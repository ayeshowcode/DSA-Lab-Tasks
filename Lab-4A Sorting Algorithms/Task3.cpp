#include <iostream>
using namespace std;
class ComputerDesk
{
private:
    int size;
    string *designation;
    int *desk;

public:
    ComputerDesk() {}
    void input()
    {
        cout << "Enter the no of employees: ";
        cin >> size;
        designation = new string[size];
        desk = new int[size];
        cout << "Enter the designations(CEO, CTO, CFO, VP, MGR, EMP): " << endl;
        for (int i = 0; i < size; i++)
        {
            cout << "Enter the desingation no : " << i + 1 << ": ";
            cin >> designation[i];
        }
        assign();
    }
    void assign()
    {
        int j = 0;
        for (int i = 0; i < size; i++)
        {
            if (designation[i] == "CEO")
                desk[j++] = 6;
            else if (designation[i] == "CTO")
                desk[j++] = 5;
            else if (designation[i] == "CFO")
                desk[j++] = 4;
            else if (designation[i] == "VP")
                desk[j++] = 3;
            else if (designation[i] == "MGR")
                desk[j++] = 2;
            else if (designation[i] == "EMP")
                desk[j++] = 1;
            else
            {
                cout << "inavlid input";
                break;
            }
        }
    }
    void insertionSort()
    {
        int i, j, x;
        for (int i = 1; i < size; i++)
        {
            int x = desk[i];
            string xs = designation[i];

            int j = i - 1;

            while (j > -1 && desk[j] > x)
            {
                desk[j + 1] = desk[j];
                designation[j + 1] = designation[j];
                j--;
            }
            desk[j + 1] = x;
            designation[j + 1] = xs;
        }
    }
    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << i+1 << ". " << designation[i] << endl;
        }
    }
};
int main()
{
    ComputerDesk d;

    d.input();
    cout << endl;
    cout << "ORIGNIAL" << endl;
    d.display();
    d.insertionSort();
    cout << endl;
    cout << "SORTED" << endl;
    d.display();
}