#pragma once
#include "pch.h"
#include "Parser.h"

using namespace std;

#define null '\0'

class Naive2 : public Parser
{
public:
	Naive2(Grammar * grammar) : Parser(grammar) {}
	bool parse(string word);

private:
	char * wordNaive2;
	bool parse(char A, int i, int j);
};