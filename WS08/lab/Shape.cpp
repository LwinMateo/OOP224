/*
Name: Lwin Yonal Mateo Lopez
Email: lymateo-lopez@myseneca.ca
Student ID: 134710201
Date: 03-24-2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "Shape.h"

using namespace std;

namespace sdds
{
	//void Shape::draw(ostream& out) const
	//{

	//}
	//void Shape::getSpecs(istream& input)
	//{
	//}
	//Shape::~Shape()
	//{
	//}
	istream& operator>>(istream& is, Shape& shape)
	{
		// TODO: insert return statement here
		shape.getSpecs(is);
		return is;
	}
	ostream& operator<<(ostream& os, const Shape& shape)
	{
		// TODO: insert return statement here
		shape.draw(os);
		return os;
	}
}


