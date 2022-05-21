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
#include "iProduct.h"

const int sdds_max_num_items = 100;

namespace sdds
{

	class AidMan
	{
		char* m_filename{};
		Menu theMenu;

		//additional attributes
		iProduct* m_products[sdds_max_num_items]{};
		int number_of_iProduct_Items = 0;

		//additional methods
		void save();
		void deallocate();
		void load();

		//additional methods for Menu Item 1
		int list(const char* sub_desc = nullptr);


		int search(int sku) const;


		void remove(int index);


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
