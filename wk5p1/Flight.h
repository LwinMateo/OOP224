/*
Name: Lwin Yonal Mateo Lopez
Email: lymateo-lopez@myseneca.ca
Student ID: 134710201
Date: 02-16-2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/

#ifndef SDDS_FLIGHT_H
#define SDDS_FLIGHT_H
#include <iostream>

namespace sdds
{

    const int Boen747Capacity = 388;
    const int FuelTankCapacity = 238840;

    class Flight
    {

        int m_passengers = 0;
        double m_fuel = 0;
        char m_title[16];
        void emptyPlane();

    public:
        Flight();
        Flight(int passengers, double fuel, const char* title);
        std::ostream& display()const;

        // to be implemented

        //TYPE CONVERSION OPERATORS
        operator bool() const;
        operator int() const;
        operator double() const;
        operator const char*() const;

        // UNARY MEMBER OPERATOR
        bool operator ~() const;

        //BINARY MEMBER OPERATORS
        
        // assignment operators (=)
        Flight& operator=(Flight& otherFlight);

        Flight& operator=(int num);

        Flight& operator=(double num);


        // assignment operators (+=)
        Flight& operator+=(double addFuel);
        Flight& operator+=(int addPassenger);

        Flight& operator-=(double reduceFuel);
        Flight& operator-=(int reducePassenger);

        //input/output operators
        Flight& operator<<(Flight& otherFlight);
        Flight& operator>>(Flight& otherFlight);

    };
    
    int operator+(const Flight& flight1, const Flight& flight2);
    int operator+=(int& initialValue, Flight& flight);
}
#endif // SDDS_FLIGHT_H