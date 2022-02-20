/*
Name: Lwin Yonal Mateo Lopez
Email: lymateo-lopez@myseneca.ca
Student ID: 134710201
Date: 01-22-2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "Phone.h"
#include "cStrTools.h"
#include<fstream>
#include<cstdio>

using namespace std;


namespace sdds
{
	// runs the phone directory appication
	void phoneDir(const char* programTitle, const char* fileName) {
		
		char nameToSearch[51] = {}; // it is where the user inserts a name to search
		int numberOfPeople = 0; 


		Person person[50]{};

		FILE* fptr = fopen(fileName, "r");

		if (fptr != NULL) {

			int i = 0; // for a while loop for extracting data
			while (fscanf(fptr, "%[^\t]\t%s\t%s\t%s\n", person[i].name, person[i].areaCode, person[i].prefix, person[i].number) == 4) {
				i += 1;
			}
			numberOfPeople = i;


			cout << programTitle << " phone direcotry search" << endl;
			cout << "------------------------------------------------------" << endl;

			do {
				cout << "Enter a partial name to search (no spaces) or enter '!' to exit"<<endl;
				cout << "> ";
				cin >> nameToSearch;

				char lowerCaseNameToSearch[51] = {};
				toLowerCaseAndCopy(lowerCaseNameToSearch, nameToSearch); /* toLowerCaseAndCopy() will turn characters of nameToSearch that the user types
																		to lowercase character and they will be place in lowerCaseNameToSearch*/
				
				for (int j = 0; j < numberOfPeople; j++) {

					char lowerCasePersonName[51] = {};
					toLowerCaseAndCopy(lowerCasePersonName, person[j].name);

					if (std::strstr(lowerCasePersonName, lowerCaseNameToSearch) != nullptr)
					{
						cout << person[j].name << ": (" << person[j].areaCode << ") " << person[j].prefix << "-" << person[j].number << endl;
					}
				}
				

			} while (strCmp(nameToSearch, "!") != 0);

			cout << "Thank you for using " << programTitle << " directory." << endl;

			fclose(fptr);
		}
		else {
			cout << fileName << " file not found!" << endl;
			cout << "Thank you for using " << programTitle << " directory." << endl;
		}
	}
}
