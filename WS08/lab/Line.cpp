/*
Name: Lwin Yonal Mateo Lopez
Email: lymateo-lopez@myseneca.ca
Student ID: 134710201
Date: 03-24-2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <cstring>
#include <iomanip>
#include "Line.h"
#include "Shape.h"
#include "LblShape.h"

using namespace std;

namespace sdds
{
	Line::Line() : LblShape()
	{
		m_length = 0;
	}

	

	Line::Line(const char* Cstring, int length) : LblShape(Cstring) {
		m_length = length;
	}	


	void Line::getSpecs(istream& input)
	{
		
		LblShape::getSpecs(input);

		input >> this->m_length;

		input.ignore(1000, '\n');
		
	}

	void Line::draw(std::ostream& out) const
	{
		if (m_length > 0 && label() != nullptr) {
			
			out << label() << endl;
			out.width(m_length);
			out.fill('=');
			out << "=";
			out.fill(' ');

		}
		
	}


	
}