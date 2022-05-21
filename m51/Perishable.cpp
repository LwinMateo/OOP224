/*
Name: Lwin Yonal Mateo Lopez
Email: lymateo-lopez@myseneca.ca
Student ID: 134710201
Date: 03-31-2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<string>
#include<cctype>
#include<cstring>
#include "Perishable.h"
#include "Item.h"
#include "Date.h"

using namespace std;

namespace sdds
{
	Perishable::Perishable()
	{
		this->Instructions = nullptr;
	}


	Perishable::Perishable(const Perishable& other)
	{
		Instructions = nullptr;

		*this = other;
	}


	Perishable& Perishable::operator=(const Perishable& other)
	{
		// TODO: insert return statement here
		if (this != &other) {
			(Item&)(*this) = other;


			delete[] this->Instructions;

			this->m_expiry = other.m_expiry;

			if (other.Instructions != nullptr) {
				this->Instructions = new char[strlen(other.Instructions) + 1];
				strcpy(this->Instructions, other.Instructions);
			}

		}

		return *this;
	}


	Perishable::~Perishable()
	{
		delete[] Instructions;
	}

	const Date& Perishable::expiry() const
	{
		// TODO: insert return statement here
		return m_expiry;
	}


	int Perishable::readSku(istream& istr)
	{
		int getSku;
		bool rightSku = false;

		cout << "SKU: ";

		do {
			istr >> getSku;
			if (!istr) {
				cout << "Invalid Integer, retry: ";
				istr.clear();
			}
			else {
				if (getSku < 10000 || getSku > 39999) {
					cout << "Value out of range [10000<=val<=39999]: ";
				}
				else {
					rightSku = true;
				}
			}
			istr.ignore(1000, '\n');
		} while (rightSku != true);

		m_sku = getSku;
		return getSku;
	}

	ofstream& Perishable::save(std::ofstream& ofstr) const
	{
		if ((bool)m_state == true) {
			Perishable P;
			P = *this;
			P.m_expiry.formatted(false);

			Item::save(ofstr);
			ofstr << "\t";
			if (P.Instructions != nullptr) {
				ofstr << P.Instructions;
			}
			ofstr << "\t";

			ofstr << P.m_expiry;

		}

		return ofstr;
	}

	ifstream& Perishable::load(std::ifstream& ifstr)
	{
		delete[] this->Instructions;
		this->Instructions = nullptr;

		Date insertDate(0, 0, 0);
		//string insertInstructions;

		Item::load(ifstr);

		//		ifstr.ignore();
		//getline(ifstr, insertInstructions, '\t');

		char inserting[1001];
		ifstr.getline(inserting, 1000, '\t');


		ifstr >> insertDate;
		ifstr.ignore(1000, '\n');


		if (!ifstr) {
			m_state = "Input file stream read (perishable) failed!";
		}
		else {
			m_state.clear();

			if (!insertDate) {
				this->m_expiry = insertDate;
			}
			else {
				this->m_expiry = insertDate;
			}

			

			//Instructions = new char[insertInstructions.length() + 1];
			//strcpy(Instructions, insertInstructions.c_str());

			if (*inserting == ' ') {
				Instructions = new char[strlen(inserting) + 1];
				strcpy(Instructions, inserting);
			}
			else {
				Instructions = new char[strlen(inserting) + 1];
				strcpy(Instructions, inserting);
			}
			
		}

		return ifstr;
	}

	ostream& Perishable::display(ostream& ostr) const
	{
		// TODO: insert return statement here
		if (!m_state) {
			ostr << m_state;
		}
		else {
			if (linear() == true) {
				//int amount = 0;
				//amount = strlen(Instructions) + 1;

				Item::display(ostr);
				if (Instructions != nullptr && std::strlen(Instructions) != 0) {
					ostr << "*";
				}
				else {
					ostr << " ";
				}
				ostr << this->m_expiry;
			}
			else if (linear() == false) {
				ostr << "Perishable ";
				Item::display(ostr);
				ostr << "Expiry date: ";
				ostr << m_expiry;
				if (Instructions != nullptr && std::strlen(Instructions) != 0) {
					ostr << "\nHandling Instructions: " << Instructions;
				}

				ostr << endl;
			}
		}

		return ostr;

	}

	istream& Perishable::read(istream& istr)
	{
		// TODO: insert return statement here
		string insertInstruction;
		Date newDate;

		Item::read(istr);

		delete[] Instructions;
		Instructions = nullptr;

		cout << "Expiry date (YYMMDD): ";

		istr >> newDate;
		istr.ignore(1000, '\n');


		cout << "Handling Instructions, ENTER to skip: ";

		if (istr.peek() != '\n') {
			getline(istr, insertInstruction, '\n');
		}



		if (istr.fail() == true) {
			m_state = "Perishable console date entry failed!";
		}
		else {
			m_state.clear();
			m_expiry = newDate;

			this->Instructions = new char[insertInstruction.length() + 1];

			strcpy(Instructions, insertInstruction.c_str());
		}

		return istr;
	}
}