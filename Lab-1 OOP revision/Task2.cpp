#include <iostream>
using namespace std;
class Exam
{
    string name;
    string date;
    int score;
    public:
    Exam(string name, string date, int score): name(name), date(date), score(score){}
    Exam():name("unknown"),date("unknown"), score(0){}

    void setName(string name)
    {
        this->name = name;
    }
    void setDate(string date)
    {
        this->date = date;
    }
    void setScore(int score)
    {
        this->score = score;
    }
    void display()
    {
        cout << "INFO" << endl;
        cout << "Name: " << name << endl;
        cout << "Date: " << date << endl;
        cout << "Score: " << score << endl << endl;
    }
    Exam(Exam &other) : name(other.name), date(other.date), score(other.score) {
        cout << "------------------------------------" << endl;
        cout << "copy constructor called" << endl;
        cout << "------------------------------------" << endl;
    }
    Exam &operator=(const Exam &other)
    {
        if (this == &other)
        {
            return *this;
        }
        name = other.name;
        date = other.date;
        score = other.score;
        cout << "------------------------------------" << endl;
        cout << "copy Assignment operator called" << endl;
        cout << "------------------------------------" << endl;
        return *this;
    }
};
int main()
{
    Exam exam1("Math", "2024-08-30", 95);
    Exam exam2;
     
    cout << "Initial Values of exam2:" << endl;
    exam2.display();
    
    exam2 = exam1; // Assignment copy constructor

    cout << "Values of exam2 after assignment from exam1:" << endl;
    exam2.display();

    Exam exam3 = exam1; // copy constructor

    cout << "Values of exam3 created using copy constructor:" << endl;
    exam3.display();

    return 0;
}