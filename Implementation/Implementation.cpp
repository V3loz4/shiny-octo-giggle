// Implementation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <windows.h>
#include "Naive.h"
#include "BottomUp.h"

using namespace std;

int main()
{
	Grammar*grammar = new Grammar("D:\\Documentos\\Efficient Algorithms\\laughing-adventure\\cnfGrammar.txt");

	string word = "abab";

	cout << "The rules that were loaded:\n";
	grammar->printRules();

	Naive*naive = new Naive(grammar);
	BottomUp*bottomUp = new BottomUp(grammar);
	//Naive*naive = new Naive(grammar);

	cout << "Naive: ";
	if (naive->parse(word)) cout << "The word belongs to the language\n";
	else cout << "The word does not belong to the language\n";

	cout << "Bottom-Up: ";
	if (bottomUp->parse(word)) cout << "The word belongs to the language\n";
	else cout << "The word does not belong to the language\n";

	delete(grammar);
	delete(naive);
	delete(bottomUp);
	Sleep(10000);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
