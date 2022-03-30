/*
Name: Lwin Yonal Mateo Lopez
Email: lymateo-lopez@myseneca.ca
Student ID: 134710201
Date: 03-24-2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_LBLSHAPE_H
#define SDDS_LBLSHAPE_H

#include "Shape.h"

namespace sdds
{
	class LblShape : public Shape
	{
		char* m_label = nullptr;
	protected:
		const char* label() const;
	public:
		LblShape();
		LblShape(const char* incoming);
		~LblShape();

		LblShape(const LblShape&) = delete;
		LblShape& operator=(const LblShape&) = delete;

		void getSpecs(std::istream& input) override;
	};
}

#endif // !SDDS_LBLSHAPE_H



