#pragma once
#include "pch.h"
#include "Parser.h"

using namespace std;

#define null '\0'

class Naive : public Parser
{
public:
	Naive(Grammar * grammar) : Parser(grammar) {}
	bool parse(string word);

private:
	char * wordNaive;
	bool parse(char A, int i, int j);
};