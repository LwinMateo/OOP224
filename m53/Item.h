/*
Name: Lwin Yonal Mateo Lopez
Email: lymateo-lopez@myseneca.ca
Student ID: 134710201
Date: 03-31-2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_ITEM_H
#define SDDS_ITEM_H
#include"iProduct.h"
#include "Status.h"

namespace sdds
{
	class Item : public iProduct
	{
		double m_price;
		int m_qty;
		int m_qtyNeeded;
		char* m_description{};
		bool m_linear;

	protected:
		Status m_state;
		int m_sku;
		bool linear() const;
	public:
		Item();

		// Rule of three
		Item(const Item&);
		Item& operator=(const Item&);
		~Item();


		// returns the number of products needed
		int qtyNeeded() const override;

		// retuns the quantity on hand
		int qty() const override;

		// returns the price of the produce
		operator double() const override;

		// returns if the iProduct is in a good state
		operator bool() const override;


		// to reduce the quantity on hand
		int operator-=(int qty) override;

		// to increase the quantity on hand
		int operator+=(int qty) override;

		// determines if the iProduct is displayed in a linear format or 
		// descriptive format
		void linear(bool isLinear);

		// PUBLIC MODIFIER
		void clear();


		// return true if the sku is a match to the iProduct's sku
		bool operator==(int sku)const override;

		// rtrns true if the description is found in the iPorduct's description
		bool operator==(const char* description)const override;




		// saves the iProduct into a file
		std::ofstream& save(std::ofstream& ofstr)const override;

		// loads an iProduct from a file
		std::ifstream& load(std::ifstream& ifstr) override;

		// displays the iProduct on the screen
		std::ostream& display(std::ostream& ostr)const override;

		// reads the iProduct from the console
		std::istream& read(std::istream& istr) override;


		// to read the Stock-Keeping Unit from console before
		// main data entry
		int readSku(std::istream& istr) override;



	};
}

#endif // !SDDS_ITEM_H
