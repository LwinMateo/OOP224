/*
Name: Lwin Yonal Mateo Lopez
Email: lymateo-lopez@myseneca.ca
Student ID: 134710201
Date: 03-24-2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_SHAPE_H
#define SDDS_SHAPE_H

namespace sdds
{
	class Shape
	{
	public:
		virtual void draw(std::ostream& out) const = 0;
		virtual void getSpecs(std::istream& input) = 0;

		virtual ~Shape() {};
	};


	std::istream& operator>>(std::istream& is, Shape& shape);

	std::ostream& operator<<(std::ostream& os, const Shape& shape);
}

#endif


