#pragma once
#include "Parser.h"

using namespace std;

#define null '\0'
#define NUMNONTERM 26
#define MAXSIZE 100

class TopDown : public Parser
{
public:
	TopDown(Grammar * grammar) : Parser(grammar) { fillTable(); }
	bool parse(string word);

private:
	char * wordTopDown;
	bool parse(char A, int i, int j);
	void fillTable();
	int table[NUMNONTERM][MAXSIZE][MAXSIZE];
};

