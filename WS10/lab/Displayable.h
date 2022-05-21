/*
Name: Lwin Yonal Mateo Lopez
Email: lymateo-lopez@myseneca.ca
Student ID: 134710201
Date: 04-13-2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_DISPLAYABLE_H_
#define SDDS_DISPLAYABLE_H_
#include <iostream>
namespace sdds{
  class Displayable{
  public:
    virtual std::ostream& display(std::ostream& os)const = 0;
  };

  std::ostream& operator<<(std::ostream& os, const Displayable& D);
}

#endif
