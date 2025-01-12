/*
Name: Lwin Yonal Mateo Lopez
Email: lymateo-lopez@myseneca.ca
Student ID: 134710201
Date: 04-13-2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_STUDENT_H_
#define SDDS_STUDENT_H_
#include "Displayable.h"
namespace sdds{

  class Student :public Displayable{
     int m_stno{};
     char m_name[41]{};
     char m_subject[7]{};
     void set(int stno, const char* name, const char* subject  );
  public:
     Student();
     Student(int stno, const char* name, const char* subject );
     std::ostream& display(std::ostream& os)const;
     bool operator==(const Student& S)const;
  };
}
#endif 