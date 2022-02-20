/*
Name: Lwin Yonal Mateo Lopez
Email: lymateo-lopez@myseneca.ca
Student ID: 134710201
Date: 02-12-2022

I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

*/

#ifndef SDDS_ROBOT_H
#define SDDS_ROBOT_H

namespace sdds
{
	class Robot
	{
		private:
			char* Name{};
			char* Location{};
			double Weight;
			double Width;
			double Height;
			double Speed;
			bool Deployed;
		public:
			//Constructors
			Robot();
			// Overloading constructor
			Robot(const char* name, const char* location, double weight, double width, double height, double speed, bool deployment);

			//Destructor
			~Robot();

			

			// to set to robot information (same as constructor)
			Robot& set(const char* name, const char* location, double weight, double width, double height, double speed, bool deployment);


			void setLocation(const char* locate);
			void setDeployed(bool deployment);

			char* getName() const;
			char* getLocation() const;
			bool isDeployed() const;
			bool isValid() const;
			double speed() const;

			void display() const;
	};

	int conrtolRooomReport(const Robot robot[], int num_robots);
}

#endif // !SDDS_ROBOTS_H
