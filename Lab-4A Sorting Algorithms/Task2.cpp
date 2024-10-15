#include <iostream>
using namespace std;
class Date
{
private:
    int date;
    int month;
    int year;

public:
    void setDate(int date)
    {
        this->date = date;
    }
    int getDate()
    {
        return date;
    }
    void setMonth(int month)
    {
        this->month = month;
    }
    int getMonth()
    {
        return month;
    }
    void setYear(int year)
    {
        this->year = year;
    }
    int getYear()
    {
        return year;
    }
    void swap(int *year1, int *year2)
    {
        int temp = *year1;
        *year1 = *year2;
        *year2 = temp;
    }
    void selectionSort(Date A[], int n)
    {
        int i, j, k;
        for (i = 0; i < n - 1; i++)
        {
            for (j = k = i; j < n; j++)
            {
                if (A[j].year < A[k].year)
                    k = j;
            }
            swap(&A[i].year, &A[k].year);
        }
    }
};
int main()
{
    Date A[5];
    int date, month, year;
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter the date: ";
        cin >> date;
        A[i].setDate(date);

        cout << "Enter the month: ";
        cin >> month;
        A[i].setMonth(month);

        cout << "Enter the year: ";
        cin >> year;
        A[i].setYear(year);
        cout << endl;
    }
    cout << endl
         << endl;
    cout << "ORIGNIAL" << endl;
    for (int i = 0; i < 5; i++)
        cout << A[i].getDate() << "/" << A[i].getMonth() << "/" << A[i].getYear() << endl;
    Date sort;
    sort.selectionSort(A, 5);
    cout << endl
         << endl;
    cout << "SORTED" << endl;
    for (int i = 0; i < 5; i++)
        cout << A[i].getDate() << "/" << A[i].getMonth() << "/" << A[i].getYear() << endl;
}