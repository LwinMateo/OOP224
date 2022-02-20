/*
Name: Lwin Yonal Mateo Lopez
Email: lymateo-lopez@myseneca.ca
Student ID: 134710201
Date: 01-19-2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Word.h"
#include "Word.h"
using namespace sdds;
using namespace std;
int main() {
	char filename[256];
	programTitle();
	cout << "Enter filename: ";
	cin >> filename;
	wordStats(filename);
	return 0;
}