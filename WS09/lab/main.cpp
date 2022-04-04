/*
Name: Lwin Yonal Mateo Lopez
Email: lymateo-lopez@myseneca.ca
Student ID: 134710201
Date: 03-30-2022
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <iostream>
#include <fstream>
#include "HtmlText.h"
#include "Text.h"
using namespace std;
using namespace sdds;
void show(Text T)  {
   cout << "*" << T << "*" << endl;
}
void saveHtml(HtmlText H) {
   ofstream("dcwrLittle.html")<<H;
}
void displayFile(const char* filename) {
   cout << "File: " << filename << endl;
   cout << "==================================================" << endl;
   ifstream fin(filename);
   char ch = 0;
   while (fin.get(ch)) {
      cout << ch;
   }
   cout << endl << "==================================================" << endl;
}
int main() {
   Text T;
   Text Y;
   Text Z;
   ifstream test("test.txt");
   ifstream dcwrLittle("dcwrLittle.txt");
   test >> T;
   dcwrLittle >> Y;
   Y = T;
   Z = Y;
   show(Y);
   HtmlText H1("Derived Classes and Resources");
   HtmlText H2;
   HtmlText H3;
   dcwrLittle.seekg(0);
   dcwrLittle >> H1;
   dcwrLittle.seekg(0);
   dcwrLittle >> H2;
   H2 = H1;
   H3 = H2;
   saveHtml(H3);
   displayFile("dcwrLittle.html");
   return 0;
}