/*
Name: Lwin Yonal Mateo Lopez
Email: lymateo-lopez@myseneca.ca
Student ID: 134710201
Date: 01-26-2022

*/


#include<iostream>
#include "Car.h"
#include "cStrTools.h"

using namespace std;

namespace sdds
{

	Car* cars = nullptr; // A Car pointer to hold the dynamic array of cars (We call this "The Car Pointer" in this text)

	int allocation_size = 0; // an integer to hold the memory allocation and expansion size when needed

	int numOfCars = 0; // an integer to hold the number of cars currently in the dynamic array of cars pointed by The Car Pointer

	int carArraySize = 0;

	void VBPLE_Title() {
		cout << "Vehicle Border Passing Log Entry" << endl;
		cout << "Enter the data in the following format:" << endl;
		cout << "Make and model,LicensePlate,MilitaryTime<ENTER>" << endl;
		cout << "Exit the program by entering the following:" << endl;
		cout << "X,<ENTER>" << endl;
	}

	void initialize(int allocSize) {
		numOfCars = 0;
		allocation_size = allocSize; // this would size by the allocSize
		carArraySize = allocSize; // this would size the carArraySize by the allocSize
		cars = new Car[carArraySize];
	}

	void deallocate(Car& C) {
		delete[] C.make_and_model;
		C.make_and_model = nullptr;
	}

	bool read(Car& C) {
		bool flagOfModel = false;

		char readMakeAndModel[61];

		//using the cStrTools read() function

		read(readMakeAndModel, 60, ',');

		if (*readMakeAndModel != 'X') {
			flagOfModel = true;

			int stringlength = strLen(readMakeAndModel);

			C.make_and_model = new char[stringlength+1];


			strCpy(C.make_and_model, readMakeAndModel);
			read(C.license_plate, 8, ',');

			cin >> C.time;

		}

		return flagOfModel;
	}

	void print(const Car& C) {
		cout << C.time << ": " << C.make_and_model << "," << C.license_plate << endl;
	}

	

	void record(const Car& C) {

		// doing a resize
		if (numOfCars == carArraySize) {
			Car* tempLocalCar = new Car[carArraySize + allocation_size];

			for (auto i = 0; i < numOfCars; i++) {
				tempLocalCar[i] = cars[i];
			}

			delete[] cars;
			cars = tempLocalCar;
			carArraySize += allocation_size;
		}

		// to restore
		cars[numOfCars] = C;
		numOfCars++;


	}

	void endOfDay() {
		for (auto i = 0; i < numOfCars; i++) {
			print(cars[i]);
			deallocate(cars[i]);
		}
		delete[] cars;
		cars = nullptr;
	}

}
