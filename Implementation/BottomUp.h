#pragma once
#include "pch.h"
#include "Parser.h"

#define MAXSIZE 100
#define NUMNONTERM 26

class BottomUp : public Parser
{
public:
	BottomUp(Grammar * grammar) : Parser(grammar) { fillTable(); }
	bool parse(string word);
private:
	void fillTable();
	bool table[NUMNONTERM][MAXSIZE][MAXSIZE];
	void nullifyArray(char * arr, int size);
};