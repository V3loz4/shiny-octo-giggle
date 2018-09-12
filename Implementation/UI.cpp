#include "pch.h"
#include "UI.h"

UI::UI()
{
}


UI::~UI()
{
}

//	Prompts the user to say which algorithm to use and runs it
void UI::parserMenu(int numStr)
{
	system("cls");
	cout << "Choose the parser: \n" << 
		"1.Naive.\n" << 
		"2.Bottom-Up.\n" << 
		"3.Top-Down.\n" << 
		"0.Exit\n" <<
		"Insert Option: ";
	int choice;
	cin >> choice;
	
	if (choice == 1) parser = new Naive(grammar);
	else if (choice == 2) parser = new BottomUp(grammar);
	else if (choice == 3) parser = new TopDown(grammar);
	else return;

	cout << "length, time, no.operations, result\n\n";

	for (int x = 0; x < numStr; x++)
	{
		high_resolution_clock::time_point start = high_resolution_clock::now();	//	Starting point in time
		bool result = parser->parse(strLoad->getStrings(x));					//	Parse of one of the input strings
		high_resolution_clock::time_point end = high_resolution_clock::now();	//	Finishing point in time

		duration<double> elapsedTime = (end - start) * 1000;					//	Calculation of the time elapsed in ms

		cout << strLoad->getStrings(x).size() <<
			"," << elapsedTime.count() <<
			"," << parser->operations <<
			"," << result << "\n";

		parser->operations = 0; //reset operations value
	}

	delete(parser);
}

//	Prompts the user for the grammar file
void UI::loadGrammarMenu()
{
	string path;
	system("cls");
	cout << "Load Grammar\n" << 
		"File path: ";
	
	cin >> path;
	grammar = new Grammar(path);

	cout << "\nRules that were loaded:\n";
	grammar->printRules();

	Sleep(3000);

	testWordMenu();
}

//	Prompts the user for the input strings file
void UI::testWordMenu()
{
	strLoad = new StringLoader();
	string path;
	system("cls");
	cout << "Load Strings\n" <<
		"File path: ";

	cin >> path;
	int numStr = strLoad->loadStrings(path);

	cout << "\nInput strings that were loaded:\n";
	strLoad->printStrings();

	Sleep(3000);

	parserMenu(numStr);
	delete(strLoad);
}


