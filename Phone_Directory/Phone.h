/*
Name: Lwin Yonal Mateo Lopez
Email: lymateo-lopez@myseneca.ca
Student ID: 134710201
Date: 01-22-2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/

#ifndef PHONE_H
#define PHONE_H

struct Person
{
	char name[51]; // 50 characters plus 1 for null terminator
	char areaCode[4]; // 3 characters plus 1 for null terminator
	char prefix[4]; // 3 characters plus 1 for null terminator
	char number[5]; // 4 characters plus 1 for null terminator

};

namespace sdds
{
	// runs the phone directory appication
	void phoneDir(const char* programTitle, const char* fileName);
}

#endif