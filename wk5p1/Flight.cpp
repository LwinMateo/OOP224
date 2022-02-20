/*
Name: Lwin Yonal Mateo Lopez
Email: lymateo-lopez@myseneca.ca
Student ID: 134710201
Date: 02-16-2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Flight.h"

using namespace std;

namespace sdds
{

    void Flight::emptyPlane() {
        m_passengers = 0;
        m_fuel = 0;
        strcpy(m_title, "EmptyPlane");
    }

    // New Flight
    Flight::Flight() {
        emptyPlane();
    }
    Flight::Flight(int passengers, double fuel, const char* title) {
        emptyPlane();
        if (passengers > 0 && passengers <= Boen747Capacity && fuel >= 0 &&
            fuel <= FuelTankCapacity) {
            m_passengers = passengers;
            m_fuel = fuel;
            strcpy(m_title, title);
        }
    }
    std::ostream& Flight::display() const {

        if (*this) {
            cout << " Flight  |  Ready to Depart";
            cout << " ";
            cout.width(10);
            cout << std::string(*this);
            cout << " | ";
            cout << "Pass: ";
            cout.width(10);
            cout << int(*this);
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << double(*this);
            cout.unsetf(ios::right);
            cout << " Liters";
        }
        else if (~*this) {
            cout << " Flight  |  Empty Plane    ";
        }
        else {
            cout << " Flight  |  Low Fuel       ";
            cout << " ";
            cout.width(10);
            cout << (const char*)(*this);
            cout << " | ";
            cout << "Pass: ";
            cout.width(10);
            cout << int(*this);
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << double(*this);
            cout.unsetf(ios::right);
            cout << " Liters";
        }
        return cout;
    }


    Flight::operator bool() const {
        return m_passengers > 0 && m_fuel >= (m_passengers * 600.0);
    }

    Flight::operator int() const {
        return m_passengers;
    }

    Flight::operator double() const {
        return m_fuel;
    }

    Flight::operator const char*() const{
        return m_title;
    }

    // Unary member operator
    bool Flight::operator ~() const {
        bool state = false;

        if (m_passengers == 0) {
            state = true;
        }

        return state;
    }

    // BINARY MEMBER OPERATORS
    // assignment operators (=)
    Flight& Flight::operator=(Flight& otherFlight) {

        if (this != &otherFlight) {
            m_passengers = otherFlight.m_passengers;
            m_fuel = otherFlight.m_fuel;

            strcpy(m_title, otherFlight.m_title);

            otherFlight.emptyPlane();
        }

       
        return *this;
    }

    Flight& Flight::operator=(int num) {
        if (num > 0 && num <= Boen747Capacity) {
            m_passengers = num;
        }

        return *this;
    }

    Flight& Flight::operator=(double num) {
        if (num > 0 && num <= FuelTankCapacity) {
            m_fuel = num;
        }

        return *this;
    }

    Flight& Flight::operator+=(double addFuel) {

        if (addFuel > 0 && m_fuel < FuelTankCapacity) {
            m_fuel += addFuel;
            if (m_fuel > FuelTankCapacity) {
                m_fuel = FuelTankCapacity;
            }
        }

        return *this;
    }

    Flight& Flight::operator+=(int addPassenger) {
        if (addPassenger > 0 && m_passengers < Boen747Capacity) {
        
            m_passengers += addPassenger;

            if (m_passengers > Boen747Capacity) {
                m_passengers = Boen747Capacity;
            }
        }

        return *this;
    }

    Flight& Flight::operator-=(double reduceFuel) {
        if (reduceFuel > 0) {
            m_fuel -= reduceFuel;
            if (m_fuel < 0) {
                m_fuel = 0;
            }
        }

        return *this;
    }

    Flight& Flight::operator-=(int reducePassenger) {
        if (reducePassenger > 0) {

            m_passengers -= reducePassenger;

            if (m_passengers < 0) {
                m_passengers = 0;
            }
        }

        return *this;
    }

    Flight& Flight::operator<<(Flight& otherFlight) {
        

        m_passengers += otherFlight.m_passengers;
        if (m_passengers > Boen747Capacity) {
            otherFlight.m_passengers = this->m_passengers - Boen747Capacity;
            m_passengers = Boen747Capacity;
        }
        else {
            otherFlight.m_passengers = 0;
        }

   

        return *this;
    }

    Flight& Flight::operator>>(Flight& otherFlight) {
        
        otherFlight << *this;

        return *this;
    }

    int operator+(const Flight& flight1, const Flight& flight2) {
        int sumPassengerFlights = 0;

        if (bool(flight1) && bool(flight2)) {
            sumPassengerFlights = int(flight1)  + int(flight2);
        }
      

        return sumPassengerFlights;
    }

    int operator+=(int& initialValue, Flight& flight) {
        
        initialValue += int(flight);

        return initialValue;

    }
}