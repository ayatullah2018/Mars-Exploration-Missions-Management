#pragma once
#include "Event.h"

class FormulationEvent : public Event
{
private:

	int id;
	double location, duration;
	int significance;
	int Eday;
	string Type;


public:
	int get_id();
	string get_Type();
	FormulationEvent(string Type, int ID, int EDay, double TL, double M_dur, int significance);
	void Excute(PriorityQueue<EmergencyMission*> & Waiting_EMissions, LinkedList<MountanousMission*> &Waiting_MMissions, LinkedQueue<PolarMission*> &Waiting_PMissions) override;


};