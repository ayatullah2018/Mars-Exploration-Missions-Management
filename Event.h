#pragma once
#include"EmergencyMission.h"
#include"MountanousMission.h"
#include"LinkedList.h"
#include"PriorityQueue.h"
#include"LinkedQueues.h"
#include"PolarMission.h"
#include"MountanousMission.h"
#include"EmergencyMission.h"
class Event
{
protected:
	int EDay;     //Event Day

public:

	Event(int EDAY);
	virtual ~Event();
	int GetEday();
	void SetEday(int EDAY);
	virtual void Excute(PriorityQueue<EmergencyMission*>& Waiting_EMissions, LinkedList<MountanousMission*>& Waiting_MMissions, LinkedQueue<PolarMission*>& Waiting_PMissions) = 0;


};