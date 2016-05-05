#pragma once
#include <string>
class FleschAnalyzer
{
public:
	int numOfSent = 0;
	FleschAnalyzer(std::string path);
	~FleschAnalyzer();
private:
	std::string punctuations = "!?.:;";
	void CountSentences(std::string line);
	bool IsPunctuation(char a);
};

