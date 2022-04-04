/*
Name: Lwin Yonal Mateo Lopez
Email: lymateo-lopez@myseneca.ca
Student ID: 134710201
Date: 03-30-2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<cctype>
#include<iomanip>
#include "Text.h"
#include "HtmlText.h"

using namespace std;

namespace sdds
{
	HtmlText::HtmlText() : Text()
	{
		this->m_title = nullptr;
	}

	HtmlText::HtmlText(const char* title)
	{
		if (title != nullptr) {
			this->m_title = new char[strlen(title) + 1];
			strcpy(this->m_title, title);
		}
		else {
			m_title = nullptr;
		}
	}
	HtmlText::HtmlText(const HtmlText& other)
	{
		this->m_title = nullptr;

		*this = other;
	}
	HtmlText& HtmlText::operator=(const HtmlText& other)
	{
		// TODO: insert return statement here
		if (this != &other) {
			delete[] this->m_title;
			m_title = nullptr;

			(Text&)*this = other;

			this->m_title = new char[strlen(other.m_title) + 1];
			strcpy(this->m_title, other.m_title);
		}

		return *this;
	}

	HtmlText::~HtmlText()
	{
		delete[] m_title;
	}

	ostream& HtmlText::write(ostream& out) const 
	{
		// TODO: insert return statement here
		bool MS = false;



		out << "<html><head><title>";



		if (m_title != nullptr) {
			out << m_title;
		}
		else {
			out << "No Title";
		}

		out << "</title></head>\n<body>\n";

		if (m_title != nullptr) {
			out << "<h1>" << m_title << "</h1>\n";
		}


		const HtmlText& current = *this;


		for (auto i = 0; current[i] != '\0'; i++) {
			if (current[i] == ' ') {
				if (MS == true) {
					out << "&nbsp;";
				}
				else {
					MS = true;
					out << " ";
				}
			}
			else if (current[i] == '<') {
				out << "&lt;";
				MS = false;
			}
			else if (current[i] == '>') {
				out << "&gt;";
				MS = false;
			}
			else if (current[i] == '\n') {
				out << "<br />\n";
				MS = false;
			}
			else {
				MS = false;
				out << current[i];
			}
		}

		out << "</body>\n</html>";

		return out;

	}
}

