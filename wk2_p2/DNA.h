/*
Name: Lwin Yonal Mateo Lopez
Email: lymateo-lopez@myseneca.ca
Student ID: 134710201
Date: 01-31-2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/


#ifndef SDDS_DNA_H_
#define SDDS_DNA_H_

namespace sdds
{
	struct DNA
	{
		int DNA_ID;
		char *DNA_Strands{};
	};

	bool beginSearch(const char* filename);

	bool read(const char* subDNA);

	void sort();

	void displayMatches();

	void deallocate();

	void endSearch();
}


#endif // !