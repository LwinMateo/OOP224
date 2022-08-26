#ifndef SDDS_CAR_H
#define SDDS_CAR_H
#include "RaceCar.h"
namespace sdds
{
	class Car
	{
		char* m_carModel{};
		int m_maximum_speed = 0;
	public:
		Car(const char* carModel, int max_speed);

		// Rule of Three
		Car(const Car& other);
		Car& operator=(const Car& other);
		~Car();

		std::ostream& display(std::ostream& ostr) const;
	};

}

#endif

