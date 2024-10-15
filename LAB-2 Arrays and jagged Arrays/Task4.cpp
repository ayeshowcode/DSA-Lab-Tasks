#include <iostream>
using namespace std;
int main()
{
    int deps = 4;
    double **departments = new double *[deps];
    int SE = 3;
    int AI = 4;
    int CS = 2;
    int DS = 1;
    departments[0] = new double[SE]{2.33, 2.67, 3.67};
    departments[1] = new double[AI]{3.67, 3.33, 3.67, 4.0};
    departments[2] = new double[CS]{3.0, 2.33};
    departments[3] = new double[DS]{2.33};

    cout << "---------------------------" << endl;
    cout << "SOFTWARE ENGINEERING" << endl;
    for (int i = 0; i < SE; i++)
        cout << departments[0][i] << "    ";
    cout << endl;
    cout << "---------------------------" << endl;

    cout << "ARTIFICIAL INTELLIGENCE" << endl;

    for (int i = 0; i < AI; i++)
        cout << departments[1][i] << "    ";
    cout << endl;
    cout << "---------------------------" << endl;

    cout << "COMPUTER SCIENCE" << endl;
    for (int i = 0; i < CS; i++)
        cout << departments[2][i] << "    ";
    cout << endl;
    cout << "---------------------------" << endl;

    cout << "DATA SCIENCE" << endl;
    for (int i = 0; i < DS; i++)
        cout << departments[3][i] << "    ";
    cout << endl;
    cout << "---------------------------" << endl;
}