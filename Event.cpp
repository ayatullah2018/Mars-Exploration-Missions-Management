#include"Event.h"


Event::Event(int eDAY)
{
	EDay = eDAY;
}

int Event::GetEday()
{
	return EDay;
}

void Event::SetEday(int eDAY)
{
	EDay = eDAY;
}

Event::~Event()
{

}