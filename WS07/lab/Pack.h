/*
Name: Lwin Yonal Mateo Lopez
Email: lymateo-lopez@myseneca.ca
Student ID: 134710201
Date: 03-14-2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_PACK_H
#define SDDS_PACK_H
#include"Container.h"

namespace sdds
{
	class Pack : public Container
	{
		int unitSize;
	public:

		Pack(const char* content, int size, int unit_Size = 330, int NumOfUnits = 0);
		
		int operator+=(int Value);

		int operator-=(int Value);

		int unit() const;
		int noOfUntis() const;
		int size() const;

		Pack& clear(int packSize, int unit_Size, const char* content);

		std::ostream& print(std::ostream& os) const;
		std::istream& read(std::istream& is);
	};

	std::istream& operator>>(std::istream& is, Pack& pack);

	std::ostream& operator<<(std::ostream& os, const Pack& pack);
}

#endif // !SDDS_PACK_H
