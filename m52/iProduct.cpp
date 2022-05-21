/*
Name: Lwin Yonal Mateo Lopez
Email: lymateo-lopez@myseneca.ca
Student ID: 134710201
Date: 03-24-2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include "iProduct.h"

using namespace std;

namespace sdds
{

	istream& operator>>(istream& is, iProduct& iproduct) {
		iproduct.read(is);
		return is;
	}

	ostream& operator<<(ostream& os, const iProduct& iproduct) {
		iproduct.display(os);
		return os;
	}

}