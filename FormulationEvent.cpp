#include"FormulationEvent.h"
#include<iostream>
#include<string>
using namespace std;


FormulationEvent::FormulationEvent(string Type, int ID, int EDay, double TL, double M_dur, int sig) :Event(EDay)
{
	this->id = ID;
	this->location = TL;
	this->duration = M_dur;
	this->significance = sig;
	this->Eday = EDay;
	this->Type = Type;

}
int FormulationEvent::get_id()
{
	return id;
}
string FormulationEvent::get_Type()
{
	return Type;
}
void FormulationEvent::Excute(PriorityQueue<EmergencyMission*>& Waiting_EMissions, LinkedList<MountanousMission*>& Waiting_MMissions, LinkedQueue<PolarMission*>& Waiting_PMissions)

{
	if (Type == "E")
	{

		EmergencyMission* EM = new EmergencyMission(id, EDay, location, duration, significance);
		EM->set_Periority();
		Waiting_EMissions.enqueue(EM, EM->getPeriority());
		cout << "..emergency Mission formulated.. " << endl;
	}
	else if (Type == "M")
	{
		MountanousMission* MM = new MountanousMission(id, EDay, location, duration, significance);
		Waiting_MMissions.InsertEnd(MM);
		cout << "..mountanous Mission formulated.." << endl;
	}
	else if (Type == "P")
	{
		PolarMission* PM = new PolarMission(id, EDay, location, duration, significance);
		Waiting_PMissions.enqueue(PM);
		cout << "..Polar Mission formulated.." << endl;
	}

}