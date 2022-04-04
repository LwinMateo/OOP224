/*
Name: Lwin Yonal Mateo Lopez
Email: lymateo-lopez@myseneca.ca
Student ID: 134710201
Date: 03-30-2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<cstring>
#include "Text.h"

using namespace std;

namespace sdds
{
	const char& Text::operator[](int index) const
	{
		return this->m_content[index];
	}

	Text::Text()
	{
		this->m_content = nullptr;
	}

	Text::Text(const Text& other)
	{
		this->m_content = nullptr;

		*this = other;
	}

	Text& Text::operator=(const Text& other)
	{
		if (this != &other) {
			if (other.m_content != nullptr) {
				delete[] this->m_content;
				m_content = nullptr;

				m_content = new char[strlen(other.m_content) + 1];
				strcpy(m_content, other.m_content);
			}
		}

		return *this;
	}

	Text::~Text()
	{
		delete[] this->m_content;
	}


	int Text::getFileLength(istream& is)
	{
		int len{};
		if (is) {
			// save the current read position
			std::streampos cur = is.tellg();
			// go to the end
			is.seekg(0, ios::end);
			// let what is the positions (end position = size)
			len = is.tellg();
			// now go back to where you were.
			is.seekg(cur);
		}
		return len;
	}


	istream& Text::read(istream& in)
	{
		// TODO: insert return statement here
		delete[] this->m_content;

		int getLength = getFileLength(in);

		m_content = new char[getLength + 1]{};

		for (auto i = 0; i < getLength; i++) {
			//in >> this->m_content[i];

			in.get(this->m_content[i]);
		}

		if (getLength > 0) {
			in.clear();
		}

		return in;

	}

	ostream& Text::write(ostream& out) const{
		if (this->m_content != nullptr) {
			out << this->m_content;
		}
		return out;
	} 
	




	istream& operator>>(istream& is, Text& text)
	{
		// TODO: insert return statement here
		text.read(is);
		return is;
	}

	ostream& operator<<(ostream& os, const Text& text)
	{
		// TODO: insert return statement here
		text.write(os);
		return os;
	}

}