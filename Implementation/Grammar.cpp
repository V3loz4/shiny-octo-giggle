#include "pch.h"
#include "Grammar.h"

Grammar::Grammar(){}

Grammar::Grammar(string filePath)
{
	numLines = 0;

	ifstream file;
	file.open(filePath);

	loadGrammar(&file);

	file.close();
}

void Grammar::loadGrammar(ifstream *file)
{
	string line;

	while (!file->eof())
	{
		getline(*file, line);
		numLines++;
	}

	pair<char, pair<char, char>> *temp = new pair<char, pair<char, char>>[numLines];
	int i = 0;

	//	Reset file reading head
	file->clear();
	file->seekg(0, ios::beg);

	while (!file->eof())
	{
		getline(*file, line);
		if (line[0] != null && line[2] != null && line[3] != null) // non-terminals
		{
			pair<char, char> par = make_pair(line[2], line[3]);
			temp[i] = make_pair(line[0], par);
			i++;
		}
		else if (line[0] != null && line[2] != null && line[3] == null) // has 1 terminal
		{
			pair<char, char> par = make_pair(line[2], null);
			temp[i] = make_pair(line[0], par);
			i++;
		}
		else
		{
			//numLines = i;	//	Make sure that the value is correct bcs might have found a wild \n at EOF
			break;
		}
	}
	pairLoad = temp;
}

void Grammar::printRules()
{
	for (int i = 0; i < numLines; i++)
	{
		char a = pairLoad[i].second.second;
		if (a == null)
		{
			std::cout << pairLoad[i].first << " -> " << pairLoad[i].second.first << '\n';
		}
		else
		{
			std::cout << pairLoad[i].first << " -> " << pairLoad[i].second.first <<
				pairLoad[i].second.second << '\n';
		}
	}
}

int Grammar::getRules(char a, pair<char, char> * parArray)
{
	pair<char, char> rules[100];
	int i = 0;
	int c = 0;

	while (i < numLines)
	{
		if (pairLoad[i].first == a)
		{
			rules[c] = pairLoad[i].second;
			c++;
		}
		i++;
	}

	for (i = 0; i < 100; i++) parArray[i] = rules[i];

	return c;
}

void Grammar::getNonTerminal(char A, char B, char * arr)
{
	char nonTerminal[26];
	for (int x = 0; x < 26; x++) nonTerminal[x] = '\0';
	int i = 0;
	int c = 0;

	while (i < numLines)
	{
		if (pairLoad[i].second.first == A && pairLoad[i].second.second == B)
		{
			nonTerminal[c] = pairLoad[i].first;
			c++;
		}
		i++;
	}
	for (i = 0; i < 26; i++)
	{
		arr[i] = nonTerminal[i];
	}
}

void Grammar::getNonTerminal(char A, char * arr)
{
	int i = 0;
	int	c = 0;
	char nonTerminal[26];
	for (int x = 0; x < 26; x++) nonTerminal[x] = '\0';

	while (i < numLines)
	{

		if (pairLoad[i].second.first == A && pairLoad[i].second.second == null)
		{
			nonTerminal[c] = pairLoad[i].first;
			c++;
		}
		i++;
	}
	for (i = 0; i < 26; i++)
	{
		arr[i] = nonTerminal[i];
	}
}