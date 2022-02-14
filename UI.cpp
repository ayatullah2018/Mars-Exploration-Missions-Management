#include "UI.h"
#include <Windows.h>

UI::UI()
{

}
void  UI::errorReadingFile()
{
    cout << "error cannot open MarsSecretINfo file " << endl;

}
void UI::specificMissionTOrover(string x)
{
    cout << x << endl;

}
void UI::sleep(int milliseconds)
{
    Sleep(milliseconds);
}
PROG_MODE UI::input_ProgramMode()
{

    cout << "please specify the MOOd of preference" << endl;
    PROG_MODE MOOD;
    cout << "for Inter_MODE enter 1, for STEP_MODE enter 2, for SILENT_MODE enter 3 " << endl;
    int num;
    cin >> num;
    MOOD = (PROG_MODE)num;
    switch (MOOD)
    {
    case(Inter_MODE):
        cout << " Inter_MODE Mood 1:  Start The mission " << endl;
        break;
    case(STEP_MODE):
        cout << " STEP_MODE Mood 2:  Start The mission " << endl;
        break;

    case (SILENT_MODE):
        cout << " SILENT_MODE Mood 3:  Start The mission " << endl;
        break;

    }
    return MOOD;
}
void UI::output_availableRovers(int emergency_R, int mountanous_R, int polar_R)
{
    cout << "                " << "                  number of waiting Rovers is:" << endl;
    cout << "                " << "1-emergency Rovers" << "  " << emergency_R << endl;
	cout << "                " << "2-mountanous Rovers" << "  " << mountanous_R << endl;
	cout << "                " << "3-polar Rovers" << "  " << polar_R << endl;
}
void UI::output_waitingMissions(int emergency_M, int mountanous_M, int polar_M)
{
    cout << "                " << "                "  <<" number of waiting Missions is:" << endl;
    cout << "                " << "1-emergency Missions" << "  " << emergency_M << endl;
    cout << "                " << "2-mountanous Missions" << "  " << mountanous_M << endl;
    cout << "                " << "3-polar Missions" << "  " << polar_M << endl;
}
void UI::ID_waitingMissions(LinkedList<int>ID_WaitingE_Mission, LinkedList<int>ID_WaitingM_Mission, LinkedList<int>ID_WaitingP_Mission)
{

    cout << "                                " << "  Waiting Missions are:" << endl;
    int counter = 1;
    cout << "                                ";
    while (counter <= ID_WaitingE_Mission.getCount())
    {
        cout << "[";
        ID_WaitingE_Mission.PrintKth(counter);
        cout << "]" << " ";

        counter++;
    }
    counter = 1;
    while (counter <= ID_WaitingM_Mission.getCount())
    {
        cout << "  ";
        ID_WaitingM_Mission.PrintKth(counter);
        cout << "  " << " ";

        counter++;
    }
    counter = 1;
    while (counter <= ID_WaitingP_Mission.getCount())
    {
        cout << "(";
        ID_WaitingP_Mission.PrintKth(counter);
        cout << ")" << " ";

        counter++;
    }
    cout << endl;

}
void UI::ID_inexcutionMissions(LinkedList<int>ID_InexcutionE_Mission, LinkedList<int>ID_InexcutionM_Mission, LinkedList<int>ID_InexcutionP_Mission)
{
    cout << "                                " << " Inexcution Missions :" << endl;
    int counter = 1;
    cout << "                                ";
    while (counter<=ID_InexcutionE_Mission.getCount())
    {
        cout << "[";
        ID_InexcutionE_Mission.PrintKth(counter);
        cout << "]"<<" ";
         
        counter++;
    }
    counter = 1;
    while (counter <= ID_InexcutionM_Mission.getCount())
    {
        cout << "  ";
        ID_InexcutionM_Mission.PrintKth(counter);
        cout << "  " << " ";

        counter++;
    }
    counter = 1;
    while (counter <= ID_InexcutionP_Mission.getCount())
    {
        cout << "(";
        ID_InexcutionP_Mission.PrintKth(counter);
        cout << ")" << " ";

        counter++;
    }
    cout << endl;
}
void  UI::output_completedMissions(int emergency_M, int mountanous_M, int polar_M)
{
    int totalsum = emergency_M + mountanous_M + polar_M;
    cout << "                " << "                     total number of completed missions till now=" << " " << totalsum <<endl;
    cout << "                " << "1-emergency missions" << "  " << emergency_M << endl;
    cout << "                " << "2-mountanous missions" << "  " << mountanous_M << endl;
    cout << "                " << "3-polar missions" << "  " << polar_M << endl;

}
void UI::ID_completedMissions(LinkedList<string>ID_Completed_Mission)
{
    cout << endl;
    cout << "                   ";
    ID_Completed_Mission.PrintList();
    cout << endl;
}
void UI::waitForUser()
{
    int userResponse;
    cout << endl;
     
    cin >> userResponse;

}
void UI::print_current_day(int currentday)
{
    cout << "current day is:" << "     "<< currentday <<endl;
    
}
void UI::ID_availableRovers(LinkedList<int>ID_WaitingE_Rover, LinkedList<int>ID_WaitingM_Rover, LinkedList<int>ID_WaitingP_Rover)
{
    cout << "                                " << "  Waiting Rovers are:" << endl;
    int counter = 1;
    cout << "                                ";
    while (counter <= ID_WaitingE_Rover.getCount())
    {
        cout << "[";
        ID_WaitingE_Rover.PrintKth(counter);
        cout << "]" << " ";

        counter++;
    }
    counter = 1;
    while (counter <= ID_WaitingM_Rover.getCount())
    {
        cout << "  ";
        ID_WaitingM_Rover.PrintKth(counter);
        cout << "  " << " ";

        counter++;
    }
    counter = 1;
    while (counter <= ID_WaitingP_Rover.getCount())
    {
        cout << "(";
        ID_WaitingP_Rover.PrintKth(counter);
        cout << ")" << " ";

        counter++;
    }
    cout << endl;
}
void UI::dachprint()
{
    cout << "--------------------------------" << endl;
}