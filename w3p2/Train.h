/*
Name: Lwin Yonal Mateo Lopez
Email: lymateo-lopez@myseneca.ca
Student ID: 134710201
Date: 02-06-2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/


#ifndef SDDS_TRAIN_H_
#define SDDS_TRAIN_H_

const int MAX_NAME_LEN = 20;

const int MAX_PEOPLE = 1000;

const double MAX_SPEED = 320;

namespace sdds
{
	class Train
	{
	private:
		char nameOfTrain[MAX_NAME_LEN + 1]{};
		int NumOfPpleOnTrain{};
		double speedOfTrain{};
	public:
		void set(const char* name, int numPeople, double speed); // it is a mutator that can change current instance
		int getNumberOfPeople() const;// const-prevents changes to current changes
		const char* getName() const;
		double getSpeed() const;
		bool isSafeEmpty() const;
		void display() const;

		// add number of people
		bool loadPeople(int additional);

		// add number of spead of the train
		bool changeSpeed(double additional_d);
		
	};



	// global function
	int transfer(Train &first, Train &second);
}

#endif // !SDDS_TRAIN_H_




