#pragma once


enum PROG_MODE	//Program Interface modes
{
	Inter_MODE=1,	//interactive mode
	STEP_MODE=2,	//Step-by-step mode
	SILENT_MODE=3,	//Silent mode

};

enum MISSION_TYPE	    //types of orders
{
	TYPE_EMERG,	      //Emergency Mission
	TYPE_MOUNT,	     //Mountanious Mission
	TYPE_POLR,	    //Polar Mission
	TYPE_UNDEF,

};

enum MISSION_STATUS	   //The mission status
{
	WAIT,	          //Waiting Mission
	IN_EXC,	         //In-Excution Mission
	COMP,	        //Completed Mission 

};

enum ROVER_TYPE
{
	T_EMERG,
	T_MOUNT,
	T_POLR,
};