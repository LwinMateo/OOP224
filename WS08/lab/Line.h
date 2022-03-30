/*
Name: Lwin Yonal Mateo Lopez
Email: lymateo-lopez@myseneca.ca
Student ID: 134710201
Date: 03-24-2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_LINE_H
#define SDDS_LINE_H

#include "LblShape.h"

namespace sdds
{
	class Line : public LblShape
	{
		int m_length = 0;
	public:
		Line();
		Line(const char* Cstring, int length);

		

		void draw(std::ostream& out) const override;
		void getSpecs(std::istream& input) override;

	};
}

#endif // !SDDS_LINE_H



