#include "pch.h"
#include "StringLoader.h"


StringLoader::StringLoader()
{
}


StringLoader::~StringLoader()
{
}

//	Loads the input strings from a file.
int StringLoader::loadStrings(string path)
{
	string str;
	ifstream file;
	numStrings = 0;

	file.open(path);
	
	while (!file.eof())
	{
		getline(file, str);
		strArray[numStrings] = enumeration(str);
		numStrings++;
	}

	return numStrings;
}

//	Gets a string from the array
string StringLoader::getStrings(int index)
{
	return strArray[index];
}

void StringLoader::printStrings()
{
	for (int x = 0; x < numStrings; x++)
	{
		string str = strArray[x];
		cout << x << ". " << str << "\n";
	}
}

// Gets a string and decodes the decodes it
string StringLoader::enumeration(string word)
{
	string decoderWord;
	// a^20

	for (int i = 0; i < word.size(); i++)
	{
		if (i == word.size() - 2) decoderWord.append(1u, word[i]);
		else if (word[i + 1] == '^')
		{
			int num = 0;

			if (i < word.size() - 3) // check for 1 or 2 numbers
			{
				int b = word[i+2] - '0';
				int d = word[i+3] - '0';

				if (b > 0 && b <= 9)
				{
					if (d >= 0 && d <= 9) num = (b * 10) + d;
					else num = b;
				}
			}
			else if (i < word.size() - 2) // check for only 1 number
			{
				int b = word[i + 2] - '0';
				
				if (b > 0 && b <= 9) num = b;
			}

			// insert the amount of letters
			for (int l = 0; l < num; l++) decoderWord.append(1u, word[i]);

			if (num > 9) i += 3;
			else if (num > 0 && num <= 9) i += 2;
			else i++;
		}
		else decoderWord.append(1u, word[i]);
	}
	return decoderWord;
}