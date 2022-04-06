/*
Name: Lwin Yonal Mateo Lopez
Email: lymateo-lopez@myseneca.ca
Student ID: 134710201
Date: 03-13-2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <string>
#include <cctype>

#include "Status.h"

using namespace std;

namespace sdds {
	//Status();
	Status::Status(const char* description) {
		if (description != nullptr) {
			delete[] Description_Status;
			Description_Status = new char[strlen(description) + 1];
			strcpy(Description_Status, description);
		}
		else if (description == nullptr) {
			delete[] Description_Status;
			Description_Status = nullptr;
		}
		else {
			Optional_Status_Code = 0;
		}
	}

	//Rule of three
	Status::Status(const Status& status) {
		Description_Status = nullptr;
		*this = status;
	}
	Status& Status::operator=(const Status& status) {
		if (this != &status) {
			delete[] Description_Status;
			Description_Status = nullptr;

			Optional_Status_Code = status.Optional_Status_Code;

			if (status.Description_Status != nullptr) {
				Description_Status = new char[strlen(status.Description_Status) + 1];

				strcpy(Description_Status, status.Description_Status);
			}
		}

		return *this;
	}

	Status::~Status() {
		delete[] Description_Status;
		
	}



	// assignment operators
	Status& Status::operator=(int addNum) {
		Optional_Status_Code = addNum;

		return *this;
	}

	Status& Status::operator=(const char* newDescription) {
		delete[] Description_Status;
		if (newDescription != nullptr) {
			Description_Status = new char[strlen(newDescription) + 1];
			strcpy(Description_Status, newDescription);
		}

		return *this;
	}


	
	// type conversion Overloads
	Status::operator int() const {
		return Optional_Status_Code;
	}
	Status::operator const char* () const {
		return Description_Status;
	}

	Status::operator bool() const{
		return Description_Status == nullptr;
	}



	

	Status& Status::clear() {
		delete[] Description_Status;
		Description_Status = nullptr;
		Optional_Status_Code = 0;

		return *this;
	}


	// HELPER OPERATOR
	ostream& operator<<(ostream& ost, const Status& status) {
		if ((bool)status == false) {
			if ((int)status != 0) {
				ost << "ERR#" << (int)status << ": ";
				ost << (const char*)status;
			}
			else {
				ost << (const char*)status;
			}
		}
		return ost;
	}
}