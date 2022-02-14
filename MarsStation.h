#pragma once
//we should add all other events.h , missions, rovers , UI and the data structure classes that will be used.
#include <iostream>
#include<fstream>
#include"PromotionEvent.h"
#include "PolarRovers.h"
#include "MountainousRovers.h"
#include "EmergencyRovers.h"
#include "LinkedQueues.h"
#include"LinkedList.h"
#include"PriorityQueue.h"
#include"UI.h"
#include"EmergencyMission.h"
#include"MountanousMission.h"
#include"PolarMission.h"
#include "BigMission.h"
#include"Event.h"
#include"FormulationEvent.h"
#include"PromotionEvent.h"
#include"CancellationEvent.h"
#include<string.h>
#include<sstream>
#include <conio.h>
#include <Windows.h>
#include <cstdlib>



using namespace std;

class MarsStation
{
	string str1=" ";
	string str2;
	static int counter;
	int waitSecond = 10;
	int currentday = 0;
	UI UI1;
	ifstream myFile;
	ofstream myFile2;
	int maintainancelistUnlockCounter=0;
	int maxmaintanancetoUnlock = 2;
	//rovers stuff
	int numofEmergencyRovers = 0;
	int numofmountanousRovers = 0;
	int numofPolarRovers = 0;
	double PolarRoversSpeed = 0;
	double mountanousRoversSpeed = 0;
	double EmergencyRoversSpeed = 0;
	double checkup_duration = 0;
	int EnumOFmissionsTillCheckup = 0;
	int MnumOFmissionsTillCheckup = 0;
	int PnumOFmissionsTillCheckup = 0;
	int NumOFinExcutionEmergencyRover = 0;
	int NumOFinExcutionMountanousRover = 0;
	int NumOFinExcutionPolarRover = 0;
	int maintainancedescision;

	//events stuff
	int numOfEvents = 0;
	char eventType;
	int autoP = 0;

	//events DS
	PriorityQueue<FormulationEvent*> formulationeventlist;
	PriorityQueue<PromotionEvent*> promotioneventlist;
	PriorityQueue<CancellationEvent*> cancellationlist;



	// missions stuff
	string missionType;
	int eventDay = 0;
	int ID = 0;
	double targetLocation = 0;
	double missionDuration = 0;
	int significance;

	int numofEmergencymissions = 0;
	int numofMountanousMission = 0;
	int numofPolarMission = 0;
	int NumOF_Inexcution_EmergencyMission = 0;
	int NumOF_Inexcution_MountanousMission = 0;
	int NumOF_Inexcution_PolarMission = 0;
	int NumOFcompletedEmergencyMission=0;
	int NumOFcompletedMountanousMission =0;
	int NumOFcompletedPolarMission =0;

	//statistics stuff
	 int  constantNumofER=0;
	 int constantNumofMR=0;
	 int constantNumofPR=0;

	 int constantNumofEM=0;
	 int constantNumofMM=0;
	 int constantNumofPM=0;

	 int autopromotionStatistics = 0;


	// DS of rovers
	 PriorityQueue<EmergencyRovers*> EmergencyQ;//3 waiting
	 PriorityQueue<MountainousRovers*> MountainousQ;
	 PriorityQueue<PolarRovers*> PolarQ;


	PriorityQueue<EmergencyRovers*> EmergencyQ_checkup; // 3 checkup
	PriorityQueue<MountainousRovers*> MountainousQ_checkup;
	PriorityQueue<PolarRovers*> PolarQ_checkup;

	PriorityQueue<Rover*>InexcutionRovers;

	//maintainance stuff
	PriorityQueue<EmergencyRovers*>EmaintainedRovers;
	PriorityQueue<MountainousRovers*>MmaintainedRovers;
	PriorityQueue<PolarRovers*>PmaintainedRovers;

	
	// DS of missions
	PriorityQueue<EmergencyMission*> Waiting_EMissions;
	LinkedList<MountanousMission*>	Waiting_MMissions;
	LinkedQueue<PolarMission*> Waiting_PMissions;
	LinkedQueue<PolarMission*> Waiting_BIGMissions;


	PriorityQueue<Mission*> InexcutionMissions;
	LinkedQueue<Mission*> completedMissions;



	//DS of ID rovers
	LinkedList<int>ID_WaitingE_Rover;
	LinkedList<int>ID_WaitingM_Rover;
	LinkedList<int>ID_WaitingP_Rover;

	//DS of ID Mission
	LinkedList<int>ID_WaitingE_Mission;
	LinkedList<int>ID_WaitingM_Mission;
	LinkedList<int>ID_WaitingP_Mission;

	LinkedList<int>ID_InexcutionE_Mission;
	LinkedList<int>ID_InexcutionM_Mission;
	LinkedList<int>ID_InexcutionP_Mission;

	LinkedList<string>ID_Completed_Mission;
	


public:
	MarsStation();
	bool EnqueueEmergency(EmergencyRovers* rover);
	bool dequeueEmergency(EmergencyRovers* &rover);
	bool dequeueMountanous(MountainousRovers* &rover);
	bool dequeuePolar(PolarRovers* &rover);
	bool Enqueue_excution(Rover* rover, int priority);
	bool dequeue_excution(Rover* &rover);
	void movmentToCompletedMissions(int currentDay);
	void returnToWaitingRovers(int currentDay);
	void returnCheckedUProverTOWaitingRovers(int currentDay);
	void returnMaintainedRovertoWaitingRovers(int currentDay);
	void MupdatingWaitingDays();
	
	void AcallOfpromotion(int currentDay);
	void storing_emergency_rovers(double EmergencyRoversSpeed);
	void storing_mountanous_rovers(double mountanousRoversSpeed);
	void storing_polar_rovers(double PolarRoversSpeed);

	void checkingforevents(int currentDay);
	void maintainanceroversIndemand();

	bool movementOverEmergency();
	bool movementOverMountanous();
	void movementOverPolar();
	void movementOverbigmission();


	bool consoleOutput();
	void AbstractSimulation();
	bool exit_project();
	bool readingFile();
	bool writintToFile2();
	bool simulation();

};