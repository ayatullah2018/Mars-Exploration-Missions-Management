#pragma once
#include "Rover.h"

class MountainousRovers : public Rover
{

public:
	MountainousRovers(double check_duration, double speed, int MnumOFmissionsTillCheckup);
	~MountainousRovers()
	{

	}; 
};