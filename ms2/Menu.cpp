/*
Name: Lwin Yonal Mateo Lopez
Email: lymateo-lopez@myseneca.ca
Student ID: 134710201
Date: 03-14-2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Menu.h"
#include "Utils.h"

using namespace std;

namespace sdds
{
	Menu::Menu(unsigned int options, const char* theMenuContent) {
		if (options > 15 || theMenuContent == nullptr) {
			//delete[] List_Of_Option;
			List_Of_Option = nullptr;
			Available_Options = 0;
		}
		else {
			List_Of_Option = new char[strlen(theMenuContent) + 1];

			strcpy(List_Of_Option, theMenuContent);
			Available_Options = options;
		}
	}

	// Rule of 3
	// Member function copying and assigning NOT IMPLEMENTED
	
	Menu::~Menu() {
		delete[] List_Of_Option;
	}

	unsigned int Menu::run() {

		unsigned int promptInt = 0;
		bool Valid = false;


		cout << List_Of_Option;
		cout << "0- Exit" << endl;
		cout << "> ";


		while (Valid == false) {
			cin >> promptInt;
			if (cin.fail() == true) {
				cout << "Invalid Integer, retry: ";
				cin.clear();
				cin.ignore(1000, '\n');
			}
			else if (promptInt > Available_Options || promptInt < 0) {
				cout << "Value out of range [0<=val<=" << Available_Options << "]: ";
			}
			else {
				Valid = true;
			}
		}

		return promptInt;
		
	}
}