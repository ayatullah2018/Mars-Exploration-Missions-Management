#include "Rover.h"



Rover::Rover(double check_duration, double speed, int numOFmissionsTillCheckup)
{
	
	id = 0;
	this->checkup_duration = check_duration;
	this->speed = speed;
	this->numOFmissionsTillCheckup = numOFmissionsTillCheckup;
	this->dayOfCompletion = 0;
	
	RoverMissionRecord = 0;
	finalCheckupDay = 0;
}
void Rover::setSpeed(int s)
{
	this->speed = s;
}
void Rover::set_finalmaintainanceDay(int currentDay)
{
	finalmaintainanceDay = 5 + currentDay; //considering that each rover should stay in the maintainace for 5 days if needed to get maintained
}
int Rover::get_finalmaintainanceDay()
{
	return finalmaintainanceDay;
}

int Rover::get_finalCheckupDay()
{
	return finalCheckupDay;
}
void  Rover::computefinalCheckupDay(int currentDay)
{
	finalCheckupDay = currentDay + checkup_duration;
}
void Rover::setID(int id)
{
	this->id = id;
}
int Rover::getID()
{
	return id;
}

int Rover::get_checkupduration()
{
	return checkup_duration;
}

int Rover::get_speed()
{
	return speed;
}
void Rover::computingdayOfCompletion(Mission* assignedMission, int currentDay)
{
	dayOfCompletion =( 2 * (assignedMission->get_targetLocation() / speed)/25) + (assignedMission->get_missionDuration()) + currentDay;
	
	
}
int Rover::get_dayOfCompletion()
{
	return dayOfCompletion;
}
void Rover::updateRoverMissionRecord()
{
	RoverMissionRecord++;
}
bool Rover::checkRoverMissionRecord()
{
	if (RoverMissionRecord == numOFmissionsTillCheckup)
		return true;
	else
		return false;
}
void Rover::set_finalCheckupDay(int x)
{
	finalCheckupDay = 0;
}
void Rover::set_RoverMissionRecord(int x)
{
	RoverMissionRecord = 0;
}
 Rover::~Rover()
{


}