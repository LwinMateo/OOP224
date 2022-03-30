#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "HealthCard.h"
using namespace std;
namespace sdds
{

	HealthCard::HealthCard() {
		// Initialize EVERTYHING
		setEmpty();
	}

	HealthCard::HealthCard(const char* name, long long number, const char vCode[], const char sNumber[]) {
		if (validID(name, number, vCode, sNumber) == true) {
			this->allocateAndCopy(name);
			m_number = number;
			strcpy(m_vCode, vCode);
			strcpy(m_sNumber, sNumber);
		}
		else {
			setEmpty();
		}
	}

	bool HealthCard::validID(const char* name, long long number, const char vCode[], const char sNumber[]) const {
		return name != nullptr && (number > 1000000000 && number < 10000000000) && (strlen(vCode) + 1) == 3 && (strlen(sNumber) + 1) == 10;
	}


	void HealthCard::setEmpty() {
		// Set the m_name to nullptr
		m_name = nullptr;
		m_number = 0;
		m_vCode[0] = '\0';
		m_sNumber[0] = '\0';
	}

	void HealthCard::allocateAndCopy(const char* name) {
		delete[] m_name;
		m_name = new char[strlen(name) + 1];
		strcpy(m_name, name);
	}

	void HealthCard::extractChar(istream& istr, char ch) const {
		char next = istr.peek();

		//istr >> ch;


		if (next == ch) {
			istr.ignore();
		}
		else {
			istr.ignore(1000, ch);
			istr.setstate(ios::failbit);
		}
	}

	ostream& HealthCard::printIDInfo(ostream& ostr) const {
		ostr << m_number << "-" << m_vCode << ", " << m_sNumber;
		return ostr;
	}



	void HealthCard::set(const char* name, long long number, const char vCode[], const char sNumber[]) {
		if (validID(name, number, vCode, sNumber) == true) {
			this->allocateAndCopy(name);
			m_number = number;
			strcpy(m_vCode, vCode);
			strcpy(m_sNumber, sNumber);
		}
		else {
			delete[] m_name;
			setEmpty();
		}
	}

	const char* HealthCard::getName() const {
		return m_name;
	}
	long long HealthCard::getNumber() const {
		return m_number;
	}
	const char* HealthCard::getVCode() const {
		return m_vCode;
	}
	const char* HealthCard::getSNumber() const {
		return m_sNumber;
	}


	//////////////////////////////
	/// RULES OF THREE
	//////////////////////////////
	HealthCard::HealthCard(const HealthCard& hc) {
		m_name = nullptr;
		*this = hc;
	}
	HealthCard& HealthCard::operator=(const HealthCard& hc) {
		if (this != &hc) {

			delete[] m_name;

			if (validID(hc.m_name, hc.m_number, hc.m_vCode, hc.m_sNumber) == true) {

				m_name = new char[strlen(hc.m_name) + 1];

				strcpy(m_name, hc.m_name);
				m_number = hc.m_number;
				strcpy(m_vCode, hc.m_vCode);
				strcpy(m_sNumber, hc.m_sNumber);
			}
			else {
				m_name = nullptr;
			}
		}

		return *this;
	}

	HealthCard::~HealthCard() {
		delete[] m_name;
	}





	HealthCard::operator bool() const {
		return m_name != nullptr;
	}

	ostream& HealthCard::print(ostream& ostr, bool toFile) const {
		//if (validID(m_name, m_number, m_vCode, m_sNumber) == true) {
		if (*this)
		{
			if (toFile == true) {
				ostr << m_name << ", ";
				printIDInfo(ostr);
			}
			if (toFile == false) {
				ostr.fill('.');
				ostr.width(50);
				ostr << left << m_name;

				printIDInfo(ostr);
			}
		}
		return ostr;
	}




	istream& HealthCard::read(istream& istr) {
		char* localName = new char[MaxNameLength];
		long long localNumber = 0;
		char localVCode[3]{};
		char localSNumber[10]{};


		istr.get(localName, MaxNameLength, ',');

		extractChar(istr, ',');

		istr >> localNumber;

		extractChar(istr, '-');

		istr.get(localVCode, 3, ',');

		extractChar(istr, ',');

		istr.get(localSNumber, 10, '\n');

		//extractChar(istr, '\n');

		if (istr.fail() == false) {
			set(localName, localNumber, localVCode, localSNumber);
		}

		istr.clear();
		istr.ignore(1000, '\n');

		return istr;

	}








	// HELPER FUNCTIONS
	ostream& operator<<(ostream& ostr, const HealthCard& hc) {
		if (hc && (hc.getNumber() > 1000000000 && hc.getNumber() < 10000000000) && (strlen(hc.getVCode()) + 1) == 3 && (strlen(hc.getSNumber()) + 1) == 10) {
			hc.print(ostr, false);
		}
		else {
			ostr << "Invalid Card Number Record";
		}

		return ostr;
	}

	istream& operator>>(istream& istr, HealthCard& hc) {
		return hc.read(istr);
	}

}
