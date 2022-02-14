#pragma once
#include "Rover.h"

class PolarRovers : public Rover
{

public:
	PolarRovers(double check_duration, double speed, int PnumOFmissionsTillCheckup);
	~PolarRovers()

	{

	};
};