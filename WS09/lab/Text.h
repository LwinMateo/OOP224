/*
Name: Lwin Yonal Mateo Lopez
Email: lymateo-lopez@myseneca.ca
Student ID: 134710201
Date: 03-30-2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_TEXT_H
#define SDDS_TEXT_H

namespace sdds
{
	class Text
	{
		char* m_content{};
	protected:
		const char& operator[] (int index)const;
	public:
		Text();

		//Rule of Three
		Text(const Text&);
		Text& operator=(const Text&);
		~Text();

		int getFileLength(std::istream& is);

		std::istream& read(std::istream& in);
		virtual std::ostream& write(std::ostream& out) const;
	};

	std::istream& operator>>(std::istream& is, Text& text);

	std::ostream& operator<<(std::ostream& os, const Text& text);
}

#endif