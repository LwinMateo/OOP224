/*
Name: Lwin Yonal Mateo Lopez
Email: lymateo-lopez@myseneca.ca
Student ID: 134710201
Date: 01-31-2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<cstdio>
#include "cStrTools.h"
#include "DNA.h"

using namespace std;

namespace sdds
{
	// using a pointer file for opening DNA csv files to count records
	FILE* ptr;

	// I create a struct pointer array statically
	DNA *dna = nullptr;

	
	// I use this variable to count records I found that match to some characters I insert
	int numberOfRecordsMatched;


	bool beginSearch(const char* filename) {
		

		// this boolean will return true saying that the file is not empty and it will let the user see, extract, or write file
		bool fileOpen = false;

		ptr = fopen(filename, "r");

		
		if (ptr != NULL) {
			// if the file is not empty the file will open and the filOpen variable returns true
			cout << "DNA search program" << endl;
			fileOpen = true;
		}

		return fileOpen;

	}

	bool read(const char* subDNA) {

		bool matchFound = false;

		
		numberOfRecordsMatched = 0;

		
		int tempID = 0;
		char tempStrand[10001]{};

		while (fscanf(ptr, "%d,%s\n", &tempID, tempStrand) == 2) {
			if (strstr(tempStrand, subDNA) != nullptr) {
				numberOfRecordsMatched++;
			}
		}
		rewind(ptr);

		// check if the # is > 0
		if (numberOfRecordsMatched > 0)
		{
			dna = new DNA[numberOfRecordsMatched];

			int index = 0;
			while (fscanf(ptr, "%d,%s\n", &tempID, tempStrand) == 2) {
				if (strStr(tempStrand, subDNA) != nullptr) {
					dna[index].DNA_ID = tempID; // dna[index].DNA_ID is set to the data extracted from file when a match is found
					dna[index].DNA_Strands = new char[strLen(tempStrand) + 1]; // set the length of tempStrand + null to the dna[index].DNA_Strands added with old array.
					strCpy(dna[index].DNA_Strands, tempStrand);// copy the tempStrand where the data is extracted to the struct array
					++index;
				}
				
			}

			matchFound = true;
			rewind(ptr);
		}


		return matchFound;
	}


	void sort() {
		int i, j;
		DNA temp;

		for (i = numberOfRecordsMatched - 1; i > 0; i--) {
			for (j = 0; j < i; j++) {
				if (dna[j].DNA_ID > dna[j+1].DNA_ID) { 
					temp = dna[j];
					dna[j] = dna[j+1];
					dna[j+1] = temp;
				}
			}
		}
	}


	void displayMatches() {

		cout << numberOfRecordsMatched << " matches found:" << endl;

		for (auto i = 0; i < numberOfRecordsMatched; i++) {
			cout << i + 1 <<") "<< dna[i].DNA_ID << ":" << endl;
			cout << dna[i].DNA_Strands << endl;
			cout << "======================================================================" << endl;
		}
	}

	void deallocate() {
		for (auto i = 0; i < numberOfRecordsMatched; i++) {
			delete[] dna[i].DNA_Strands;
			dna[i].DNA_Strands = nullptr;
		}
	}

	void endSearch() {
		cout << "DNA Search Program Closed." << endl;
		fclose(ptr);

		delete[] dna;
		dna = nullptr;
	}
}


