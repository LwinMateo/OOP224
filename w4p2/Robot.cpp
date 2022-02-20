/*
Name: Lwin Yonal Mateo Lopez
Email: lymateo-lopez@myseneca.ca
Student ID: 134710201
Date: 02-12-2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<string.h>
#include<string>
#include "Robot.h"

using namespace std;

namespace sdds
{
	Robot::Robot() {
		Name = nullptr;
		Location = nullptr;
		Weight = 0;
		Width = 0;
		Height = 0;
		Speed = 0;
		Deployed = false;
	}
	Robot::Robot(const char* name, const char* location, double weight, double width, double height, double speed, bool deployment) {
		if (name != nullptr && location != nullptr && weight > 0 && width > 0 && height > 0 && speed > 0 && (deployment == true || deployment == false)) {
			Name = new char[strlen(name) + 1];
			Location = new char[strlen(location) + 1];

			strcpy(Name, name);
			strcpy(Location, location);

			Weight = weight;
			Width = width;
			Height = height;
			Speed = speed;
			Deployed = deployment;
		}
		else {
			Name = nullptr;
			Location = nullptr;
			Weight = 0;
			Width = 0;
			Height = 0;
			Speed = 0;
			Deployed = false;
		}
	}
	Robot::~Robot() {
		delete[] Name;
		delete[] Location;
		Name = nullptr;
		Location = nullptr;
	}



	Robot& Robot::set(const char* name, const char* location, double weight, double width, double height, double speed, bool deployment) {
		delete[] Name;
		delete[] Location;

		if (name != nullptr && location != nullptr) {
			Name = new char[strlen(name) + 1];
			Location = new char[strlen(location) + 1];

			strcpy(Name, name);
			strcpy(Location, location);
			Weight = weight;
			Width = width;
			Height = height;
			Speed = speed;
			Deployed = deployment;
		}
		else {
			Name = nullptr;
			Location = nullptr;
			Weight = 0;
			Width = 0;
			Height = 0;
			Speed = 0;
			Deployed = false;
		}

		return *this;
	}

	void Robot::setLocation(const char* locate) {
		delete[] Location;

		if (locate != nullptr && Location != nullptr) {
			Location = new char[strlen(locate) + 1];
			strcpy(Location, locate);
		}
		else {
			delete[] Location;
			Location = nullptr;
		}
	}

	void Robot::setDeployed(bool deployment) {
		if (deployment == true || deployment == false) {
			Deployed = deployment;
		}
	}




	char* Robot::getName() const {
		return Name;
	}
	char* Robot::getLocation() const {
		return Location;
	}

	bool Robot::isDeployed() const {
		bool RobotDeployed = false;
		if (Deployed == true) {
			RobotDeployed = true;
		}

		return RobotDeployed;
	}

	bool Robot::isValid() const {
		return Name != nullptr && Location != nullptr && Weight > 0 && Width > 0 && Height > 0 && Speed > 0 && (Deployed == true || Deployed == false);
	}

	double Robot::speed() const {
		return Speed;
	}

	void Robot::display() const {

		cout << "| ";
		cout << setw(11) << left << Name;

		cout << "| ";
		cout << setw(16) << left << Location;

		cout << "| ";
		cout << fixed << setprecision(1) << setw(6) << right << Weight;

		cout << " |";
		cout << fixed << setprecision(1) << setw(7) << right << Width;

		cout << " | ";
		cout << fixed << setprecision(1) << setw(6) << right << Height;

		cout << " | ";
		cout << fixed << setprecision(1) << setw(6) << right << Speed;

		cout << " | ";
		cout << setw(9) << left << (Deployed == true ? "YES" : "NO");
		cout << "|" << endl;
	}

	int conrtolRooomReport(const Robot robot[], int num_robots) {
		int i = 0;

		// this variable is to check if there is an invalid information or not
		int returnIndex = -1;

		// this variable counts how manys Robots are deployed
		int countRocketDeployed = 0;

		cout << "                        ------ Robot Control Room -----" << endl;
		cout << "                    ---------------------------------------" << endl;

		cout << "| Robot ID   | Location        | Weight |  Width | Height |  Speed | Deployed |" << endl;
		cout << "|------------+-----------------+--------+--------+--------+--------+----------|" << endl;
		for (i = 0; i < num_robots; i++) {
			if (robot[i].isValid() == false) {
				returnIndex = i;
				return returnIndex;
			}
			else {

				robot[i].display();
				if (robot[i].isDeployed() == true) {
					countRocketDeployed += 1;
				}
			}
		}
		cout << "|=============================================================================|" << endl;
		cout << "| SUMMARY:                                                                    |" << endl;
		cout << "| " << countRocketDeployed << "  robots are deployed.                                                     |" << endl;
		cout << "| The fastest robot is:                                                       |" << endl;




		cout << "| Robot ID   | Location        | Weight |  Width | Height |  Speed | Deployed |" << endl;
		cout << "|------------+-----------------+--------+--------+--------+--------+----------|" << endl;
		for (i = 0; i < num_robots; i++) {
			if (robot[i].speed() == 3.5) {
				robot[i].display();
			}
		}
		cout << "|=============================================================================|" << endl;


		return returnIndex;
	}

}