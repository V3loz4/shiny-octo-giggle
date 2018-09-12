#pragma once

#include <String>
#include <iostream>
#include "Naive.h"
#include "BottomUp.h"
#include "TopDown.h"
#include "StringLoader.h"
#include <Windows.h>
#include <chrono>

using namespace std;
using namespace chrono;

class UI
{
	public:
		UI();
		~UI();
		void loadGrammarMenu();

	private:
		void parserMenu(int numStr);
		void testWordMenu();
		StringLoader*strLoad;
		Grammar*grammar;
		Parser*parser;
};

