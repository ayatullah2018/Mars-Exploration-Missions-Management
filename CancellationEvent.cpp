#include "CancellationEvent.h"
#include<iostream>
#include<string>
using namespace std;



int CancellationEvent::getID()
{

	return id;
}

CancellationEvent::CancellationEvent(int ID, int EDay) :Event(EDay)
{
	this->id = ID;
	this->Eday = EDay;

}

void CancellationEvent::Excute(PriorityQueue<EmergencyMission*>& Waiting_EMissions, LinkedList<MountanousMission*>& Waiting_MMissions, LinkedQueue<PolarMission*>& Waiting_PMissions)
{

	if (Waiting_MMissions.Find1(id))
	{

		EmergencyMission* Emission = new EmergencyMission(0, 0, 0, 0, 0);

		Node<MountanousMission*>* item = Waiting_MMissions.ExtractNode(id);
		delete item;
		item = nullptr;


	}

	
}