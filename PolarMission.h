#pragma once
#include"Mission.h"
class PolarMission :public Mission
{

public:
	PolarMission(int ID, int formulationDay, double targetLocation, double missionDuration, int significance);
	
	~PolarMission();
};
