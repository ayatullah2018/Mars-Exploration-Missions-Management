#pragma once
#include "Rover.h"

using namespace std;

class EmergencyRovers : public Rover
{

public:
	EmergencyRovers(double check_duration, double speed, int EnumOFmissionsTillCheckup);
	~EmergencyRovers()
	{

	};
};