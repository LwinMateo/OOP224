/*
Name: Lwin Yonal Mateo Lopez
Email: lymateo-lopez@myseneca.ca
Student ID: 134710201
Date: 03-31-2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<cstring>
#include<string>
#include<iomanip>
#include<fstream>
#include "Item.h"


using namespace std;

namespace sdds
{
	bool Item::linear() const
	{
		return m_linear;
	}
	Item::Item() : m_state("nothing")
	{
		this->m_price = 0;
		this->m_qty = 0;
		this->m_qtyNeeded = 0;
		this->m_description = nullptr;
		this->m_linear = false;

		this->m_sku = 0;
	}
	Item::Item(const Item& item)
	{
		m_description = nullptr;

		*this = item;
	}
	Item& Item::operator=(const Item& item)
	{
		// TODO: insert return statement here
		if (this != &item) {

			delete[] m_description;


			// SHALLOW COPY OF ATTRIBUTES
			this->m_price = item.m_price;

			this->m_qty = item.m_qty;

			this->m_qtyNeeded = item.m_qtyNeeded;

			this->m_linear = item.m_linear;

			// protected
			this->m_state = item.m_state;
			this->m_sku = item.m_sku;

			if (item.m_description != nullptr) {
				m_description = new char[strlen(item.m_description) + 1];
				strcpy(this->m_description, item.m_description);
			}
			else {
				m_description = nullptr;
			}


		}


		return *this;
	}
	Item::~Item()
	{
		delete[] m_description;
	}




	// returns the number of products needed
	int Item::qtyNeeded() const {
		return m_qtyNeeded;
	}

	// retuns the quantity on hand
	int Item::qty() const {
		return m_qty;
	}





	// returns the price of the produce
	Item::operator double() const {
		return m_price;
	}

	// returns if the iProduct is in a good state
	Item::operator bool() const {
		return (bool)m_state;
	}


	// to reduce the quantity on hand
	int Item::operator-=(int qty) {
		this->m_qty -= qty;

		return this->m_qty;
	}

	// to increase the quantity on hand
	int Item::operator+=(int qty) {
		this->m_qty += qty;

		return this->m_qty;
	}


	void Item::linear(bool isLinear)
	{
		m_linear = isLinear;
	}

	// PUBLIC MODIFIER
	void Item::clear() {
		m_state.clear();
	}


	// return true if the sku is a match to the iProduct's sku
	bool Item::operator==(int sku)const {
		return this->m_sku == sku;
	}

	// rtrns true if the description is found in the iPorduct's description
	bool Item::operator==(const char* description)const {
		return strstr(this->m_description, description) != 0;
	}




	// saves the iProduct into a file
	ofstream& Item::save(std::ofstream& ofstr)const {

		if ((bool)m_state == true) {
			ofstr << this->m_sku << "\t" << this->m_description << "\t" << this->m_qty << "\t" << this->m_qtyNeeded << "\t" << this->m_price;
		}

		return ofstr;
	}

	// loads an iProduct from a file
	ifstream& Item::load(std::ifstream& ifstr) {
		delete[] m_description;

		m_description = nullptr;

		int sku = -1;
		string insertDesciption;
		int quantityOnHand = -1;
		int quantityNeeded = -1;
		double price = -1;

		ifstr >> sku;
		ifstr.ignore();

		getline(ifstr, insertDesciption, '\t');

		ifstr >> quantityOnHand;
		ifstr >> quantityNeeded;
		ifstr >> price;

		ifstr.ignore();

		if (!ifstr) {
			m_state = "Input file stream read failed!";
		}
		else {
			m_state.clear();
			m_sku = sku;
			m_description = new char[insertDesciption.length() + 1];
			strcpy(m_description, insertDesciption.c_str());
			m_qty = quantityOnHand;
			m_qtyNeeded = quantityNeeded;
			m_price = price;
		}

		return ifstr;

	}

	// displays the iProduct on the screen
	ostream& Item::display(ostream& ostr) const {
		if (!m_state) {
			ostr << m_state;
		}
		else {
			if (m_linear == true) {


				ostr.width(5);
				ostr.setf(ios::left);
				ostr << m_sku << " | ";
				ostr.unsetf(ios::left);

				char shortDesc[35 + 1]{};
				strncpy(shortDesc, m_description, 35);
				ostr.width(35);
				ostr.setf(ios::left);
				ostr << shortDesc << " | ";
				ostr.unsetf(ios::left);


				ostr.width(4);
				ostr.setf(ios::right);
				ostr << m_qty << " | ";
				ostr.unsetf(ios::right);


				ostr.width(4);
				ostr.setf(ios::right);
				ostr << m_qtyNeeded << " | ";
				ostr.unsetf(ios::right);


				ostr.width(7);
				ostr.setf(ios::right);

				ostr << fixed << setprecision(2) << m_price << " |";
				ostr.unsetf(ios::right);



			}
			else {
				double ToPurchase = ((double)m_qtyNeeded - (double)m_qty) * m_price;


				ostr << "AMA Item:" << endl;
				ostr << m_sku << ": " << m_description << endl;
				ostr << "Quantity Needed: " << m_qtyNeeded << endl;
				ostr << "Quantity Available: " << m_qty << endl;
				ostr << "Unit Price: $" << m_price << setprecision(2) << endl;
				ostr << "Needed Purchase Fund: " << fixed << setprecision(2) << "$" << ToPurchase << endl;
			}
		}

		return ostr;
	}

	// reads the iProduct from the console
	istream& Item::read(istream& istr) {



		delete[] m_description;
		m_state.clear();


		bool newQ = false;
		bool NewQNeeded = false;
		bool newP = false;


		string newDescrip;
		int newQuantityNeeded = -1;
		int newQuantity = -1;
		double newPrice = -1;

		cout << "AMA Item:" << endl;
		cout << "SKU: " << this->m_sku << endl;


		cout << "Description: ";
		std::getline(istr, newDescrip, '\n');

		cout << "Quantity Needed: ";
		do {
			istr >> newQuantityNeeded;
			if (!istr) {
				cout << "Invalid Integer, retry: ";
				istr.clear();

			}
			else {
				if (newQuantityNeeded < 1 || newQuantityNeeded > 9999) {
					cout << "Value out of range [1<=val<=9999]: ";
				}
				else {
					NewQNeeded = true;
				}
			}
			istr.ignore(1000, '\n');
		} while (NewQNeeded != true);


		cout << "Quantity On Hand: ";
		do {
			istr >> newQuantity;
			if (!istr) {
				cout << "Invalid Integer, retry: ";
				istr.clear();

			}
			else {
				if (newQuantity < 0 || newQuantity > newQuantityNeeded) {
					cout << "Value out of range [0<=val<=" << newQuantityNeeded << "]: ";
				}
				else {
					newQ = true;
				}
			}
			istr.ignore(1000, '\n');
		} while (newQ != true);


		cout << "Unit Price: $";
		do {
			istr >> newPrice;
			if (!istr) {
				cout << "Invalid number, retry: ";
				istr.clear();

			}
			else {
				if (newPrice < 0.0 || newPrice > 9999.0) {
					cout << "Value out of range [0.00<=val<=9999.00]: ";
				}
				else {
					newP = true;
				}
			}
			istr.ignore(1000, '\n');
		} while (newP != true);




		if (!istr) {
			m_state = "Console entry failed!";
		}
		else {
			m_state.clear();

			m_description = new char[newDescrip.length() + 1];


			strcpy(m_description, newDescrip.c_str());

			m_qty = newQuantity;
			m_qtyNeeded = newQuantityNeeded;
			m_price = newPrice;
		}

		return istr;
	}


	// to read the Stock-Keeping Unit from console before
	// main data entry
	int Item::readSku(istream& istr) {
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
				if (getSku < 40000 || getSku > 99999) {
					cout << "Value out of range [40000<=val<=99999]: ";
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

}
