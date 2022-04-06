/*
Name: Lwin Yonal Mateo Lopez
Email: lymateo-lopez@myseneca.ca
Student ID: 134710201
Date: 03-14-2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include"Menu.h"
#include "AidMan.h"
#include"Utils.h"
#include"Date.h"

using namespace std;

namespace sdds
{
	unsigned int AidMan::menu() {
		Date date(0, 0, 0);

		unsigned int insertOption;

		cout << "Aid Management System Version 0.1" << endl;
		cout << "Date: " << date << endl;
		if (FileName == nullptr) {
			cout << "Data file: No file" << endl;
		}
		else {
			cout << "Data file: " << FileName << endl;
		}
		cout << "---------------------------------" << endl;

		insertOption = AidMan().theMenu.run();

		return insertOption;
	}

	AidMan::AidMan() : theMenu(7, "1- List Items\n2- Add Item\n3- Remove Item\n4- Update Quantity\n5- Sort\n6- Ship Items\n7- New/Open Aid Database\n---------------------------------\n") { // INITIALIZATION LIST
		FileName = nullptr;
	}


	//Rule of three (----------NOT IMPLEMENTED------------)
	//AidMan(const AidMan& aid) = delete;
	//AidMan& operator=(const AidMan aid) = delete;



	AidMan::~AidMan() {
		delete[] FileName;
	}

	void AidMan::run() {
		unsigned int num = 0;
		
		do {
			num = menu();
			if (num == 1) {
				cout << "\n****List Items****\n\n";
			}
			else if (num == 2) {
				cout << "\n****Add Item****\n\n";
			}
			else if (num == 3) {
				cout << "\n****Remove Item****\n\n";
			}
			else if (num == 4) {
				cout << "\n****Update Quantity****\n\n";
			}
			else if (num == 5) {
				cout << "\n****Sort****\n\n";
			}
			else if (num == 6) {
				cout << "\n****Ship Items****\n\n";
			}
			else if (num == 7) {
				cout << "\n****New/Open Aid Database****\n\n";
			}
			else if (num == 0) {
				cout << "Exiting Program!";
			}
		} while (num != 0);

	}
}