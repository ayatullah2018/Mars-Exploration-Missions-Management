#pragma once
#include "Mission.h"
class BigMission :public Mission
{

public:
	
	BigMission(int ID, int formulationDay, double targetLocation, double missionDuration, int significance);

	~BigMission();



};