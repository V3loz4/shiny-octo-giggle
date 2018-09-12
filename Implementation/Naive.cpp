#include "pch.h"
#include "Naive.h"

bool Naive::parse(string word)
{
	int tamWord = word.size(); // word and wordNaive have the same length
	wordNaive = new char[tamWord];
	for (int i = 0; i < tamWord; i++)
	{
		wordNaive[i] = word[i];
	}
	return parse('S', 0, tamWord);
}

bool Naive::parse(char A, int i, int j)
{
	operations++;
	pair<char, char> parArray[100];
	int numEntries = grammar->getRules(A, parArray);

	if (i == j - 1)
	{
		for (int a = 0;	a < numEntries;	a++)
		{
			if (wordNaive[i] == parArray[a].first) return true;
		}
		return false;
	}

	for (int a = 0;	a < numEntries; a++)
	{
		if (parArray[a].second == null)
		{
			if (parArray[a].first == (wordNaive[i])) return true;
		}
		else
		{
			int k = i + 1;
			for (k; k < j; k++)
			{
				if (parse(parArray[a].first, i, k) && parse(parArray[a].second, k, j)) return true;
			}
		}
	}
	return false;
}