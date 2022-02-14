#pragma once
#include "Event.h"
class CancellationEvent :public Event
{
private:
	int id;
	int Eday;


public:
	int getID();
	CancellationEvent(int ID, int EDAY);

	void Excute(PriorityQueue<EmergencyMission*>& Waiting_EMissions, LinkedList<MountanousMission*>& Waiting_MMissions, LinkedQueue<PolarMission*>& Waiting_PMissions) override;

};

