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
		strArray[numStrings] = str;
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