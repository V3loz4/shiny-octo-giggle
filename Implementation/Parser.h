#pragma once
#include "pch.h"
#include <string>
#include "Grammar.h"

class Parser
{
public:
	Parser(Grammar * grm);
	virtual bool parse(string word) = 0;
	Grammar * grammar;
	int operations;

private:

};
