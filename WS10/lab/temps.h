/*
Name: Lwin Yonal Mateo Lopez
Email: lymateo-lopez@myseneca.ca
Student ID: 134710201
Date: 04-13-2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/


#ifndef SDDS_TEMPS_H
#define SDDS_TEMPS_H
#include<iostream>
#include "Collection.h"
#include "Car.h"

namespace sdds
{

	// a template header is declare with 'typename' with any made-up name
	template<typename type>
	

	// this function must return a Collection object of any type, that could be and integer, or any classes declared
	// this function contains two types of any objects that are for comparing which items are a match.
	Collection<type> select(const type* Object, int number, const type &Object2) {
		int matchesFound = 0;
		
		for (auto i = 0; i < number; i++) {
			if (Object[i] == Object2) {
				matchesFound++;
			}

		}

		Collection<type> returnObj(matchesFound);

		int j = 0;
		for (auto i = 0; i < number; i++) {
			if (Object[i] == Object2) {
				returnObj[j] = Object[i];
				j++;
			}
			
		}

		return returnObj;
	}



	// I retype the template that was declared previously 
	template<class type>

	// this function does not return any type, but it contain a parameter that is an object of any type
	// what I do is display every item
	void printCollection(const type& collectionObject, const char* title) {
		if (title != nullptr) {
			std::cout << title << std::endl;
		}

		int Size = collectionObject.size();

		for (auto i = 0; i < Size; i++) {
			std::cout << collectionObject[i] << std::endl;
		}

	}

}


#endif
