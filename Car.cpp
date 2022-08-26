#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include<string.h>
#include "Car.h"

using namespace std;

namespace sdds
{
	Car::Car(const char* carModel, int max_speed)
	{
		int Len = strlen(carModel + 1);
		if ((carModel != nullptr && Len == 3) && (max_speed >= 50 || max_speed <= 400)) {
			delete[] this->m_carModel;
			this->m_carModel = new char[strlen(carModel) + 1];


			strcpy(this->m_carModel, carModel);

			this->m_maximum_speed = max_speed;
		}
		else {
			delete[] this->m_carModel;
			this->m_carModel = nullptr;
			this->m_maximum_speed = 0;
		}

	}

	Car::Car(const Car& other)
	{
		this->m_carModel = nullptr;
		*this = other;

	}

	Car& Car::operator=(const Car& other)
	{
		// TODO: insert return statement here
		if (this != &other) {
			delete[] this->m_carModel;
			other.m_carModel;
			this->m_carModel = new char[strlen(other.m_carModel + 1)];
			strcpy(this->m_carModel, other.m_carModel);
		}

		return *this;
	}

	Car::~Car()
	{
		delete[] this->m_carModel;
		this->m_maximum_speed = 0;
	}

	ostream& Car::display(ostream& ostr) const
	{
		
		if ((this->m_carModel == nullptr) && (this->m_maximum_speed >= 50 || this->m_maximum_speed <= 400)) {
			ostr << "Empty!\n";
		}
		else {
			ostr << "Model: " << this->m_carModel << endl;
			ostr << "Maximum Speed: " << this->m_maximum_speed << endl;
		}
	}


}