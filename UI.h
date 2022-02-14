#pragma once
#include<iostream>
#include"Defs.h"
#include<string.h>
#include"LinkedList.h"
using namespace std;
class UI
{
public:
	UI();
	PROG_MODE input_ProgramMode();
	void errorReadingFile();
	void waitForUser();
	void print_current_day(int currentday);
	void output_availableRovers(int emergency_R, int mountanous_R, int polar_R);  //each type
	void output_waitingMissions(int emergency_M, int mountanous_M, int polar_M);  //each type
	void output_completedMissions(int emergency_M, int mountanous_M, int polar_M);//eachtype
	void specificMissionTOrover(string x);
	void ID_availableRovers(LinkedList<int>, LinkedList<int>, LinkedList<int>);
	void ID_waitingMissions(LinkedList<int>, LinkedList<int>, LinkedList<int>);
	void ID_inexcutionMissions(LinkedList<int>ID_InexcutionE_Mission, LinkedList<int>ID_InexcutionM_Mission, LinkedList<int>ID_InexcutionP_Mission);
	void ID_completedMissions(LinkedList<string>ID_Completed_Mission);
	void sleep(int milliseconds);
	void dachprint();

	// auto promotion function and file output
	//linked list destructor
	
};