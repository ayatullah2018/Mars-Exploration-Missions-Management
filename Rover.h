#pragma once

#include<iostream>
#include"Mission.h"
using namespace std;

class Rover
{
	int id;
	int checkup_duration;
	double speed;
	int RoverMissionRecord;
	int dayOfCompletion;
	int numOFmissionsTillCheckup;
	int finalCheckupDay;



	int finalmaintainanceDay;



public:
	void setSpeed(int s);
	void set_finalmaintainanceDay(int currentDay);
	int get_finalmaintainanceDay();
	Rover(double check_duration, double speed, int numOFmissionsTillCheckup);
	int get_finalCheckupDay();
	void set_finalCheckupDay(int x);
	void set_RoverMissionRecord(int x);
	void computefinalCheckupDay(int currentDay);
	int get_checkupduration();
	int get_speed();
	void computingdayOfCompletion(Mission* assignedMission, int currentDay);
	void updateRoverMissionRecord();
	int getID();
	void setID(int id);
	int get_dayOfCompletion();
	bool checkRoverMissionRecord();
	
	virtual ~Rover();
};