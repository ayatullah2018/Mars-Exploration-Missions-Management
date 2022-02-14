#include "MarsStation.h"
#include <stdlib.h>     
#include <time.h>       


static int IDcounter = 0;
MarsStation::MarsStation()
{
	srand(time(NULL));


}
bool MarsStation::readingFile()
{
	myFile.open(("MarsSecretINfo.txt"));

	if (!myFile)
	{
		UI1.errorReadingFile();
		return false;
	}

	//rover inputs
	myFile >> numofEmergencyRovers;
	constantNumofER = numofEmergencyRovers;

	cout<< numofEmergencyRovers <<endl;

	
	myFile >> numofmountanousRovers;
	constantNumofMR = numofmountanousRovers;

	cout << numofmountanousRovers << endl;


	myFile >> numofPolarRovers;
	constantNumofPR = numofPolarRovers;

	cout << numofPolarRovers << endl;

	myFile >> EnumOFmissionsTillCheckup;
	cout << EnumOFmissionsTillCheckup << endl;

	myFile >> MnumOFmissionsTillCheckup;
	cout << MnumOFmissionsTillCheckup << endl;

	myFile >> PnumOFmissionsTillCheckup;
	cout << PnumOFmissionsTillCheckup << endl;

	myFile >> checkup_duration;
	cout << checkup_duration << endl;

	for (int i = 0; i < numofEmergencyRovers; i++)
	{
		myFile >> EmergencyRoversSpeed;
		cout << EmergencyRoversSpeed << endl;

		storing_emergency_rovers(EmergencyRoversSpeed);
	}

	for (int i = 0; i < numofmountanousRovers; i++)
	{
		myFile >> mountanousRoversSpeed;
		cout << mountanousRoversSpeed << endl;

		storing_mountanous_rovers(mountanousRoversSpeed);
	}


	for (int i = 0; i < numofPolarRovers; i++)
	{
		myFile >> PolarRoversSpeed;
		cout << PolarRoversSpeed << endl;

		storing_polar_rovers(PolarRoversSpeed);
	}






	//mission inputs
	myFile >> autoP;
	cout << autoP << endl;
	myFile >> numOfEvents;
	cout << numOfEvents << endl;
	int i = 0;
	while (i< numOfEvents)
	{
		myFile >> eventType;
		cout << eventType << endl;

		if (eventType == 'F')
		{
			    myFile >> missionType;
				cout << missionType << endl;


				myFile >> eventDay;
				myFile >> ID;
				myFile >> targetLocation;
				myFile >> missionDuration;
				myFile >> significance;
	           FormulationEvent* fevent = new FormulationEvent(missionType, ID, eventDay, targetLocation, missionDuration, significance);
			   formulationeventlist.enqueue(fevent, eventDay);
			   if (missionType == "E")
				   constantNumofEM++;
			   else if (missionType == "M")
				   constantNumofMM++;

			   else if (missionType == "P")
				   constantNumofPM++;

		}

		else if(eventType == 'P')
		{

			myFile >> eventDay;
			myFile >> ID;
			PromotionEvent* event1 = new PromotionEvent(ID, eventDay);
			promotioneventlist.enqueue(event1, eventDay);

		}
		else if (eventType == 'X')
		{
			myFile >> eventDay;
			myFile >> ID;
			CancellationEvent* event2 = new CancellationEvent(ID, eventDay);
			cancellationlist.enqueue(event2, eventDay);
		}
		i++;
	}

	

	return true;
}

bool MarsStation::writintToFile2()
{
	int totalWaitingDays = 0;
	int totalexcutionDays = 0;
	double avg_excution = 0;
	double avg_waiting = 0;


	Mission* mission = new Mission(0, 0, 0, 0, 0);
	myFile2.open(("MarsReport.txt"));

	if (!myFile2)
	{
		UI1.errorReadingFile();
		return false;
	}
	myFile2 << "Completion day" << "               " << "ID" << "                 " << "Formulation Day" << "       " << "Waiting DayS" << "          " << "Excution DayS \n";
	while (!completedMissions.isEmpty())
	{
		completedMissions.dequeue(mission);
		totalexcutionDays = totalexcutionDays + mission->get_numofexcutiondays();
		totalWaitingDays = totalWaitingDays + mission->get_waitingDays();
		myFile2 << mission->getFinalexcutionDays() << "                           " << mission->getID() << "                      " << mission->getformulationDay() << "                      ";
		myFile2 << mission->get_waitingDays() << "                      " << mission->get_numofexcutiondays() << "\n";
		mission = new Mission(0, 0, 0, 0, 0);
	}
	
	myFile2 << "...............................................................\n";
	myFile2 << "................................................................\n";
	myFile2 << "Missions:" << " " << constantNumofEM + constantNumofMM + constantNumofPM;
	myFile2 << "[" << "M:" << constantNumofMM << ",P:" << constantNumofPM << ",E:" << constantNumofEM << "]" << "\n";

	myFile2 << "Rovers:" << " " << constantNumofER + constantNumofMR + constantNumofPR;
	myFile2 << "[" << "M:" << constantNumofMR << ",P:" << constantNumofPR << ",E:" << constantNumofER << "]" << "\n";
	avg_excution = (double)totalexcutionDays / (double)(constantNumofEM + constantNumofMM + constantNumofPM);
	avg_waiting= (double)totalWaitingDays/ (double)(constantNumofEM + constantNumofMM + constantNumofPM);
	myFile2 << "Avg waiting days=" << avg_waiting <<"," << "Avg excution days=" << avg_excution << "\n";
	myFile2 << " auto promotion mountanous missions percentage=" << ((double)autopromotionStatistics / (double)constantNumofMM) * 100 << "%";
	myFile2.close();
	return true;
}

void MarsStation::storing_emergency_rovers(double EmergencyRoversSpeed)
{
	
	
	EmergencyRovers* rover = nullptr;
	
	
		rover = new EmergencyRovers(checkup_duration, EmergencyRoversSpeed, EnumOFmissionsTillCheckup);
		IDcounter++;
		rover->setID(IDcounter);
		EmergencyQ.enqueue(rover, -1* EmergencyRoversSpeed);
		ID_WaitingE_Rover.InsertEnd(rover->getID());
	

}
void MarsStation::storing_mountanous_rovers(double mountanousRoversSpeed)
{
	MountainousRovers* rover = nullptr;
	

		rover = new MountainousRovers(checkup_duration, mountanousRoversSpeed, MnumOFmissionsTillCheckup);
		IDcounter++;
		rover->setID(IDcounter);
		MountainousQ.enqueue(rover, -1* mountanousRoversSpeed);

		ID_WaitingM_Rover.InsertEnd(rover->getID());
		


}
void MarsStation::storing_polar_rovers(double PolarRoversSpeed)
{

	PolarRovers* rover = nullptr;
	for (int i = 0; i < numofPolarRovers; i++)
	{
		rover = new PolarRovers(checkup_duration, PolarRoversSpeed, PnumOFmissionsTillCheckup);
		IDcounter++;
		rover->setID(IDcounter);
		PolarQ.enqueue(rover, -1* PolarRoversSpeed);

		ID_WaitingP_Rover.InsertEnd(rover->getID());

	}

}
bool MarsStation::EnqueueEmergency(EmergencyRovers* rover)
{
	EmergencyQ.enqueue(rover,-1*(rover->get_speed()) );
	return true;
}

bool MarsStation::dequeueEmergency(EmergencyRovers* &rover)
{
	EmergencyQ.dequeue(rover);
	return true;
}

bool MarsStation::dequeueMountanous(MountainousRovers* &rover)
{
	MountainousQ.dequeue(rover);
	return true;
}


bool MarsStation::dequeuePolar(PolarRovers*& rover)
{
	PolarQ.dequeue(rover);
	return true;
}

bool MarsStation::Enqueue_excution(Rover* rover, int priority)
{
	InexcutionRovers.enqueue(rover, priority);
	return true;
}
bool MarsStation::dequeue_excution(Rover*& rover)
{
	InexcutionRovers.dequeue(rover);
	return true;
}
void MarsStation::MupdatingWaitingDays()
{
	Node<MountanousMission*>* headM = Waiting_MMissions.getHead();
	while ( headM!= nullptr)
	{
		headM->getItem()->set_MwaitingDays();
		headM = headM->getNext();
	}
}

void MarsStation::AcallOfpromotion(int currentDay)
{
	int count1=Waiting_MMissions.getCount();
	Node<MountanousMission*>* item;
	for (int i = 0; i < count1; i++) //looping over the the linked list items to check the waitingDays 
	{
		item = Waiting_MMissions.Return_kth_data(i); //returning the item with the i th mission 
		if (item->getItem()->get_MwaitingDays() == autoP)
		{
			autopromotionStatistics++;
			cout << "autopromotionStatistics" << autopromotionStatistics << endl;
			cout << (autopromotionStatistics / constantNumofMM) * 100 << endl;
			cout << "i am promoted guys can you see" << item->getItem()->getID() <<endl;
			PromotionEvent* event = new PromotionEvent(item->getItem()->getID(), currentDay);
			event->Excute(Waiting_EMissions, Waiting_MMissions, Waiting_PMissions);
			numofEmergencymissions++;
			numofMountanousMission--;
			ID_WaitingE_Mission.InsertEnd(event->getID());
			ID_WaitingM_Mission.DeleteNode(event->getID());

		}
	}
		
}
bool MarsStation::movementOverEmergency()
{
	int flag=0;
	EmergencyMission* tempMMission = new EmergencyMission(0, 0, 0, 0, 0);
	MountainousRovers* tempRover = new MountainousRovers(0, 0, 0);
	EmergencyRovers* EtempRover = new EmergencyRovers(0, 0, 0);
	PolarRovers* PtempRover = new PolarRovers(0, 0, 0);


	double roverSpeed = 0;

	Waiting_EMissions.dequeue(tempMMission); // getting the first mission 
	numofEmergencymissions--;
	

	
	
	if (!EmergencyQ.isEmpty())
	{
		flag = 1;
		
		dequeueEmergency(EtempRover);
		numofEmergencyRovers--;
		str1 = str1.append(",ER");
		str2 = to_string(EtempRover->getID());
		str1 = str1.append(str2);
		str1 = str1.append("--->");

		ID_WaitingE_Rover.DeleteNode(EtempRover->getID()); //deleting the rover Id from the waiting Ids list
		roverSpeed = EtempRover->get_speed();
		EtempRover->computingdayOfCompletion(tempMMission, currentday); // calculating the final excution day of a rover
		cout << "here is emergency mission"<<tempMMission->getID() <<"excution day" << EtempRover->get_dayOfCompletion() << endl;
		
	}
	else if (!MountainousQ.isEmpty())

	{
		flag = 2;
		dequeueMountanous(tempRover);// getting the first rover of mountanous if exists
		numofmountanousRovers--;
		str1 = str1.append(",MR");
		str2 = to_string(tempRover->getID());
		str1 = str1.append(str2);
		str1 = str1.append("--->");
		ID_WaitingM_Rover.DeleteNode(tempRover->getID());
		roverSpeed = tempRover->get_speed();
		tempRover->computingdayOfCompletion(tempMMission, currentday); // calculating the final excution day of a rover
		cout << "here is emergency mission" << tempMMission->getID() << " excution day" << tempRover->get_dayOfCompletion() << endl;
		
	}
	else if(!PolarQ.isEmpty())
	{
		flag = 3;
		PolarQ.dequeue(PtempRover);// getting the first rover of mountanous if exists
		numofPolarRovers--;
		str1 = str1.append(",PR");
		str2 = to_string(PtempRover->getID());
		str1 = str1.append(str2);
		str1 = str1.append("--->");

		ID_WaitingP_Rover.DeleteNode(PtempRover->getID());

		roverSpeed = PtempRover->get_speed();
		PtempRover->computingdayOfCompletion(tempMMission, currentday); // calculating the final excution day of a rover
		cout << "here is emergency mission " << tempMMission->getID() << "excution day" << PtempRover->get_dayOfCompletion() << endl;

	}
	else 
	{
		return false;
	}

	tempMMission->setfinalexcutionDays(roverSpeed, currentday);// calculating the final excution day of a mission 
	//cout << "honaaa el id" << tempMMission->getID() << endl;
	str2 = to_string(tempMMission->getID());
	str1 = str1.append(str2);



	if (flag==1)
	{
		Rover* rover1 = EtempRover;
		Enqueue_excution(rover1, rover1->get_dayOfCompletion()); //inputing the rover in the inexcution queue
		NumOFinExcutionEmergencyRover++;
	}
	else if (flag==2)
	{
		Rover* rover2 = tempRover;
		Enqueue_excution(rover2, rover2->get_dayOfCompletion()); //inputing the rover in the inexcution queue
		NumOFinExcutionMountanousRover ++ ;
	}
	else if (flag == 3)
	{
		Rover* rover2 = PtempRover;
		Enqueue_excution(rover2, rover2->get_dayOfCompletion()); //inputing the rover in the inexcution queue
		NumOFinExcutionPolarRover++;
	}
	else
	{
		return false;
	}
	Mission* mission1 = tempMMission;
	InexcutionMissions.enqueue(mission1, mission1->getFinalexcutionDays()); // inputing the mission in the inexcution queue
	NumOF_Inexcution_EmergencyMission++;
	ID_InexcutionE_Mission.InsertEnd(mission1->getID());
	ID_WaitingE_Mission.DeleteNode(mission1->getID());

	return true;
}
void MarsStation::movementOverbigmission()
{
	BigMission* tempMMission = new BigMission(0, 0, 0, 0, 0);
	MountainousRovers* MtempRover = new MountainousRovers(0, 0, 0);
	EmergencyRovers* EtempRover = new EmergencyRovers(0, 0, 0);
	PolarRovers* PtempRover = new PolarRovers(0, 0, 0);
	double roverSpeed = 0;
	if (!MountainousQ.isEmpty())
	{
		dequeueMountanous(MtempRover);// getting the first rover of mountanous if exists
		numofmountanousRovers--;

		str1 = str1.append(",MR");
		str2 = to_string(MtempRover->getID());
		str1 = str1.append(str2);
		str1 = str1.append("--->");

		ID_WaitingM_Rover.DeleteNode(MtempRover->getID());

		roverSpeed = MtempRover->get_speed();
		MtempRover->computingdayOfCompletion(tempMMission, currentday);
	}
	 if (!PolarQ.isEmpty())
	{
		
		PolarQ.dequeue(PtempRover);// getting the first rover of mountanous if exists
		numofPolarRovers--;
		str1 = str1.append(",PR");
		str2 = to_string(PtempRover->getID());
		str1 = str1.append(str2);
		str1 = str1.append("--->");

		ID_WaitingP_Rover.DeleteNode(PtempRover->getID());

		roverSpeed = PtempRover->get_speed();
		PtempRover->computingdayOfCompletion(tempMMission, currentday); // calculating the final excution day of a rover
		cout << tempMMission->getID() << "excution day" << PtempRover->get_dayOfCompletion() << endl;

	}
	 if (!EmergencyQ.isEmpty())
	 {
		

		 dequeueEmergency(EtempRover);
		 numofEmergencyRovers--;
		 str1 = str1.append(",ER");
		 str2 = to_string(EtempRover->getID());
		 str1 = str1.append(str2);
		 str1 = str1.append("--->");

		 ID_WaitingE_Rover.DeleteNode(EtempRover->getID()); //deleting the rover Id from the waiting Ids list
		 roverSpeed = EtempRover->get_speed();
		 EtempRover->computingdayOfCompletion(tempMMission, currentday); // calculating the final excution day of a rover
		 cout << tempMMission->getID() << "excution day" << EtempRover->get_dayOfCompletion() << endl;

	 }
	 tempMMission->setfinalexcutionDays(roverSpeed, currentday);
	 str2 = to_string(tempMMission->getID());
	 str1 = str1.append(str2);
	 Rover* rover1 = EtempRover;
	 Enqueue_excution(rover1, rover1->get_dayOfCompletion()); //inputing the rover in the inexcution queue
	 NumOFinExcutionEmergencyRover++;
	 Rover* rover2 = MtempRover;
	 Enqueue_excution(rover2, rover2->get_dayOfCompletion()); //inputing the rover in the inexcution queue
	 NumOFinExcutionMountanousRover++;
	 Rover* rover3 = PtempRover;
	 Enqueue_excution(rover3, rover3->get_dayOfCompletion()); //inputing the rover in the inexcution queue
	 NumOFinExcutionPolarRover++;
	 Mission* mission1 = tempMMission;
	 InexcutionMissions.enqueue(mission1, mission1->getFinalexcutionDays()); // inputing the mission in the inexcution queue
	 NumOF_Inexcution_EmergencyMission++;
	 ID_InexcutionE_Mission.InsertEnd(mission1->getID());
	 ID_WaitingE_Mission.DeleteNode(mission1->getID());

}
bool MarsStation::movementOverMountanous()
{
	bool flag;
	MountanousMission* tempMMission = new MountanousMission(0, 0, 0, 0, 0);
	MountainousRovers* tempRover = new MountainousRovers(0, 0, 0);
	EmergencyRovers* EtempRover = new EmergencyRovers(0, 0, 0);
	

	double roverSpeed=0;

	Waiting_MMissions.getbeg(tempMMission); // getting the first mission 
	numofMountanousMission--;

	if (!MountainousQ.isEmpty())
	{
		flag = 1;
	dequeueMountanous(tempRover);// getting the first rover of mountanous if exists
	numofmountanousRovers--;

	str1 = str1.append(",MR");
	str2 = to_string(tempRover->getID());
	str1 = str1.append(str2);
	str1 = str1.append("--->");

	ID_WaitingM_Rover.DeleteNode(tempRover->getID());

	roverSpeed = tempRover->get_speed();
	tempRover->computingdayOfCompletion(tempMMission, currentday); // calculating the final excution day of a rover
	cout << "here is mountanous mission " << tempMMission->getID() << "excution day" << tempRover->get_dayOfCompletion() << endl;
	}
	else if(!EmergencyQ.isEmpty() && Waiting_EMissions.isEmpty())
	
	{
		flag = 0;
		dequeueEmergency(EtempRover);
		numofEmergencyRovers--;

		str1 = str1.append(",ER");
		str2 = to_string(EtempRover->getID());
		str1 = str1.append(str2);
		str1 = str1.append("--->");

		ID_WaitingE_Rover.DeleteNode(EtempRover->getID());


		roverSpeed = EtempRover->get_speed();
		EtempRover->computingdayOfCompletion(tempMMission, currentday); // calculating the final excution day of a rover
		cout << "here is mountanous mission" << tempMMission->getID() << " excution day" << EtempRover->get_dayOfCompletion() << endl;
	}
	else
	{
		return false;
	}
	 
	tempMMission->setfinalexcutionDays(roverSpeed, currentday);// calculating the final excution day of a mission 
	str2 = to_string(tempMMission->getID());
	str1 = str1.append(str2);

	
	
	if (flag)
	{
		Rover* rover1 = tempRover;
		Enqueue_excution(rover1, rover1->get_dayOfCompletion()); //inputing the rover in the inexcution queue
		NumOFinExcutionMountanousRover++;
	}
	else if (!flag)
	{
		Rover* rover2 = EtempRover;
		Enqueue_excution(rover2, rover2->get_dayOfCompletion()); //inputing the rover in the inexcution queue
		NumOFinExcutionEmergencyRover++;
	}
	else
	{
		return false;
	}
	Mission* mission1 = tempMMission;
	InexcutionMissions.enqueue(mission1, mission1->getFinalexcutionDays()); // inputing the mission in the inexcution queue
	NumOF_Inexcution_MountanousMission++;
	ID_InexcutionM_Mission.InsertEnd(mission1->getID());
	ID_WaitingM_Mission.DeleteNode(mission1->getID());

	return true;
}
void MarsStation::movementOverPolar()
{
	PolarMission* tempPMission = new PolarMission(0, 0, 0, 0, 0);
	Waiting_PMissions.dequeue(tempPMission); // getting the first mission 
	numofPolarMission--;
	PolarRovers* tempRover = new PolarRovers(0, 0, 0);
	PolarQ.dequeue(tempRover);// getting the first rover
	numofPolarRovers--;

	str1 = str1.append(",PR");
	str2 = to_string(tempRover->getID());
	str1 = str1.append(str2);
	str1 = str1.append("--->");

	ID_WaitingP_Rover.DeleteNode(tempRover->getID());

	double roverSpeed = tempRover->get_speed();
	tempPMission->setfinalexcutionDays(roverSpeed, currentday);// calculating the final excution day of a mission 
	str2 = to_string(tempPMission->getID());
	str1 = str1.append(str2);

	tempRover->computingdayOfCompletion(tempPMission, currentday); // calculating the final excution day of a rover

	Mission* mission1 = tempPMission;
	Rover* rover1 = tempRover;

	Enqueue_excution(rover1, rover1->get_dayOfCompletion()); //inputing the rover in the inexcution queue
	NumOFinExcutionPolarRover++;
	InexcutionMissions.enqueue(mission1, mission1->getFinalexcutionDays()); // inputing the mission in the inexcution queue
	NumOF_Inexcution_PolarMission++;
	ID_InexcutionP_Mission.InsertEnd(mission1->getID());
	ID_WaitingP_Mission.DeleteNode(mission1->getID());

	cout << "here is polar mission " << tempPMission->getID() << "excution day" << tempRover->get_dayOfCompletion() << endl;
	
}
void MarsStation::movmentToCompletedMissions(int currentDay)
{
	Mission* mission = nullptr;
	mission=new Mission(0, 0, 0, 0, 0);

	InexcutionMissions.peek(mission);
	EmergencyMission* detectedEMission=nullptr ;
	MountanousMission* detectedMMission=nullptr;
	PolarMission* detectedPMission=nullptr;
	while ((mission->getFinalexcutionDays() ==  currentDay))//when the excution days end, the completed list should be filled
	{
		InexcutionMissions.dequeue(mission);
		detectedEMission = dynamic_cast<EmergencyMission*>(mission);
		detectedMMission = dynamic_cast<MountanousMission*>(mission);
		detectedPMission = dynamic_cast<PolarMission*>(mission);
		//dynamic casting to know which missionQ type i should count in the statistics
		if (detectedEMission != nullptr)
		{
			NumOFcompletedEmergencyMission++;
			cout << "emergency Mission completed " << endl;
			ID_InexcutionE_Mission.DeleteNode(detectedEMission->getID());

			
			int My_ID= detectedEMission->getID();
			ostringstream str1;
			str1 << My_ID;
			string myid = str1.str();
			ID_Completed_Mission.InsertEnd("[");
			ID_Completed_Mission.InsertEnd(myid);
			ID_Completed_Mission.InsertEnd("]");
			
			
			
		}
		else if (detectedMMission != nullptr)
		{
			NumOFcompletedMountanousMission++;
			cout << "mountanous Mission completed" << endl;
			ID_InexcutionM_Mission.DeleteNode(detectedMMission->getID());


			int My_ID = detectedMMission->getID();
			ostringstream str1;
			str1 << My_ID;
			string myid = str1.str();
			ID_Completed_Mission.InsertEnd(myid);
		} 
		else if (detectedPMission != nullptr)
		{
			NumOFcompletedPolarMission++;
			cout << "Polar Mission completed" << endl;
			ID_InexcutionP_Mission.DeleteNode(detectedPMission->getID());

			int My_ID = detectedPMission->getID();
			ostringstream str1;
			str1 << My_ID;
			string myid = str1.str();
			ID_Completed_Mission.InsertEnd("(");
			ID_Completed_Mission.InsertEnd(myid);
			ID_Completed_Mission.InsertEnd(")");
		}

		completedMissions.enqueue(mission);
		mission = new Mission(0, 0, 0, 0, 0);
		InexcutionMissions.peek(mission);
		
	}

}

void MarsStation::returnToWaitingRovers(int currentDay)
{
	Rover* rover = new Rover(0, 0, 0);
	InexcutionRovers.peek(rover);
	EmergencyRovers* ERover = nullptr;
	MountainousRovers* MRpver= nullptr;
	PolarRovers* PRover= nullptr;
	while (rover->get_dayOfCompletion()== currentDay)
	{
		InexcutionRovers.dequeue(rover);
		rover->updateRoverMissionRecord();
		ERover = dynamic_cast<EmergencyRovers*>(rover);
		MRpver = dynamic_cast<MountainousRovers*>(rover);
		PRover = dynamic_cast<PolarRovers*>(rover);
		// dynamic cast to know that which Qtype of rovers i should return my rover to 

		if (ERover != nullptr)
		{
			if (ERover->checkRoverMissionRecord())
			{
				ERover->computefinalCheckupDay(currentDay);
				EmergencyQ_checkup.enqueue(ERover, ERover->get_finalCheckupDay());
			}
			else
			{
				EmergencyQ.enqueue(ERover, -1* ERover->get_speed());
				numofEmergencyRovers++;
				ID_WaitingE_Rover.InsertEnd(ERover->getID());

			}
		}

		else if (MRpver != nullptr)
		{
			if (MRpver->checkRoverMissionRecord())
			{
				MRpver->computefinalCheckupDay(currentDay);
				MountainousQ_checkup.enqueue(MRpver, MRpver->get_finalCheckupDay());
			}
		    else
		     {
			MountainousQ.enqueue(MRpver, -1*MRpver->get_speed());
			numofmountanousRovers++;
			ID_WaitingM_Rover.InsertEnd(MRpver->getID());

		     }
		}
		else if (PRover != nullptr)
		{
			if (PRover->checkRoverMissionRecord())
			{
				PRover->computefinalCheckupDay(currentDay);
				PolarQ_checkup.enqueue(PRover, PRover->get_finalCheckupDay());
			}
		else
		{
			PolarQ.enqueue(PRover, - 1 * PRover->get_speed());
			numofPolarRovers++;
			ID_WaitingP_Rover.InsertEnd(PRover->getID());

		}
		}
		  rover = new Rover(0, 0, 0);
		InexcutionRovers.peek(rover);
	}
		
		
}
void MarsStation::returnMaintainedRovertoWaitingRovers(int currentDay)
{
	EmergencyRovers* ERover = new EmergencyRovers(0, 0, 0);
	MountainousRovers* MRpver = new MountainousRovers(0, 0, 0);
	PolarRovers* PRover = new PolarRovers(0, 0, 0);
	EmaintainedRovers.peek(ERover);
	MmaintainedRovers.peek(MRpver);
	PmaintainedRovers.peek(PRover);

	while (ERover->get_finalmaintainanceDay() == currentDay)
	{
		EmaintainedRovers.dequeue(ERover);
		EmergencyQ.enqueue(ERover, -1 * ERover->get_speed());
		cout << "eRover is back" << ERover->getID() << endl;
		numofEmergencyRovers++;
		ID_WaitingE_Rover.InsertEnd(ERover->getID());
		ERover = new EmergencyRovers(0, 0, 0);
		EmergencyQ_checkup.peek(ERover);
	}
	while (MRpver->get_finalmaintainanceDay() == currentDay)
	{
		MmaintainedRovers.dequeue(MRpver);
		MountainousQ.enqueue(MRpver, -1 * MRpver->get_speed());
		cout << "MRover is back" << MRpver->getID() << endl;

		numofmountanousRovers++;
		ID_WaitingM_Rover.InsertEnd(MRpver->getID());
		MRpver = new MountainousRovers(0, 0, 0);
		MountainousQ_checkup.peek(MRpver);
	}
	while (PRover->get_finalmaintainanceDay() == currentDay)
	{
		PmaintainedRovers.dequeue(PRover);
		PolarQ.enqueue(PRover, -1 * PRover->get_speed());
		cout << "PRover is back" << PRover->getID() << endl;

		numofPolarRovers++;
		ID_WaitingP_Rover.InsertEnd(PRover->getID());
		PRover = new PolarRovers(0, 0, 0);
		PolarQ_checkup.peek(PRover);

	}

}
void MarsStation::returnCheckedUProverTOWaitingRovers(int currentDay)
{
	EmergencyRovers* ERover = new EmergencyRovers(0,0,0);
	MountainousRovers* MRpver = new MountainousRovers(0, 0, 0);
	PolarRovers* PRover = new PolarRovers(0, 0, 0);
	EmergencyQ_checkup.peek(ERover);
	MountainousQ_checkup.peek(MRpver);
	PolarQ_checkup.peek(PRover);
	while (ERover->get_finalCheckupDay() == currentDay)
	{
		EmergencyQ_checkup.dequeue(ERover);
		ERover->set_RoverMissionRecord(0);

		maintainancedescision = rand() % 10 + 1;
		if (maintainancedescision > 1)
		{
			ERover->set_finalmaintainanceDay(currentDay);
			EmaintainedRovers.enqueue(ERover, ERover->get_finalmaintainanceDay());
			cout << "E maint" << maintainancedescision<<"//rover id"<< ERover->getID() << "///finalday=" << ERover->get_finalmaintainanceDay() << endl;

		}
		
		else
		{
			EmergencyQ.enqueue(ERover, -1 * ERover->get_speed());
			numofEmergencyRovers++;
			ID_WaitingE_Rover.InsertEnd(ERover->getID());
		}
			ERover = new EmergencyRovers(0, 0, 0);
			EmergencyQ_checkup.peek(ERover);
		
	}
	while (MRpver->get_finalCheckupDay() == currentDay)
	{
		MountainousQ_checkup.dequeue(MRpver);
		MRpver->set_RoverMissionRecord(0);

		maintainancedescision = rand() % 10 + 1;
		if (maintainancedescision > 1)
		{
			MRpver->set_finalmaintainanceDay(currentDay);
			MmaintainedRovers.enqueue(MRpver, ERover->get_finalmaintainanceDay());
			cout << "m maint" << maintainancedescision << "//rover id" << MRpver->getID() << "///finalday=" << MRpver->get_finalmaintainanceDay() << endl;

		}
		else 
		{

			MountainousQ.enqueue(MRpver, -1 * MRpver->get_speed());
			numofmountanousRovers++;
			ID_WaitingM_Rover.InsertEnd(MRpver->getID());

		}
		MRpver = new MountainousRovers(0, 0, 0);
		MountainousQ_checkup.peek(MRpver);
	}
	while (PRover->get_finalCheckupDay() == currentDay)
	{
		PolarQ_checkup.dequeue(PRover);
		PRover->set_RoverMissionRecord(0);

		maintainancedescision = rand() % 10 + 1;
		if (maintainancedescision > 1)
		{
			PRover->set_finalmaintainanceDay(currentDay);
			PmaintainedRovers.enqueue(PRover, PRover->get_finalmaintainanceDay());
			cout << "p maint" << maintainancedescision << "//rover id" << PRover->getID() << "///finalday=" << PRover->get_finalmaintainanceDay() << endl;

		}
		else

		{
			PolarQ.enqueue(PRover, -1 * PRover->get_speed());
			numofPolarRovers++;
			ID_WaitingP_Rover.InsertEnd(PRover->getID());
		}
		PRover = new PolarRovers(0, 0, 0);
		PolarQ_checkup.peek(PRover);
	}
}

bool MarsStation::exit_project() // the project exits when all the missions are in the completed list
{
	
	if (Waiting_EMissions.isEmpty())
		if (Waiting_MMissions.isempty())
			if (Waiting_PMissions.isEmpty()) 
				if(InexcutionMissions.isEmpty())
					if(formulationeventlist.isEmpty())
			{
				//cout << " no more updates for toady" << endl;
				return true;
			}
            else
				return false;

}
bool MarsStation::consoleOutput()
{
	UI1.print_current_day(currentday);
	UI1.output_availableRovers(numofEmergencyRovers, numofmountanousRovers, numofPolarRovers);
	UI1.ID_availableRovers(ID_WaitingE_Rover, ID_WaitingM_Rover, ID_WaitingP_Rover);
	UI1.output_waitingMissions(numofEmergencymissions, numofMountanousMission, numofPolarMission);
	UI1.ID_waitingMissions(ID_WaitingE_Mission, ID_WaitingM_Mission, ID_WaitingP_Mission);
	UI1.ID_inexcutionMissions(ID_InexcutionE_Mission, ID_InexcutionM_Mission, ID_InexcutionP_Mission);
	UI1.output_completedMissions(NumOFcompletedEmergencyMission, NumOFcompletedMountanousMission, NumOFcompletedPolarMission);
	UI1.ID_completedMissions(ID_Completed_Mission);
	UI1.specificMissionTOrover(str1);
	UI1.dachprint();
	return true;
}
void  MarsStation::maintainanceroversIndemand()
{
	MountainousRovers* tempRover = new MountainousRovers(0, 0, 0);
	EmergencyRovers* EtempRover = new EmergencyRovers(0, 0, 0);
	PolarRovers* PtempRover = new PolarRovers(0, 0, 0);
	int x = rand() % 3 + 1;
	if (x == 1&& !EmaintainedRovers.isEmpty())
	{
		EmaintainedRovers.dequeue(EtempRover);

		EtempRover->setSpeed(EtempRover->get_speed() - 10);
		EmergencyQ.enqueue(EtempRover, EtempRover->get_speed());
		ID_WaitingE_Rover.InsertEnd(EtempRover->getID());
		numofEmergencyRovers++;

	}
	else if (x == 2&& !MmaintainedRovers.isEmpty())
	{
		MmaintainedRovers.dequeue(tempRover);

		tempRover->setSpeed(tempRover->get_speed() - 10);
		MountainousQ.enqueue(tempRover, tempRover->get_speed());
		ID_WaitingM_Rover.InsertEnd(tempRover->getID());
		numofmountanousRovers++;

	}
	else if (x == 3 && !PmaintainedRovers.isEmpty())
	{
		PmaintainedRovers.dequeue(PtempRover);
		PtempRover->setSpeed(PtempRover->get_speed() - 10);
		PolarQ.enqueue(PtempRover, PtempRover->get_speed());
		ID_WaitingP_Rover.InsertEnd(PtempRover->getID());
		numofPolarRovers++;

	}

}
void MarsStation::checkingforevents(int currentDay)
{
	FormulationEvent* event = new FormulationEvent("none", 0, 0, 0, 0, 0);
	PromotionEvent* event2 = new PromotionEvent(0, 0);
	CancellationEvent* event3 = new CancellationEvent(0, 0);
	formulationeventlist.peek(event);
	promotioneventlist.peek(event2);
	cancellationlist.peek(event3);
	while (event->GetEday() == currentDay)
	{
		formulationeventlist.dequeue(event);
		event->Excute(Waiting_EMissions, Waiting_MMissions, Waiting_PMissions);

		if (event->get_Type() == "E")
		{
			numofEmergencymissions++;
			ID_WaitingE_Mission.InsertEnd(event->get_id());

		 }
		else if (event->get_Type() == "M")
		{
			numofMountanousMission++;
			ID_WaitingM_Mission.InsertEnd(event->get_id());

		}
		else if (event->get_Type() == "P")
		{
			numofPolarMission++;
			ID_WaitingP_Mission.InsertEnd(event->get_id());

		}
		event = new FormulationEvent("none", 0, 0, 0, 0, 0);
		formulationeventlist.peek(event);
	}

	while (event2->GetEday() == currentDay)
	{
		promotioneventlist.dequeue(event2);
		event2->Excute(Waiting_EMissions, Waiting_MMissions, Waiting_PMissions);
		numofEmergencymissions++;
		numofMountanousMission--;
		ID_WaitingE_Mission.InsertEnd(event2->getID());
		ID_WaitingM_Mission.DeleteNode(event2->getID());

		event2 = new PromotionEvent(0, 0);
		promotioneventlist.peek(event2);

	}
	while (event3->GetEday() == currentDay)
	{
		cancellationlist.dequeue(event3);
		event3->Excute(Waiting_EMissions, Waiting_MMissions, Waiting_PMissions);
		numofMountanousMission--;
		ID_WaitingM_Mission.DeleteNode(event3->getID());
		event3 = new CancellationEvent(0, 0);
		cancellationlist.peek(event3);
	}
}

void MarsStation::AbstractSimulation()
{
	
	currentday = currentday++;
	checkingforevents(currentday);
	while (!EmergencyQ.isEmpty() || !MountainousQ.isEmpty() || !PolarQ.isEmpty())
	{
		if (!Waiting_EMissions.isEmpty())
		{

			movementOverEmergency();

		}
		else
			break;
	}
	
	while (!EmergencyQ.isEmpty() || !MountainousQ.isEmpty())// checking iff the waiting mountanous missions are available or not
	{
		
		if (!Waiting_MMissions.isempty())
		{
			

			movementOverMountanous();

		}
		else break;
	}
	
	while (!Waiting_PMissions.isEmpty())
	{
		if (!PolarQ.isEmpty())
		{
			movementOverPolar();
		}
		else
			break;
	}

	movmentToCompletedMissions(currentday);
	returnToWaitingRovers(currentday); // return the inexcutionrovers to waiting or checkup lists
	returnCheckedUProverTOWaitingRovers(currentday); //or returnint rovers to maintainance
	returnMaintainedRovertoWaitingRovers(currentday);
	MupdatingWaitingDays();
	AcallOfpromotion(currentday);
	if (EmergencyQ.isEmpty() && MountainousQ.isEmpty() && PolarQ.isEmpty() && !Waiting_EMissions.isEmpty())
	{
		maintainancelistUnlockCounter++;
		if (maintainancelistUnlockCounter == maxmaintanancetoUnlock)
		{
			maintainanceroversIndemand();
			maintainancelistUnlockCounter = 0;
		}
	}
}
bool MarsStation::simulation()
{
	PROG_MODE MOOD= UI1.input_ProgramMode();
	readingFile();
	
	 switch (MOOD)
	 {
	 case Inter_MODE:
		 
		 while (!exit_project())
		 {
			 AbstractSimulation();
			 consoleOutput();
			 UI1.waitForUser( );
		}
		 break;
	 case STEP_MODE:	
		 while (!exit_project())
		 {
			 AbstractSimulation();
			 consoleOutput();
			 UI1.sleep(1000);

		 }

		 break;
	 case SILENT_MODE:
		 while (!exit_project())
		 {
			 AbstractSimulation();
			 UI1.sleep(1000);
		 }
		 break;
	 default:
		 break;
	 }
	
	 writintToFile2();
	return true;
}