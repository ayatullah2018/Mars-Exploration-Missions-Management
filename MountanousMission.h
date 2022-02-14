#pragma once
#include"Mission.h"
class MountanousMission :public Mission
{
private:
	int mwaitingDays;

public:
	MountanousMission(int ID, int formulationDay, double targetLocation, double missionDuration, int significance);
	~MountanousMission();
	void set_MwaitingDays();
	int get_MwaitingDays();
};