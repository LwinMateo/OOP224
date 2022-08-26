#ifndef SDDS_RACECAR_H
#define SDDS_RACECAR_H
#include "Car.h"

namespace sdds
{
	class RaceCar : public Car
	{
		char* m_TeamName{};
	public:
		RaceCar(const char* carModel, int max_speed, const char* teamName);

		// rule of three
		RaceCar(const RaceCar& other);
		RaceCar& operator=(const RaceCar& other);
		~RaceCar();

		std::ostream& display(std::ostream& ostr) const; 
	};
}

#endif