// Flesch-Reading-Ease-test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "FleschAnalyzer.h"
#include <iostream>
using namespace std;

int main()
{
	FleschAnalyzer fa = FleschAnalyzer("test.txt");
	cout << fa.GetTheresult() << endl;
    return 0;
}

