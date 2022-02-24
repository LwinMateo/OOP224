/*
Name: Lwin Yonal Mateo Lopez
Email: lymateo-lopez@myseneca.ca
Student ID: 134710201
Date: 02-16-2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/

#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include "Portfolio.h"

using namespace std;
namespace sdds
{


    Portfolio::Portfolio() {
        emptyPortfolio();
    }

    void Portfolio::emptyPortfolio()
    {
        m_value = 0;
        m_stock[0] = 0;
        m_type = 'E';
    }
    Portfolio::Portfolio(double value, const char* stock, char type) {
        emptyPortfolio();
        if (value >= 0 && (type == 'V' || type == 'G' || type == 'I')) {
            m_value = value;
            m_type = type;
            strcpy(m_stock, stock);
        }
    }

    void Portfolio::dispPortfolio() const {
        cout << " ";
        cout.width(10);
        cout << (const char*)(*this);
        cout << " | ";
        cout << "Value: ";
        cout.width(10);
        cout << double(*this);
        cout << " | ";
        cout << " Type: ";
        cout << char(*this);
    }
    std::ostream& Portfolio::display() const {

        if (~*this) {
            cout << " Portfolio  |  Bad-NG |";
            dispPortfolio();
        }
        else if (*this) {
            cout << " Portfolio  |  Active |";
            dispPortfolio();

        }
        else {
            cout << " Portfolio  |  EMPTY  |";
            dispPortfolio();
        }
        return cout;
    }


    Portfolio::operator double() const {
        return m_value;
    }

    Portfolio::operator const char* () const {
        return m_stock;
    }

    Portfolio::operator char() const {
        return m_type;
    }

    Portfolio::operator bool() const {
        return m_type == 'G' || m_type == 'V' || m_type == 'I';
    }

    Portfolio& Portfolio::operator+=(double addValue) {
        if (m_value > 0 && addValue > 0) {
            m_value += addValue;
        }

        return *this;
    }

    Portfolio& Portfolio::operator-=(double subtractValue) {
        if (m_value > 0 && subtractValue > 0) {
            m_value -= subtractValue;
        }

        return *this;
    }

    bool Portfolio::operator ~() const {
        return m_value < 0;
    }

    Portfolio& Portfolio::operator<<(Portfolio& otherPortfolio) {

        if (this && otherPortfolio) {
            m_value += otherPortfolio.m_value;

            otherPortfolio.emptyPortfolio();
        }

        return *this;
    }

    Portfolio& Portfolio::operator>>(Portfolio& otherPortfolio) {
        otherPortfolio << *this;
        return *this;
    }

    double operator+(const Portfolio& left, const Portfolio& right) {

        double result = 0;

        if (left && right) {
            result = double(left) + double(right);
        }
        else {
            result = 0;
        }

        return result;

    }

    double operator+=(double& num, const Portfolio& right) {
        num += double(right);

        return num;
    }
}