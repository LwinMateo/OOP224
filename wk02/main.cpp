/*
Name: Lwin Yonal Mateo Lopez
Email: lymateo-lopez@myseneca.ca
Student ID: 134710201
Date: 01-26-2022

*/

#include "Car.h"
using namespace sdds;

int main() {
    Car C;
    VBPLE_Title();
    initialize(2); // set this later to 5
    while (read(C)) {
        record(C);
    }
    endOfDay();

}
