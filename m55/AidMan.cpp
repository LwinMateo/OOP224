/*
Name: Lwin Yonal Mateo Lopez
Email: lymateo-lopez@myseneca.ca
Student ID: 134710201
Date: 04-11-2022
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
				cout << "\n****Add Item****\n";
				if (number_of_iProduct_Items >= sdds_max_num_items) {
					cout << "Database full!\n";
				}
				else {
					cout << "1- Perishable\n";
					cout << "2- Non-Perishable\n-----------------\n";
					cout << "0 - Exit" << endl;
					int option = ut.getint(0, 2, "> ");

					if (option == 0) {
						cout << "Aborted\n";
					}
					else if (option == 1) {

						m_products[number_of_iProduct_Items] = new Perishable;
						int sku = m_products[number_of_iProduct_Items]->readSku(cin);
						if (search(sku) >= 0) {
							cout << "Sku: " << sku << " is already in the system, try updating quantity instead.\n\n";
							delete m_products[number_of_iProduct_Items];
							m_products[number_of_iProduct_Items] = nullptr;
						}
						else {
							m_products[number_of_iProduct_Items]->read(cin);
							number_of_iProduct_Items++;
						}
					}
					else {

						m_products[number_of_iProduct_Items] = new Item;
						int sku = m_products[number_of_iProduct_Items]->readSku(cin);
						if (search(sku) >= 0) {
							cout << "Sku: " << sku << " is already in the system, try updating quantity instead.\n";
							delete m_products[number_of_iProduct_Items];
							m_products[number_of_iProduct_Items] = nullptr;
						}
						else {
							m_products[number_of_iProduct_Items]->read(cin);
							number_of_iProduct_Items++;
						}
					}
					cout << endl;
				}
			}
			else if (num == 3) {
				string characters;
				char* copy;
				int getNumber = 0;

				cout << "\n****Remove Item****\n";
				cout << "Item description: ";
				cin >> characters;
				copy = new char[characters.length() + 1];
				strcpy(copy, characters.c_str());

				getNumber = list(copy);



				delete[] copy;

				if (getNumber > 0) {
					int insertSku = 0;
					int indexFound = 0;

					cout << "Enter SKU: ";
					cin >> insertSku;
					//cin.ignore('\n');

					indexFound = search(insertSku);

					if (indexFound == -1) {
						cout << "SKU not found!\n";
					}
					else {

						cout << "Following item will be removed: \n";
						this->m_products[indexFound]->linear(false);
						this->m_products[indexFound]->display(cout);

						cout << "\nAre you sure?\n";
						cout << "1- Yes!\n";
						cout << "0- Exit\n";
						int option = ut.getint(0, 2, "> ");
						if (option == 0) {
							cout << "Aborted!\n";
						}
						else {
							remove(indexFound);
							cout << "Item removed!\n\n";
						}
					}
				}


			}
			else if (num == 4) {
				string characters;
				char* copy;
				int getNumber = 0;

				cout << "\n****Update Quantity****\n";
				cout << "Item description: ";
				cin >> characters;
				copy = new char[characters.length() + 1];
				strcpy(copy, characters.c_str());

				getNumber = list(copy);



				delete[] copy;

				if (getNumber > 0) {
					int insertSku = 0;
					int indexFound = 0;

					cout << "Enter SKU: ";
					cin >> insertSku;
					//cin.ignore('\n');

					indexFound = search(insertSku);

					if (indexFound == -1) {
						cout << "SKU not found!\n";
					}
					else {

						cout << "1- Add\n";
						cout << "2- Reduce\n";
						cout << "0- Exit\n";
						int option = ut.getint(0, 2, "> ");
						if (option == 0) {
							cout << "Aborted!\n\n";
						}
						else if (option == 1) {
							if (this->m_products[indexFound]->qty() == this->m_products[indexFound]->qtyNeeded()) {
								cout << "Quantity Needed already fulfilled!\n\n";
							}
							else {
								cout << "Quantity to add: ";
								bool goodQuantity = false;
								int AddNumber = 0;
								do {
									cin >> AddNumber;
									if (!cin) {
										cout << "Invalid Integer, retry: ";
										cin.clear();

									}
									else {
										if (AddNumber < 1 || AddNumber > this->m_products[indexFound]->qtyNeeded()) {
											cout << "Value out of range [1<=val<=" << this->m_products[indexFound]->qtyNeeded() << "]: ";
										}
										else {
											goodQuantity = true;
										}
									}
									cin.ignore(1000, '\n');
								} while (goodQuantity != true);
								*m_products[indexFound] += AddNumber;
								cout << AddNumber << " items added!\n\n";
							}

						}
						else if (option == 2) {
							if (this->m_products[indexFound]->qty() == 0) {
								cout << "Quantity on hand is zero!\n\n";
							}
							else {
								cout << "Quantity to reduce: ";
								bool goodQuantity = false;
								int ReduceNumber = 0;
								do {
									cin >> ReduceNumber;
									if (!cin) {
										cout << "Invalid Integer, retry: ";
										cin.clear();

									}
									else {
										if (ReduceNumber < 1 || ReduceNumber > this->m_products[indexFound]->qtyNeeded()) {
											cout << "Value out of range [1<=val<=" << this->m_products[indexFound]->qtyNeeded() << "]: ";
										}
										else {
											goodQuantity = true;
										}
									}
									cin.ignore(1000, '\n');
								} while (goodQuantity != true);
								*m_products[indexFound] -= ReduceNumber;
								cout << ReduceNumber << " items removed!\n\n";
							}
						}

					}
				}

			}
			else if (num == 5) {
				cout << "\n****Sort****\n";
				sort();
				cout << "Sort completed!\n\n";
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

		char inputFile[1000];
		cout << "\n****New/Open Aid Database****\n";
		cout << "Enter file name: ";

		cin >> inputFile;


		delete[] m_filename;
		m_filename = nullptr;
		m_filename = new char[strlen(inputFile) + 1];
		strcpy(m_filename, inputFile);

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

					if (in.good()) {
						m_products[number_of_iProduct_Items]->load(in);
						number_of_iProduct_Items++;
					}

					if (in.good() == false) {
						delete m_products[number_of_iProduct_Items];
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

	int AidMan::search(int sku) const {
		int index = -1;
		for (auto i = 0; i < number_of_iProduct_Items; i++) {
			if (*m_products[i] == sku) {
				index = i;
			}
		}
		return index;
	}


	void AidMan::remove(int index) {
		delete this->m_products[index];
		for (auto i = index; i < number_of_iProduct_Items; i++) {
			this->m_products[i] = this->m_products[i + 1];
		}
		number_of_iProduct_Items -= 1;
	}


	void AidMan::sort() {
		int i, j;


		for (i = number_of_iProduct_Items - 1; i > 0; i--) {
			for (j = 0; j < i; j++) {

				int qtyItem1 = this->m_products[j]->qtyNeeded() - this->m_products[j]->qty();
				int qtyItem2 = this->m_products[j + 1]->qtyNeeded() - this->m_products[j + 1]->qty();
				if (qtyItem1 < qtyItem2) {

					iProduct* temp = m_products[j];
					m_products[j] = m_products[j + 1];
					m_products[j + 1] = temp;

				}
			}
		}
	}
}