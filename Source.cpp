



#include <iostream>
#include <conio.h>
#include <cstdlib>
#include "MarsStation.h"
#include<string.h>

using namespace std;


//logic of our program:  the next mission can be assigned only at the day after the day of returning the rover to it's waiting list. 


int main()
{
    
   MarsStation station1;
    station1.simulation();
    
    
    
    return 0;
}









/*
int waitSecond = 10; /// number of second to wait for user input.
while (1)
{

    if (_kbhit())
    {
        cin >> a;
        cout << a << "is the value";
        break;
    }

    Sleep(1000); //sleep for 1 sec;
    --waitSecond;

    if (waitSecond == 0)   // wait complete.
        break;
}
*/