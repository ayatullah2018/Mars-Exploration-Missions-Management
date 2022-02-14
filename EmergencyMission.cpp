#include "EmergencyMission.h"


EmergencyMission::EmergencyMission(int ID, int formulationDay, double targetLocation, double missionDuration, int significance):Mission(ID, formulationDay, targetLocation, missionDuration, significance)
{

	priority = 1000-(5 * significance + 3 * targetLocation + 2 * missionDuration);

}
int EmergencyMission::getPeriority()
{
	return priority;
}
void EmergencyMission::set_Periority()
{
	priority = 1000 - (5 * get_significance() + 3 * get_targetLocation() + 2 * get_missionDuration());
}
EmergencyMission::~EmergencyMission()
{

}