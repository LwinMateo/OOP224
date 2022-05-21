/*
Name: Lwin Yonal Mateo Lopez
Email: lymateo-lopez@myseneca.ca
Student ID: 134710201
Date: 03-14-2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef DATE_H
#define DATE_H

#include <iostream>
#include "Status.h"
#include "Utils.h"

namespace sdds
{
	const int MAX_YEAR_VALUE = 2030;

	class Date
	{

	private:
		int Year = 0;
		int Month = 0;
		int Day = 0;
		Status State;
		bool Formatted = true;
	public:
		// Private Methods
		bool validate();
		int unique_date_value() const;

		Date(int year = 0, int month = 0, int day = 0);

		bool operator==(const Date& x) const;
		bool operator!=(const Date& x) const;
		bool operator<(const Date& x) const;
		bool operator>(const Date& x) const;
		bool operator<=(const Date& x) const;
		bool operator>=(const Date& x) const;

		const Status& state() const;

		Date& formatted(bool setFormat);

		operator bool() const;

		std::ostream& write(std::ostream& out) const;
		std::istream& read(std::istream& in);

	};

	std::istream& operator>>(std::istream& is, Date& date);

	std::ostream& operator<<(std::ostream& os, const Date& date);
}


#endif // !DATE_H
