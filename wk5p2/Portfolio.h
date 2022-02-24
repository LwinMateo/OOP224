/*
Name: Lwin Yonal Mateo Lopez
Email: lymateo-lopez@myseneca.ca
Student ID: 134710201
Date: 02-17-2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/

#ifndef SDDS_Portfolio_H_
#define SDDS_Portfolio_H_
#include <iostream>
#include <string>

namespace sdds
{

    class Portfolio
    {
        double m_value = 0;
        char m_stock[16];
        char m_type;

    public:

        Portfolio();

        void emptyPortfolio();
   
        Portfolio(double value, const char* stock, char type);

        void dispPortfolio() const;

        std::ostream& display() const; 



        // operator and conversion overloads
        operator double() const;
        operator const char* () const;
        operator char() const;
        operator bool() const;

        Portfolio& operator+=(double addValue);
        Portfolio& operator-=(double subtractValue);

        bool operator ~() const;

        Portfolio& operator<<(Portfolio& otherPortfolio);
        Portfolio& operator>>(Portfolio& otherPortfolio);
    };

    double operator+(const Portfolio& left, const Portfolio& right);
    double operator+=(double& num, const Portfolio& right);
}
#endif // SDDS_Portfolio_H_
