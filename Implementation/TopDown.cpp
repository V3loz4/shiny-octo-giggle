#include "pch.h"
#include "TopDown.h"

bool TopDown::parse(string word)
{
	operations++;
	int tamWord = word.size(); // word and wordTopDown have the same length
	wordTopDown = new char[tamWord];
	for (int i = 0; i < tamWord; i++)
	{
		wordTopDown[i] = word[i];
	}
	return parse('S', 0, tamWord);
}

bool TopDown::parse(char A, int i, int j)
{
	int letter = A - 'A';
	bool belongs = false;

	if (table[letter][i][j] != 2)
	{
		belongs = (bool) table[letter][i][j];
		return belongs;
	}
	else
	{
		pair<char, char> parArray[100];
		int numEntries = grammar->getRules(A, parArray);

		if (i == j - 1)
		{
			for (int a = 0;	a < numEntries;	a++)
			{
				if (wordTopDown[i] == parArray[a].first)
				{
					belongs = true;
					break;
				}
			}
		}
		else
		{
			for (int a = 0; a < numEntries;	a++)
			{
				// TODO incremental contador global
				if (parArray[a].second == null)
				{
					if (parArray[a].first == (wordTopDown[i]))
					{
						belongs = true;
						break;
					}
				}
				else
				{
					int k = i + 1;
					for (k; k < j; k++)
					{
						if (parse(parArray[a].first, i, k) && parse(parArray[a].second, k, j))
						{
							belongs = true;
							break;
						}
					}
				}
			}
		}
		// true = 1
		// false = 0
		// null = 2
		letter = A - 'A';
		table[letter][i][j] = (int)belongs;
		return belongs;
	}
}

void TopDown::fillTable()
{
	for ( int a = 0; a < NUMNONTERM; a++)
	{
		for (int b = 0; b < MAXSIZE; b++)
		{
			for (int c = 0; c < MAXSIZE; c++)
			{
				table[a][b][c] = 2;	// 2 is null
			}
		}
	}
}
