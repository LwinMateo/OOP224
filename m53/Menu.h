/*
Name: Lwin Yonal Mateo Lopez
Email: lymateo-lopez@myseneca.ca
Student ID: 134710201
Date: 03-14-2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_MENU_H
#define SDDS_MENU_H

namespace sdds
{
	class Menu
	{
		char* List_Of_Option{};
		unsigned int Available_Options = 0;
	public:
		Menu(unsigned int, const char* );
		
		// Rule of 3
		Menu(const Menu& menu) = delete;
		Menu& operator=(const Menu menu) = delete;
		~Menu();

		unsigned int run();
	};
}
#endif // !MENU_H
