#pragma once
#include "Event.h"



class PromotionEvent : public Event
{
private:
	int ID;
	int Eday;
public:
	int getID();
	PromotionEvent(int ID, int EDay);
	void Excute(PriorityQueue<EmergencyMission*>& Waiting_EMissions, LinkedList<MountanousMission*>& Waiting_MMissions, LinkedQueue<PolarMission*>& Waiting_PMissions) override;

};