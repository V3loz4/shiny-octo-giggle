#pragma once
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

#define MAX 100

class StringLoader
{
	public:
		StringLoader();
		~StringLoader();
		int loadStrings(string path);
		string getStrings(int index);
		void printStrings();
	private:
		string strArray[MAX];
		int numStrings;
};

