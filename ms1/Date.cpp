/*
Name: Lwin Yonal Mateo Lopez
Email: lymateo-lopez@myseneca.ca
Student ID: 134710201
Date: 03-13-2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <cctype>
#include<cstring>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<cstdlib>
#include "Date.h"
#include "Utils.h"

using namespace std;

namespace sdds
{
	// Private Methods
	bool Date::validate() {
		bool validDate = false;

		State.clear();

		if (Year < 2022 || Year > MAX_YEAR_VALUE) {
			State = "Invalid year in date";
			State = 1;
		}
		else if (Month < 1 || Month > 12) {
			State = "Invalid month in date";
			State = 2;
		}
		else if (Day < 1 || Day > ut.daysOfMon(Month, Year)) {
			State = "Invalid day in date";
			State = 3;
		}
		else {
			
			validDate = true;
		}

		return validDate;

	}


	int Date::unique_date_value() const{
		int theValue = Year * 372 + Month * 31 + Day;

		return theValue;
	}

	Date::Date(int year, int month, int day) {
		if (year == 0 && month == 0 && day == 0) {
			ut.getSystemDate(&Year, &Month, &Day);
		}
		else {
			this->Year = year;
			this->Month = month;
			this->Day = day;
			this->validate();
		}
	}


	// OPERATOR OVERLOADS FOR COMPARISON
	bool Date::operator==(const Date& x) const{
		return this->unique_date_value() == x.unique_date_value();
	}

	bool Date::operator!=(const Date& x) const{
		return this->unique_date_value() != x.unique_date_value();
	}

	bool Date::operator<(const Date& x) const{
		return this->unique_date_value() < x.unique_date_value();
	}

	bool Date::operator>(const Date& x) const{
		return this->unique_date_value() > x.unique_date_value();
	}

	bool Date::operator<=(const Date& x) const{
		return this->unique_date_value() <= x.unique_date_value();
	}

	bool Date::operator>=(const Date& x) const{
		return this->unique_date_value() >= x.unique_date_value();
	}

	


	const Status& Date::state() const {
		return State;
	}

	Date& Date::formatted(bool setFormat) {
		Formatted = setFormat;
		return *this;
	}

	Date::operator bool() const {
		return State;
	}

	ostream& Date::write(ostream& out) const {
		if (Formatted == true) {
			out << Year << "/";
			out.width(2);
			out.fill('0');
			out.setf(ios::right);
			out << Month << "/";
			out.width(2);
			out << Day;

			
			out.unsetf(ios::right);
			out.fill(' ');
		}
		else {
			out << Year % 100;
			out.width(2);
			out.fill('0');
			out.setf(ios::right);
			out << Month;
			out.width(2);
			out << Day;


			out.unsetf(ios::right);
			out.fill(' ');
		}


		return out;
	}


	istream& Date::read(istream& in) {

		int enterDate;
		

		in >> enterDate;

		if (in) {
			if (enterDate < 10000) {

				Year = 2022;
				Day = enterDate % 100;
				Month = enterDate / 100;

			}
			else if (enterDate < 1000000) {
				Day = enterDate % 100;
				enterDate /= 100;


				Month = enterDate % 100;
				Year = enterDate / 100;
				Year += 2000;
			}


			if (this->validate() == false) {
				in.setstate(ios::badbit);
			}
		}
		else {
			State = "Invalid date value";
		}
		

		return in;

	}




	istream& operator>>(istream& is, Date& date) {
		date.read(is);
		return is;
	}

	ostream& operator<<(ostream& os, const Date& date) {
		return date.write(os);
	}
}