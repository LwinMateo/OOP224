/*
Name: Lwin Yonal Mateo Lopez
Email: lymateo-lopez@myseneca.ca
Student ID: 134710201
Date: 02-09-2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<string.h>
#include "CarInventory.h"

using namespace std;

namespace sdds
{

	CarInventory::CarInventory() {
		resetInfo();
	}

	CarInventory::CarInventory(const char* type, const char* brand, const char* model, int year, int code, double price) {

		if (type != nullptr && brand != nullptr && model != nullptr && year >= 1990 && (code >=100 && code < 1000) && price > 0) {
			m_type = new char[strlen(type) + 1];
			m_brand = new char[strlen(brand) + 1];
			m_model = new char[strlen(model) + 1];

			strcpy(m_type, type);
			strcpy(m_brand, brand);
			strcpy(m_model, model);
			m_year = year;
			m_code = code;
			m_price = price;
			
		}
		else {	
			resetInfo();
		}

	}

	CarInventory::~CarInventory() {
		delete[] m_type;
		delete[] m_brand;
		delete[] m_model;
		m_type = nullptr;
		m_brand = nullptr;
		m_model = nullptr;
	}

	void CarInventory::resetInfo() {
		m_type = nullptr;
		m_brand = nullptr;
		m_model = nullptr;
		m_year = 0;
		m_code = 0;
		m_price = 0;
	}

	CarInventory& CarInventory::setInfo(const char* type, const char* brand, const char* model, int year, int code, double price) {
		delete[] m_type;
		delete[] m_brand;
		delete[] m_model;


		if (type != nullptr && brand != nullptr && model != nullptr) {
			m_type = new char[strlen(type) + 1];
			m_brand = new char[strlen(brand) + 1];
			m_model = new char[strlen(model) + 1];
			strcpy(m_type, type);
			strcpy(m_brand, brand);
			strcpy(m_model, model);
			m_year = year;
			m_code = code;
			m_price = price;

		}
		else {
			resetInfo();
		}

		

		return *this;

	}

	void CarInventory::printInfo() const {

		cout << "| ";
		cout << setw(10) << left << m_type;

		cout << " | ";
		cout << setw(16) << left << m_brand;

		cout << " | ";
		cout << setw(16) << left << m_model;

		cout << " | ";
		cout << m_year;
		cout << " |  ";

		cout << m_code;

		cout << " | ";

		cout << fixed << setprecision(2) <<setw(9)<<right<< m_price;

		cout << " |" << endl;
	}

	bool CarInventory::isValid() const {
		return m_type != nullptr && m_brand != nullptr && m_model != nullptr && m_year >= 1990 && (m_code >= 100 && m_code < 1000) && m_price > 0;
	}

	bool CarInventory::isSimilarTo(const CarInventory& car) const {
		bool isSimilar = false;

		if ((car.m_type != nullptr && m_type != nullptr) && (car.m_brand != nullptr && m_brand != nullptr) && (car.m_model != nullptr && m_model != nullptr)) {
			if(strcmp(m_type, car.m_type) == 0 && strcmp(m_brand, car.m_brand) == 0 && strcmp(m_model,car.m_model) == 0 && car.m_year == m_year)
				isSimilar = true;
		}

		return isSimilar;
	}

	bool find_similar(CarInventory car[], const int num_cars) {
		bool matchFound = false;

		for (int i = 0; i < num_cars; i++) {
			for (int j = i + 1; j < num_cars; j++) {
				if (car[i].isSimilarTo(car[j]) == true) {
					// match is found
					matchFound = true;
				}
			}
		}

		return matchFound;
	}

	

}