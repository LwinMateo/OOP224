#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include<string.h>
#include"Car.h"
#include "RaceCar.h"

using namespace std;

namespace sdds
{
	RaceCar::RaceCar(const char* carModel, int max_speed, const char* teamName){
		Car(carModel, max_speed);
		int Len2 = strlen(teamName);
		if (teamName != nullptr && Len2 == 3) {
			delete[] m_TeamName;
			m_TeamName = new char[strlen(teamName) + 1];
			strcpy(m_TeamName, teamName);
		}
		else {
			delete[] m_TeamName;
		}
	}
	RaceCar::RaceCar(const RaceCar& other)
	{
		m_TeamName = nullptr;
		*this = other;
	}
	RaceCar& RaceCar::operator=(const RaceCar& other)
	{
		if (this != &other) {
			(&Car)*this = other;
			delete[] m_TeamName;
			m_TeamName = new char[strlen(other.m_TeamName) + 1];
			strcpy(m_TeamName, other.m_TeamName);
		}
		return *this;
	}
	RaceCar::~RaceCar()
	{
		delete[] m_TeamName;
	}

	ostream& RaceCar::display(ostream& ostr) const {
		Car::display(ostr);
		if (m_TeamName == nullptr) {
			ostr << "Empty!\n";
		}
		else {
			ostr << m_TeamName << endl;
		}
	}
}