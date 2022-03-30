/*
Name: Lwin Yonal Mateo Lopez
Email: lymateo-lopez@myseneca.ca
Student ID: 134710201
Date: 03-14-2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include "Container.h"

using namespace std;

namespace sdds
{
	void Container::setEmpty() {
		Content[0] = '\0';
		Capacity = 0;
		Content_Volume = 0;
	}

	int Container::capacity() const {
		return Capacity;
	}

	int Container::volume() const {
		return Content_Volume;
	}

	Container::Container(const char* content, int capacity, int contentVolume) {

		if (content == nullptr || contentVolume > capacity) {
			setEmpty();
		}
		else {
			strcpy(Content, content);
			Capacity = capacity;
			Content_Volume = contentVolume;
		}

	}

	int Container::operator+=(int Value){
		int Portion = 0;
		Portion = Capacity - Content_Volume;
		int actualAmount = 0;
		if (Value <= Portion) {
			Content_Volume += Value;
			actualAmount = Value;
		}
		else if (Value > Portion) {
			Content_Volume += Portion;
			actualAmount = Portion;
		}

		return actualAmount;
	}

	int Container::operator-=(int Value){

		int reducedAmount = 0;

		if (Value < Content_Volume) {
			Content_Volume -= Value;
			reducedAmount = Value;
		}
		else if (Value > Content_Volume) {
			reducedAmount = Content_Volume;
			Content_Volume -= reducedAmount;

		}

		return reducedAmount;
	}

	//conversion
	Container::operator bool() const {
		return Content[0] != '\0';
	}


	Container& Container::clear(int capacity, const char* description) {
		if(capacity > 0 && description != nullptr){
			strcpy(Content, description);
			Capacity = capacity;
			//Content_Volume = 0;
		}

		return *this;
	}

	ostream& Container::print(ostream& out) const {
		if (!(*this)) {
			out << "****: (**cc/***)";
		}
		else {
			out << Content << ": (" << Content_Volume << "cc/" << Capacity << ")";
		}

		return out;
	}

	istream& Container::read(istream& in){
		int input;
		bool Valid = false;

		if (!(*this)) {
			//in.clear();
			
			cout << "Broken Container, adding aborted! Press <ENTER> to continue....";
			in.ignore(1000, '\n');
		}
		else {
			// valid container
			cout << "Add to ";
			print(cout);
			cout << "\n> ";
			while (Valid == false) {
				in >> input;
				if (!in) {
					cout << "Invalid Integer, retry: ";
					in.clear();
					
				}
				else {
					if (input < 1 || input >= 220000) {
						cout << "Value out of range [1<=val<=220000]: ";
					}
					else {
						cout << "Added " << (*this += input) << " CCs" << endl;
						Valid = true;
					}
				}
				in.ignore(1000, '\n');
			}
			
		}

		return in;
	}


	istream& operator>>(istream& is, Container& c) {
		c.read(is);
		return is;
	}

	ostream& operator<<(ostream& os, const Container& c) {
		c.print(os);
		return os;
	}
}


	