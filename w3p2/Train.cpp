/*
Name: Lwin Yonal Mateo Lopez
Email: lymateo-lopez@myseneca.ca
Student ID: 134710201
Date: 02-06-2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include"Train.h"

using namespace std;

namespace sdds
{

	void Train::set(const char* name, int numPeople, double speed) {
		if ((name != nullptr && strlen(name) > 0) && (numPeople > 0 && numPeople < MAX_PEOPLE) && (speed > 0 && speed < MAX_SPEED)) {
			strncpy(nameOfTrain, name, MAX_NAME_LEN);
			NumOfPpleOnTrain = numPeople;
			speedOfTrain = speed;
		}
		else {
			// I used these variable members of the object set to empty values


			nameOfTrain[0] = '\0'; // I set this variable having index 0 of nameOfTrain set to the null terminator
			NumOfPpleOnTrain = -1; // I set the integer type, NumOfPpleOnTrain to -1 for avoiding errors
			speedOfTrain = -1; // I set the double type, speed to -1 for avoiding errors

		}
	}

	int Train::getNumberOfPeople() const {
		return NumOfPpleOnTrain;
	}

	const char* Train::getName() const {
		return nameOfTrain;
	}

	double Train::getSpeed() const {
		return speedOfTrain;
	}

	bool Train::isSafeEmpty() const {

		return nameOfTrain[0] == '\0' && NumOfPpleOnTrain < 0 && speedOfTrain < 0;
	}

	void Train::display() const {
		if (isSafeEmpty() == true) {
			cout << "Safe Empty State!" << endl;
		}
		else {
			cout << "NAME OF THE TRAIN";
			cout.width(2);
			cout.setf(ios::right);
			cout << " : " << nameOfTrain << endl;
			cout.setf(ios::fixed);

			cout << "NUMBER OF PEOPLE";
			cout.width(4);
			cout.setf(ios::right);
			cout << " : " << NumOfPpleOnTrain << endl;
			cout.setf(ios::fixed);

			cout << "SPEED";
			cout.width(15);
			cout.precision(2);
			cout.setf(ios::right);
			cout << " : " << speedOfTrain << " km/h" << endl;
			cout.setf(ios::fixed);
		}
	}

	bool Train::loadPeople(int additional) {
		bool successCount = false;

		if (isSafeEmpty() == true) {
			successCount = false;
		}
		else {
			NumOfPpleOnTrain += additional;

			if (NumOfPpleOnTrain > MAX_PEOPLE) {
				NumOfPpleOnTrain = MAX_PEOPLE;
			}
			else if(NumOfPpleOnTrain < 0) {
				NumOfPpleOnTrain = 0;
			}

			successCount = true;

		}
		

		return successCount;
	}


	bool Train::changeSpeed(double additional_d) {
		bool successSpeed = false;

		
		if (isSafeEmpty() == true) {
			successSpeed = false;
		}
		else {
			speedOfTrain += additional_d;
			if (speedOfTrain > MAX_SPEED) {
				speedOfTrain = MAX_SPEED;
			}
			else if(speedOfTrain < 0){
				speedOfTrain = 0;
			}

			successSpeed = true;
		}
		

		return successSpeed;
	}

	int transfer(Train &first, Train &second) {

		int trainTransfer = -1;


		if (first.isSafeEmpty() == true || second.isSafeEmpty() == true) {
			trainTransfer = -1;
		}
		else {
			auto passengersFirst = first.getNumberOfPeople();
			auto passengersSecond = second.getNumberOfPeople();

			first.loadPeople(passengersSecond);

			trainTransfer = first.getNumberOfPeople() - passengersFirst;
			second.loadPeople(-trainTransfer);

		
		}

		

		return trainTransfer;
		
	}


}