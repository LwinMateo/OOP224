/*
Name: Lwin Yonal Mateo Lopez
Email: lymateo-lopez@myseneca.ca
Student ID: 134710201
Date: 03-24-2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_RECTANGLE_H
#define SDDS_RECTANGLE_H

#include "LblShape.h"

namespace sdds
{
	class Rectangle : public LblShape
	{
		int m_width;
		int m_height;
	public:
		Rectangle();
		Rectangle(const char* Cstring, int width, int height);
		void draw(std::ostream& out) const override;
		void getSpecs(std::istream& input) override;
	};
}
#endif // !SDDS_RECTANGLE_H



