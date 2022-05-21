/*
Name: Lwin Yonal Mateo Lopez
Email: lymateo-lopez@myseneca.ca
Student ID: 134710201
Date: 04-13-2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "Displayable.h"
namespace sdds{
  std::ostream& operator<<(std::ostream& os, const Displayable& D){
    return D.display(os);
  }
}