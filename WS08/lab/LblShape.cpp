/*
Name: Lwin Yonal Mateo Lopez
Email: lymateo-lopez@myseneca.ca
Student ID: 134710201
Date: 03-24-2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<string>
#include "Shape.h"
#include "LblShape.h"

using namespace std;

namespace sdds
{
	const char* LblShape::label() const
	{
		return m_label;
	}

	LblShape::LblShape()
	{
		m_label = nullptr;
	}

	LblShape::LblShape(const char* incoming)
	{
		m_label = new char[strlen(incoming) + 1];
		strcpy(m_label, incoming);
	}

	LblShape::~LblShape()
	{
		delete[] m_label;
	}

	void LblShape::getSpecs(istream& input)
	{
		std::string theString;

		std::getline(input, theString, ',');


		delete[] m_label;
		
		this->m_label = new char[theString.length() + 1];

		strcpy(m_label, theString.c_str());

	}
}
