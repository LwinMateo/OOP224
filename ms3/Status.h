/*
Name: Lwin Yonal Mateo Lopez
Email: lymateo-lopez@myseneca.ca
Student ID: 134710201
Date: 03-24-2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_STATUS_H_
#define SDDS_STATUS_H_

namespace sdds
{
	class Status
	{
	private:
		char* Description_Status{};
		int Optional_Status_Code = 0;
	public:
		//Status();
		Status(const char* description = nullptr);

		//Rule of three
		Status(const Status&);
		Status& operator=(const Status&);
		~Status();

		// assignment operators
		Status& operator=(int addNum);
		Status& operator=(const char* newDescription);

		// type conversion Overloads
		operator int() const;
		operator const char* () const;
		operator bool() const;




		Status& clear();
	};

	std::ostream& operator<<(std::ostream& ost, const Status& status);
}

#endif // !STATUS_H_
