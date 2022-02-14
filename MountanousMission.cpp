#include "MountanousMission.h"


MountanousMission::MountanousMission(int ID, int formulationDay, double targetLocation, double missionDuration, int significance):Mission(ID, formulationDay, targetLocation, missionDuration, significance)
{
	mwaitingDays = 0;
}
MountanousMission:: ~MountanousMission()
{

}
void MountanousMission::set_MwaitingDays()
{
	mwaitingDays++;
}
int  MountanousMission::get_MwaitingDays()
{
	return mwaitingDays;
}