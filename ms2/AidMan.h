/*
Name: Lwin Yonal Mateo Lopez
Email: lymateo-lopez@myseneca.ca
Student ID: 134710201
Date: 03-14-2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef AIDMAN_H
#define AIDMAN_H
#include "Menu.h"

namespace sdds
{
	class AidMan
	{
		char* FileName{};
		Menu theMenu;

	public:
		unsigned int menu();

		AidMan();

		//Rule of three
		AidMan(const AidMan& aid) = delete;
		AidMan& operator=(const AidMan aid) = delete;
		~AidMan();

		void run();

	};
}

#endif // !AIDMAN_H
