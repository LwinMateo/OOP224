#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cctype>
#include<string.h>
#include "Name.h"
using namespace std;
namespace sdds
{
	Name::Name() {
		First_Name = nullptr;
		Middle_Name = nullptr;
		Last_Name = nullptr;
	}
	
	Name::Name(const char* firstName) {
		//delete[] First_Name;

		if (firstName != nullptr) {
			First_Name = new char[strlen(firstName) + 1];
			strcpy(First_Name, firstName);
		}
		else {
			*this = Name();
		}
	}

	Name::Name(const char* firstName, const char* middleName) {
		//delete[] First_Name;
		//delete[] Middle_Name;

		if (firstName != nullptr && middleName != nullptr) {
			First_Name = new char[strlen(firstName) + 1];
			Middle_Name = new char[strlen(middleName) + 1];

			strcpy(First_Name, firstName);
			strcpy(Middle_Name, middleName);
		}
		else {
			*this = Name();
		}
	}

	Name::Name(const char* firstName, const char* middleName, const char* lastName) {
		//delete[] First_Name;
		//delete[] Middle_Name;
		//delete[] Last_Name;

		if (firstName != nullptr && middleName != nullptr && lastName != nullptr) {
			First_Name = new char[strlen(firstName) + 1];
			Middle_Name = new char[strlen(middleName) + 1];
			Last_Name = new char[strlen(lastName) + 1];

			strcpy(First_Name, firstName);
			strcpy(Middle_Name, middleName);
			strcpy(Last_Name, lastName);

		}
		else {
			*this = Name();
		}
	}

	

	//RULES OF THREE
	Name::Name(const Name& name) {
		First_Name = nullptr;
		Middle_Name = nullptr;
		Last_Name = nullptr;

		*this = name;
	}

	Name& Name::operator=(const Name& name) {
		if (this != &name) {
			delete[] First_Name;
			delete[] Middle_Name;
			delete[] Last_Name;

			if (name.First_Name != nullptr && name.Middle_Name != nullptr && name.Last_Name != nullptr) {
				First_Name = new char[strlen(name.First_Name) + 1];
				Middle_Name = new char[strlen(name.Middle_Name) + 1];
				Last_Name = new char[strlen(name.Last_Name) + 1];

				strcpy(First_Name, name.First_Name);
				strcpy(Middle_Name, name.Middle_Name);
				strcpy(Last_Name, name.Last_Name);
			}
			else {
				First_Name = nullptr;
				Middle_Name = nullptr;
				Last_Name = nullptr;
			}
		}

		return *this;
	}

	Name::~Name() {
		delete[] First_Name;
		delete[] Middle_Name;
		delete[] Last_Name;
	}

	void Name::setShort(bool pass) {
		
		if (pass == false) {
			char* Abbrev{};

			Abbrev = new char[strlen(Middle_Name) + 1];

			//delete[] Middle_Name;

			for (auto i = 0; Middle_Name[i] != '\0'; i++) {
				if (i == 0) {
					Abbrev[i] = Middle_Name[i];
				}
				if (i == 1) {
					Abbrev[i] = '.';
				}	
			}

			delete[] Middle_Name;

			strcpy(Middle_Name, Abbrev);

			delete[] Abbrev;
		}
	}

	// adding a cString
	Name& Name::operator+=(const char* addString) {
		// this variable works to count if there are spaces in a Cstring
		int countSpace = 0;
		
		if (First_Name == nullptr) {
			First_Name = new char[strlen(addString) + 1];
			strcpy(First_Name, addString);
		}
		
		if (Middle_Name == nullptr) {
			Middle_Name = new char[strlen(addString) + 1];
			strcpy(Middle_Name, addString);
		}

		if (Last_Name == nullptr) {
			Last_Name = new char[strlen(addString) + 1];
			strcpy(Last_Name, addString);
		}

		if (First_Name != nullptr && Middle_Name != nullptr && Last_Name != nullptr) {
			*this = Name();
		}

		

		for (auto i = 0; addString[i] != '\0'; i++) {
			if (isspace(addString[i])) {
				countSpace++;
			}
		}
		if (countSpace > 0) {
			*this = Name();
		}

		if (addString == nullptr) {
			*this = Name();
		}

		return *this;

	}

	Name::operator bool() const {
		return First_Name != nullptr;
	}

	// functions for iostream
	istream& Name::read(istream& istr) {
		
		char* theFirstName = new char[Maximum + 1];
		char* theMiddleName = new char[Maximum + 1];
		char* theLastName = new char[Maximum + 1];

		istr.get(theFirstName, Maximum+1);

		istr.get(theMiddleName, Maximum+1);

		istr.get(theMiddleName, Maximum+1);

		if (istr.fail() == true) {
			*this = Name();
		}
		else {
			*this = Name(theFirstName, theMiddleName, theLastName);
		}

		istr.clear();
		//istr.ignore(1000, '\n');

		delete[] theFirstName;
		delete[] theMiddleName;
		delete[] theLastName;

		return istr;
	}

	ostream& Name::display(ostream& ostr) const {
		if (First_Name != nullptr && Middle_Name != nullptr && Last_Name != nullptr) {
			ostr << First_Name << " " << Middle_Name << " " << Last_Name;
		}

		if (First_Name != nullptr && Middle_Name == nullptr && Last_Name != nullptr) {

			//delete[] Middle_Name;
			ostr << First_Name << " " << Last_Name;
		}

		if (First_Name != nullptr && Middle_Name == nullptr && Last_Name == nullptr) {
			//delete[] Middle_Name;
			//delete[] Last_Name;
			ostr << First_Name;
		}

		

		return ostr;
	}
	


	// HELPER FUNCTIONS
	istream& operator>>(istream& istr, Name& name) {
		name.read(istr);
		return istr;
	}

	ostream& operator<<(ostream& ostr, const  Name& name) {
		if (name) {
			name.display(ostr);
		}
		else {
			ostr << "Bad Name";
		}

		return ostr;
	}
}