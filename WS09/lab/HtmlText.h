/*
Name: Lwin Yonal Mateo Lopez
Email: lymateo-lopez@myseneca.ca
Student ID: 134710201
Date: 03-30-2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_HTMLTEXT_H
#define SDDS_HTMLTEXT_H

#include "Text.h"

namespace sdds
{
	class HtmlText : public Text
	{
		char* m_title{};
	public:

		HtmlText();

		HtmlText(const char* title);

		//Rule of Three
		HtmlText(const HtmlText&);
		HtmlText& operator=(const HtmlText&);
		~HtmlText();

		std::ostream& write(std::ostream& out) const override;
	};
}

#endif // !SDDS_HTMLTEXT_H
