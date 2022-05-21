/*
Name: Lwin Yonal Mateo Lopez
Email: lymateo-lopez@myseneca.ca
Student ID: 134710201
Date: 04-08-2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <cctype>
#include<cstring>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<cstdlib>
#include "Utils.h"
using namespace std;
namespace sdds
{
    Utils ut;
    void Utils::testMode(bool testmode) {
        m_testMode = testmode;
    }
    void Utils::getSystemDate(int* year, int* mon, int* day) {
        if (m_testMode) {
            if (day) *day = sdds_testDay;
            if (mon) *mon = sdds_testMon;
            if (year) *year = sdds_testYear;
        }
        else {
            time_t t = std::time(NULL);
            tm lt = *localtime(&t);
            if (day) *day = lt.tm_mday;
            if (mon) *mon = lt.tm_mon + 1;
            if (year) *year = lt.tm_year + 1900;
        }
    }
    int Utils::daysOfMon(int month, int year)const {
        int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
        int mon = (month >= 1 && month <= 12 ? month : 13) - 1;
        return days[mon] + int((mon == 1) * ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
    }


    // RECOMMENDED FUNCTIONS

    void Utils::alocpy(char*& destination, const char* source) {
        delete[] destination;
        destination = nullptr;

        if (source != nullptr) {
            destination = new char[strlen(source) + 1];
            strcpy(destination, source);
        }
    }

    int Utils::getint(const char* prompt) {
        int Number = 0;
        bool ValidInput = false;

        if (prompt != nullptr) {
            cout << prompt;

            while (ValidInput == false) {
                cin >> Number;

                if (cin.fail() == true) {
                    cout << "Invalid Integer, retry: ";
                    cin.clear();
                    cin.ignore(123, '\n');
                }
                else {
                    ValidInput = true;
                }
            }

        }

        return Number;
    }

    int Utils::getint(int min, int max, const char* prompt, const char* errMes) {
        // Number will be use for the input the user inserts
        int Number = 0;
        bool ValidInput = false;


        while (ValidInput == false) {
            // Number will use getint() function
            Number = getint(prompt);
            if (Number >= min && Number <= max) {
                ValidInput = true;
                //return Number;
            }
            else {
                if (errMes != nullptr) {
                    cout << errMes << ", retry: ";
                    cin.clear();
                }
                else {
                    cout << "Value out of range [" << min << "<=val<=" << max << "]: ";
                }
            }
        }

        return Number;

    }



}