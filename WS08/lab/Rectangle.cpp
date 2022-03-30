/*
Name: Lwin Yonal Mateo Lopez
Email: lymateo-lopez@myseneca.ca
Student ID: 134710201
Date: 03-24-2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Shape.h"
#include "Rectangle.h"
#include "Line.h"

using namespace std;

namespace sdds
{
	Rectangle::Rectangle() : LblShape()
	{
		m_width = 0;
		m_height = 0;
	}

	Rectangle::Rectangle(const char* Cstring, int width, int height) : LblShape(Cstring)
	{
		int theLength = strlen(label()) + 2;

		if (height < 3 || width < theLength) {
			m_width = 0;
			m_height = 0;
		}
		else {
			m_width = width;
			m_height = height;
		}


	}

	

	void Rectangle::getSpecs(istream& input)
	{
		LblShape::getSpecs(input);

		input >> m_width;

		char symbol;

		input >> symbol;

		input >> m_height;

		input.ignore(1000, '\n');

	}


	void Rectangle::draw(ostream& out) const
	{
		int theLength = strlen(label()) + 2;

		if (m_height > 3 && m_width > theLength) {
			out << "+";
			out.width(m_width - 2);
			out.fill('-');
			out << "-";
			out.fill(' ');
			out << "+" << endl;


			out << "|";
			out << setw(m_width - 2) << left << label();
			out << "|" << endl;



			for (auto k = 0; k < m_height - 3; k++) {
				out << "| ";
				out.width(m_width - 2);
				out.setf(ios::right);
				out << "|" << endl;
				out.unsetf(ios::right);
			}


			out << "+";
			out.width(m_width - 2);
			out.fill('-');
			out << "-";
			out.fill(' ');
			out << "+";

		}

		
	}
}


