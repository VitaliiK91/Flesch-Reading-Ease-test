#pragma once
#include <string>
class FleschAnalyzer
{
public:
	FleschAnalyzer(std::string path);
	~FleschAnalyzer();
	double GetTheresult();
	int numOfSent = 0;
	int numOfWords = 0;
	int numOfSyl = 0;
private:
	std::string punctuations = "!?.:;";
	std::string vowels = "aeiouyAEIOUY";
	void CountParameters(std::string line);
	bool IsPunctuation(char a);
	bool IsVowel(char a);
	void AnalyzeFile();
	std::string filePath;
};

