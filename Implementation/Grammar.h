#pragma once
#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

#define null '\0'

class Grammar
{
public:
	Grammar();
	Grammar(string filePath);	// The grammar is inserted through a txt file
	void printRules();
	int getRules(char a, pair<char, char> * parArray);
	void getNonTerminal(char A, char *  arr);
	void getNonTerminal(char A, char B, char * arr);

private:
	pair<char, pair<char, char>> * pairLoad;
	void loadGrammar(ifstream *file);
	int numLines;
};