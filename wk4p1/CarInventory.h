/*
Name: Lwin Yonal Mateo Lopez
Email: lymateo-lopez@myseneca.ca
Student ID: 134710201
Date: 02-09-2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/

#ifndef SDDS_CAR_INVENTORY_H
#define SDDS_CAR_INVENTORY_H

namespace sdds
{
	class CarInventory
	{
		private:
			char* m_type{};
			char* m_brand{};
			char* m_model{};
			int m_year;
			int m_code;
			double m_price;

		public:
			CarInventory();
			CarInventory(const char* type, const char* brand, const char* model, int year = 2022, int code = 100, double price = 1);
			~CarInventory();
			void resetInfo();
			CarInventory& setInfo(const char* type, const char* brand, const char* model, int year, int code, double price);
			void printInfo() const;
			bool isValid() const;
			bool isSimilarTo(const CarInventory& car) const;
		
	};

	bool find_similar(CarInventory car[], const int num_cars);
}

#endif