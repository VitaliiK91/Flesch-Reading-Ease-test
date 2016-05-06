#include "stdafx.h"
#include "FleschAnalyzer.h"
#include <string>
#include <iostream>
#include <fstream>

FleschAnalyzer::FleschAnalyzer(std::string path)
{
	filePath = path;
}

FleschAnalyzer::~FleschAnalyzer()
{
}

double FleschAnalyzer::GetTheresult()
{
	AnalyzeFile();
	return 206.835 - 1.015 * numOfWords / numOfSent - 84.6 * numOfSyl / numOfWords;
}

void FleschAnalyzer::CountParameters(std::string line)
{
	int i;
	for (i = 0; i < line.length(); i++)
	{
		if (IsPunctuation(line[i]))
		{
			numOfSent++;
		}
		if (i != line.length() && (line[i] == ' ' || line[i] == '—'))
		{
			numOfWords++;
		}
		if (IsVowel(line[i])
			&& (
				(i != line.length())
				&& (
					(!IsVowel(line[i + 1]))
					&&
					(line[i + 1] != ' ' && line[i + 1] != ',' && !IsPunctuation(line[i + 1] && line[i] != 'e' && line[i] != 'E'))
					)
				)
			)
		{
			numOfSyl++;
		}
	}
}

bool FleschAnalyzer::IsPunctuation(char a)
{
	int i;
	for (i = 0; i < punctuations.length(); i++)
	{
		if (a == punctuations[i])
		{
			return true;
		}
	}
	return false;
}

bool FleschAnalyzer::IsVowel(char a)
{
	int i;
	for (i = 0; i < vowels.length(); i++)
	{
		if (a == vowels[i])
		{
			return true;
		}
	}
	return false;
}

void FleschAnalyzer::AnalyzeFile()
{
	std::string line;
	std::ifstream file(filePath);
	if (file.is_open())
	{
		while (getline(file, line))
		{
			if (line.length() > 0)
			{
				numOfWords++;
				CountParameters(line);
			}
		}
		file.close();
	}
}



