/*
Name: Lwin Yonal Mateo Lopez
Email: lymateo-lopez@myseneca.ca
Student ID: 134710201
Date: 03-14-2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_CONTAINER_H
#define SDDS_CONTAINER_H

namespace sdds
{
	class Container
	{
		char Content[51];
		int Capacity;
		int Content_Volume;

	protected:
		void setEmpty();
		int capacity() const;
		int volume() const;

		
	public:
		Container(const char* content, int capacity, int contentVolume = 0);
		int operator+=(int Value);
		int operator-=(int Value);

		//conversion
		operator bool() const;

		Container& clear(int capacity, const char* description);

		std::ostream& print(std::ostream& out) const;

		std::istream& read(std::istream& in);
	};

	std::istream& operator>>(std::istream& is, Container& c);

	std::ostream& operator<<(std::ostream& os, const Container& c);
}

#endif // !SDDS_CONTAINER_H
