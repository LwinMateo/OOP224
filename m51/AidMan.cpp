/*
Name: Lwin Yonal Mateo Lopez
Email: lymateo-lopez@myseneca.ca
Student ID: 134710201
Date: 04-08-2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<fstream>
#include<iomanip>
#include<string.h>
#include<string>
#include<cctype>
#include"Menu.h"
#include "AidMan.h"
#include"Utils.h"
#include"Date.h"
#include"iProduct.h"
#include"Item.h"
#include "Perishable.h"

using namespace std;

namespace sdds
{

	unsigned int AidMan::menu() {
		Date date(0, 0, 0);
		unsigned int insertOption;

		cout << "Aid Management System" << endl;
		cout << "Date: " << date << endl;
		if (m_filename == nullptr) {
			cout << "Data file: No file" << endl;
		}
		else {
			cout << "Data file: " << m_filename << endl;
		}
		cout << "---------------------------------" << endl;

		insertOption = AidMan().theMenu.run();

		return insertOption;
	}

	AidMan::AidMan() : theMenu(7, "1- List Items\n2- Add Item\n3- Remove Item\n4- Update Quantity\n5- Sort\n6- Ship Items\n7- New/Open Aid Database\n---------------------------------\n") { // INITIALIZATION LIST
		m_filename = nullptr;
	}


	//Rule of three (----------NOT IMPLEMENTED------------)
	//AidMan(const AidMan& aid) = delete;
	//AidMan& operator=(const AidMan aid) = delete;



	AidMan::~AidMan() {
		deallocate();
	}

	void AidMan::run() {
		unsigned int num = 0;

		do {
			num = menu();
			if (num != 0 && m_filename == nullptr && num != 7) {
				num = 7;
			}

			if (num == 1) {

				cout << "\n****List Items****\n";


				int count{};
				count = list();
				int option{};

				if (count != 0)
				{
					cin.ignore();
					cout << "Enter row number to display details or <ENTER> to continue:\n> ";
					if (cin.peek() != '\n')
					{

						cin >> option;
						if (option > 0 && option <= count) {
							m_products[option - 1]->linear(false);
							m_products[option - 1]->display(cout);
							cout << endl;
							cout << endl;

						}
						else {
							cout << "Invalid Index" << endl;
						}
					}
					else {
						cout << endl;
					}
				}


			}
			else if (num == 2) {
				cout << "\n****Add Item****\n\n";
			}
			else if (num == 3) {
				cout << "\n****Remove Item****\n\n";
			}
			else if (num == 4) {
				cout << "\n****Update Quantity****\n\n";
			}
			else if (num == 5) {
				cout << "\n****Sort****\n\n";
			}
			else if (num == 6) {
				cout << "\n****Ship Items****\n\n";
			}
			else if (num == 7) {

				this->load();

			}
			else if (num == 0) {
				cout << "Exiting Program!\n";
			}
		} while (num != 0);
		save();

	}





	void AidMan::save() {
		if (m_filename != nullptr) {
			ofstream file(m_filename, ios::out);
			for (int i = 0; i < sdds_max_num_items; i++) {
				if (m_products[i] != nullptr) {
					m_products[i]->save(file) << endl;
				}
			}
			file.close();
		}
	}

	void AidMan::deallocate() {
		for (int i = 0; i < number_of_iProduct_Items; i++) {
			delete m_products[i];
			m_products[i] = nullptr;
		}

		delete[] m_filename;
		m_filename = nullptr;

		number_of_iProduct_Items = 0;
	}


	void AidMan::load() {
		this->save();
		this->deallocate();

		string insertfile;
		cout << "\n****New/Open Aid Database****\n";
		cout << "Enter file name: ";

		cin >> insertfile;


		delete[] m_filename;
		m_filename = nullptr;
		if (insertfile.length() != 0) {
			m_filename = new char[insertfile.length() + 1];
			strcpy(m_filename, insertfile.c_str());
		}


		ifstream in(m_filename, ios::in);
		if (in.fail() == true) {
			int option = 0;
			do {
				cout << "Failed to open " << m_filename << " for reading!\n";
				cout << "Would you like to create a new data file?\n";
				cout << "1- Yes!\n0 - Exit\n> ";
				cin >> option;
				if (option == 1) {
					ofstream ofs;
					ofs.open(m_filename, ios::out);
					ofs.close();
					option = 0;
				}
			} while (option != 0);

		}
		else {
			while (in.good()) {
				char next = in.peek();

				if (next >= '1' && next <= '9') {
					if (next >= '1' && next <= '3')
					{
						m_products[this->number_of_iProduct_Items] = new Perishable();
					}
					else if (next > '3')
					{
						m_products[number_of_iProduct_Items] = new Item();
					}

					m_products[number_of_iProduct_Items]->load(in);
					if (in.good()) {
						number_of_iProduct_Items++;
					}
					else {
						delete m_products[number_of_iProduct_Items];
						m_products[number_of_iProduct_Items] = nullptr;
					}
				}

				else
				{
					in.setstate(ios::failbit);
				}


			}
			in.close();
			cout << number_of_iProduct_Items << " records loaded!\n\n";

		}
	}

	int AidMan::list(const char* sub_desc)
	{
		int count = 0;

		if (number_of_iProduct_Items != 0) {
			cout << " ROW |  SKU  | Description                         | Have | Need |  Price  | Expiry" << endl;
			cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;

			if (sub_desc == nullptr) {
				for (int i = 0; i < number_of_iProduct_Items; i++) {
					this->m_products[i]->linear(true);

					cout.width(4);
					cout.fill(' ');
					cout.setf(ios::right);
					cout << i + 1;
					cout << " | ";
					cout.unsetf(ios::right);

					this->m_products[i]->display(cout);

					if (i != number_of_iProduct_Items - 1) {
						cout << endl;
					}
					count++;
				}
				cout << "\n-----+-------+-------------------------------------+------+------+---------+-----------\n";
			}
			else {
				for (int i = 0; i < number_of_iProduct_Items; i++) {

					if (*m_products[i] == sub_desc) {
						this->m_products[i]->linear(true);

						cout.width(4);
						cout.fill(' ');
						cout.setf(ios::right);
						cout << i + 1;
						cout << " | ";
						cout.unsetf(ios::right);

						this->m_products[i]->display(cout);

						if (i != number_of_iProduct_Items - 1) {
							cout << endl;
						}
						count++;
					}

				}
				cout << "-----+-------+-------------------------------------+------+------+---------+-----------\n";

			}

			if (count == 0) {
				cout << "The list is empty!\n\n";
			}
		}
		else {
			cout << "The list is empty!\n\n";
		}

		return count;
	}

}
