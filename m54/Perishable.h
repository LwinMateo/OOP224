/*
Name: Lwin Yonal Mateo Lopez
Email: lymateo-lopez@myseneca.ca
Student ID: 134710201
Date: 03-31-2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_PERISHABLE_H
#define SDDS_PERISHABLE_H
#include"Date.h"
#include"Item.h"

namespace sdds
{
	class Perishable : public Item
	{
		Date m_expiry;
		char* Instructions{};
	public:
		Perishable();

		//Rule of Three
		Perishable(const Perishable&);
		Perishable& operator=(const Perishable&);
		~Perishable();

		const Date& expiry() const;




		// to read the Stock-Keeping Unit from console before
		// main data entry
		int readSku(std::istream& istr) override;

		// saves the iProduct into a file
		std::ofstream& save(std::ofstream& ofstr) const override;

		// loads an iProduct from a file
		std::ifstream& load(std::ifstream& ifstr) override;

		// displays the iProduct on the screen
		std::ostream& display(std::ostream& ostr) const override;

		// reads the iProduct from the console
		std::istream& read(std::istream& istr) override;
	};

}

#endif // !SDDS_PERISHABLE_H
