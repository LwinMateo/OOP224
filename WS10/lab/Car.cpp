/*
Name: Lwin Yonal Mateo Lopez
Email: lymateo-lopez@myseneca.ca
Student ID: 134710201
Date: 04-13-2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Car.h"
namespace sdds{
  void Car::set(const char* plate, const char* make, const char* model){
    std::strncpy(m_plate, plate, 8);
    m_plate[8] = 0;
    std::strncpy(m_make, make, 40);
    m_make[40] = 0;;
    std::strncpy(m_model, model, 40);
    m_make[40] = 0;;
  }
  Car::Car() {
  }
  Car::Car(const char* plate, const char* make, const char* model){
    set(plate, make, model);
  }
  std::ostream& Car::display(std::ostream& os)const{
    return os << m_plate << " " << m_make << " " << m_model;
  }
  bool Car::operator==(const Car& C)const{
    return std::strcmp(m_make, C.m_make) == 0;
  }
}
