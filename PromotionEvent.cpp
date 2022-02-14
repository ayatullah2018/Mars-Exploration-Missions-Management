#include"PromotionEvent.h"
#include<iostream>
#include<string>
#include"Node.h"
using namespace std;




PromotionEvent::PromotionEvent(int ID, int EDay) :Event(EDay)
{
	
	this->ID = ID;
	this->Eday = EDay;

}
int PromotionEvent::getID()
{
	return ID;
}

void PromotionEvent::Excute(PriorityQueue<EmergencyMission*>& Waiting_EMissions, LinkedList<MountanousMission*>& Waiting_MMissions, LinkedQueue<PolarMission*>& Waiting_PMissions)
{
	if (Waiting_MMissions.Find1(ID))
	{
		EmergencyMission* Emission = new EmergencyMission(0, 0, 0, 0, 0);
		
		Node<MountanousMission*>* item = Waiting_MMissions.ExtractNode(ID);

			{
				cout << "yaaaaaaaaaay" << endl;
				Emission->setID(item->getItem()->getID());
				Emission->setformulationDay(item->getItem()->getformulationDay());
				Emission->set_targetLocation(item->getItem()->get_targetLocation());
				Emission->set_missionDuration(item->getItem()->get_missionDuration());
				Emission->set_significance(item->getItem()->get_significance());
				Emission->set_Periority();
				Waiting_EMissions.enqueue(Emission, Emission->getPeriority());
			}
		}

	}
	





