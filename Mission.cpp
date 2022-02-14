#include"Mission.h"


Mission::Mission(int ID, int eventDay, double targetLocation, double missionDuration, int significance)
{

	this->ID = ID;
	this->targetLocation = targetLocation;
	this->missionDuration = missionDuration;
	this->significance = significance;
	waitingDays =0;
	startofexcutionDays = 0;
	finalexcutionDays =0;
	formulationDay= 1;
	numofexcutiondays = 0;
}
void Mission::setstartofexcutionDays(int currentday)
{
	startofexcutionDays = currentday;
}
int Mission::get_startofexcutionDays()
{
	return startofexcutionDays;
}
int Mission::get_waitingDays()
{
	return waitingDays;
}
int Mission::getformulationDay()
{
	return formulationDay;
}
void Mission::setformulationDay(int formulationDay)
{
	this->formulationDay = formulationDay;
}
int Mission::get_numofexcutiondays()
{
	return numofexcutiondays;
}
void Mission::setfinalexcutionDays( double roverSpeed, int currentDay)
{
	finalexcutionDays = (2 * (targetLocation / roverSpeed)/25) + (missionDuration) + currentDay; //dividing by 25 as the day on mars is 25 hours to make all the units with days
	
	setstartofexcutionDays(currentDay);
	setnumofexcutiondays();
	set_waitingDays(currentDay);
}

double  Mission::get_targetLocation()
{
	return targetLocation;
}
double  Mission::get_missionDuration()
{
	return missionDuration;
}
int Mission::getFinalexcutionDays()
{

	return finalexcutionDays;
}
void Mission::set_waitingDays(int currentday) //current day here represents the assigning day
{
	waitingDays= currentday - formulationDay;

}

int Mission::getID()
{
	return ID;
}
void Mission::set_significance(int num)
{
	significance = num;
}
int Mission::get_significance()
{
	return significance;
}
void Mission::set_targetLocation(double num)
{
	targetLocation = num;
}
void Mission::set_missionDuration(double num)
{
	missionDuration = num;
}
void Mission::setID(int ID)
{
	this->ID = ID;
}
void  Mission::setnumofexcutiondays()
{
	numofexcutiondays = finalexcutionDays- startofexcutionDays;
}
Mission::~Mission()
{

}