#include "pch.h"
#include "Parser.h"

Parser::Parser(Grammar * grm)
{
	grammar = grm;
	operations = 0;
}