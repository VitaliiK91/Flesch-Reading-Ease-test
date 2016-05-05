#include "stdafx.h"
#include "FleschAnalyzer.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

FleschAnalyzer::FleschAnalyzer(string path)
{
	string line;
	ifstream file(path);
	if (file.is_open())
	{
		while (getline(file, line))
		{
			CountSentences(line);
		}
		file.close();
	}
}

FleschAnalyzer::~FleschAnalyzer()
{
}

void FleschAnalyzer::CountSentences(std::string line)
{
	int i;
	for (i = 0; i < line.length(); i++)
	{
		if (IsPunctuation(line[i]))
		{
			numOfSent++;
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



