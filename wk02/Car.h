/*
Name: Lwin Yonal Mateo Lopez
Email: lymateo-lopez@myseneca.ca
Student ID: 134710201
Date: 01-26-2022

*/

#ifndef SDDS_CAR_H
#define SDDS_CAR_H


namespace sdds
{
	struct Car
	{
		char license_plate[9]{}; // 8 characters plus 1 for null terminator
		char* make_and_model{}; // dynamically allocated memory
		int time{};
	};

	void VBPLE_Title();

	void initialize(int allocSize);

	void deallocate(Car& C);

	bool read(Car& C);

	void print(const Car& C);

	void record(const Car& C);

	void endOfDay();

}

#endif
