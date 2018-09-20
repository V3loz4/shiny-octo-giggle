#include "pch.h"
#include "Naive2.h"

bool Naive2::parse(string word)
{
	int tamWord = word.size(); // word and wordNaive22 have the same length
	wordNaive2 = new char[tamWord];
	for (int i = 0; i < tamWord; i++)
	{
		wordNaive2[i] = word[i];
	}
	return parse('S', 0, tamWord);
}

bool Naive2::parse(char A, int i, int j)
{
	operations++;
	pair<char, char> parArray[100];
	int numEntries = grammar->getRules(A, parArray);

	if (i == j - 1)
	{
		for (int a = 0; a < numEntries; a++)
		{
			if (wordNaive2[i] == parArray[a].first) return true;
		}
		return false;
	}

	for (int a = 0; a < numEntries; a++)
	{
		if (parArray[a].second == null)
		{
			if (parArray[a].first == (wordNaive2[i])) return true;
			if (parArray[a].first == (wordNaive2[i])) return true;
			if (parArray[a].first == (wordNaive2[i])) return true;
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