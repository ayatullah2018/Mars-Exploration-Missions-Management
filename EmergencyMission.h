#pragma once
#include"Mission.h"
class EmergencyMission :public Mission
{
	int priority=0;
public:
	EmergencyMission(int ID, int formulationDay, double targetLocation, double missionDuration, int significance);
	int getPeriority();
	void set_Periority();
	~EmergencyMission();
};