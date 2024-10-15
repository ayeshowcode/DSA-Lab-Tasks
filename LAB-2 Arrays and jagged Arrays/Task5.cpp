#include <iostream>
using namespace std;
int main()
{
    int rows = 5;
    string **seatingChart = new string *[rows];
    seatingChart[0] = new string[4];
    seatingChart[1] = new string[3];
    seatingChart[2] = new string[2];
    seatingChart[3] = new string[5];
    seatingChart[4] = new string[1];

    cout << "Enter the name of the attendees in the first row" << endl;
    for (int i = 0; i < 4; i++)
        cin >> seatingChart[0][i];

    cout << "Enter the name of the attendees in the second row" << endl;
    for (int i = 0; i < 3; i++)
        cin >> seatingChart[1][i];

    cout << "Enter the name of the attendees in the third row" << endl;
    for (int i = 0; i < 2; i++)
        cin >> seatingChart[2][i];

    cout << "Enter the name of the attendees in the fourth row" << endl;
    for (int i = 0; i < 5; i++)
        cin >> seatingChart[3][i];

    cout << "Enter the name of the attendees in the fifth row" << endl;
    for (int i = 0; i < 1; i++)
        cin >> seatingChart[4][i];




    cout << "--------------------------------" << endl;
    cout << "--------------------------------" << endl;




    cout << "attendees in the first row" << endl;
    for (int i = 0; i < 4; i++)
        cout << seatingChart[0][i] << "    ";
    cout << endl;

    cout << "--------------------------------" << endl;
    cout << "attendees in the second row" << endl;
    for (int i = 0; i < 3; i++)
        cout << seatingChart[1][i] << "    ";
    cout << endl;

    cout << "--------------------------------" << endl;
    cout << "attendees in the third row" << endl;
    for (int i = 0; i < 2; i++)
        cout << seatingChart[2][i] << "    ";
    cout << endl;

    cout << "--------------------------------" << endl;
    cout << "attendees in the fourth row" << endl;
    for (int i = 0; i < 5; i++)
        cout << seatingChart[3][i] << "    ";
    cout << endl;

    cout << "--------------------------------" << endl;
    cout << "attendees in the fifth row" << endl;
    for (int i = 0; i < 1; i++)
        cout << seatingChart[4][i] << "    ";
    cout << endl;
    cout << "--------------------------------" << endl;
}