/*
Name: Lwin Yonal Mateo Lopez
Email: lymateo-lopez@myseneca.ca
Student ID: 134710201
Date: 03-14-2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Pack.h"
#include"Container.h"

using namespace std;

namespace sdds
{
	Pack::Pack(const char* content, int size, int unit_Size, int NumOfUnits) : Container(content, size*unit_Size, NumOfUnits*unit_Size){
		if (unit_Size > 0) {
			unitSize = unit_Size;
		}
		
	}

	int Pack::operator+=(int Value) {
		int theNumber = Container::operator+=(Value*unitSize);

		theNumber /= this->unitSize;

		return theNumber;

	}
	int Pack::operator-=(int Value) {
		int theNumber = Container::operator-=(Value * unitSize);

		theNumber /= this->unitSize;

		return theNumber;
	}

	int Pack::unit() const {
		return this->unitSize;
	}
	int Pack::noOfUntis() const {
		return Container::volume() / this->unitSize;
	}
	int Pack::size() const {
		return Container::capacity() / this->unitSize;
	}

	Pack& Pack::clear(int packSize, int unit_Size, const char* content) {
		if (unit_Size > 0) {
			Container::clear(packSize * unit_Size, content);
			this->unitSize = unit_Size;
		}
		return *this;
	}

	ostream& Pack::print(ostream& os) const {
		
		Container::print(os);
		if (this->unitSize > 0) {
			cout << ", " << noOfUntis() << " in a pack of " << size();
		}
		return os;
	}
	istream& Pack::read(istream& is) {
		int input;
		bool Valid = false;

		if (!(*this)) {
			
			cout << "Broken Container, adding aborted! Press <ENTER> to continue....";
			is.ignore(1000, '\n');
		}
		else {
			if (this->noOfUntis() < this->size())
			{
				// we can get more units
				// read an integer from "is" and add it to the pack
				cout << "Add to ";
				print(cout);
				cout << "\n> ";
				while (Valid == false) {
					is >> input;
					if (!is) {
						cout << "Invalid Integer, retry: ";
						is.clear();
					}
					else {
						if (input < 1 || input > size() - noOfUntis()) {
							cout << "Value out of range [1<=val<=" << size() - this->noOfUntis() << "]: ";
						}
						else {
							cout << "Added " << (*this += input) << endl;
							Valid = true;
						}
					}
					is.ignore(1000, '\n');
				}
			}
			else
			{
				// pack if full, nothing can be added
				cout << "Pack is full!, press <ENTER> to continue...";
				is.ignore(1000, '\n');
				
			}
		}


		return is;
		
	}

	istream& operator>>(istream& is, Pack& pack) {
		pack.read(is);
		return is;
	}

	ostream& operator<<(ostream& os, const Pack& pack) {
		pack.print(os);
		return os;
	}
}