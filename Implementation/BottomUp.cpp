#include "pch.h"
#include "BottomUp.h"

bool BottomUp::parse(string word)
{
	int tamWord = word.size();
	int i = 1; // number of the column
	int j = 1; // number of the line
	int a = 0; // counter of non terminals
	int b = 0;
	int k = 0;

	for (i = 1; i <= tamWord; i++)
	{
		char nt[NUMNONTERM];
		int x = i - 1;
		grammar->getNonTerminal(word[x], nt);

		for (a = 0; a < NUMNONTERM; a++)
		{
			if (nt[a] != null)
			{
				b = nt[a] - 'A';
				table[b][i][j] = true;
			}
			else break;
		}
	}

	for (j = 2; j <= tamWord; j++)
	{
		int max = tamWord - j + 2;
		for (i = 1; i < max; i++)
		{
			for (k = 1; k <= j - 1; k++)
			{
				int x = i + k;
				int y = j - k;
				for (a = 0; a < NUMNONTERM; a++)
				{
					if (table[a][i][k])
					{
						for (b = 0; b < NUMNONTERM; b++)
						{
							if (table[b][x][y])
							{
								char A = a + 'A';
								char B = b + 'A';

								char lhs[NUMNONTERM];

								grammar->getNonTerminal(A, B, lhs);

								for (int c = 0; c < NUMNONTERM; c++)
								{
									if (lhs[c] != null)
									{
										int d = lhs[c] - 'A';
										table[d][i][j] = true;
									}
									else break;
								}
							}
						}
					}
				}
			}
		}
	}

	int posS = 'S' - 'A'; // position of the S layer
	return table[posS][1][tamWord];
}

void BottomUp::fillTable()
{
	for (int a = 0; a < NUMNONTERM; a++)
	{
		for (int b = 0; b < MAXSIZE; b++)
		{
			for (int c = 0; c < MAXSIZE; c++)
			{
				table[a][b][c] = false;
			}
		}
	}
}

void BottomUp::nullifyArray(char * arr, int size)
{
	for (int x = 0; x < size; x++) arr[x] = null;
}