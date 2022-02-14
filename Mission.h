#pragma once
#include<iostream>
#include "Defs.h"

using namespace std;

class Mission
{
private:
	int ID;
	int formulationDay;
	double targetLocation;
	double missionDuration;
	int significance;
	int waitingDays;
	int startofexcutionDays;
	int finalexcutionDays; // final excution day is the day of completion
	int numofexcutiondays;

public:
	Mission(int ID, int eventDay, double targetLocation, double missionDuration, int significance);
	int get_startofexcutionDays();
	void setstartofexcutionDays(int currentday);
	void setfinalexcutionDays(double roverSpeed, int currentDay);
	void setnumofexcutiondays();
	int get_numofexcutiondays();
	void set_waitingDays(int currentday);
	void set_MwaitingDays();
	double get_targetLocation();
	void set_targetLocation(double num);
	double get_missionDuration();
	void set_missionDuration(double num);
	int getFinalexcutionDays();
	int get_waitingDays();
	int getID();
	void setID(int );
	void set_significance(int num);
	int get_significance();
	void setformulationDay(int );
	int getformulationDay();
	virtual ~Mission();
	
};