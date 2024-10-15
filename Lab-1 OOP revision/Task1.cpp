#include <iostream>
using namespace std;
class BankAccount
{
    double amount;

public:
    BankAccount() : amount(0.0)
    {
        cout << "default constructor called" << endl
             << "Amount: " << amount << "$" << endl
             << endl;
    }
    BankAccount(double amount) : amount(amount)
    {
        cout << "parametarized constructor called" << endl
             << "Amount: " << amount << "$" << endl
             << endl;
    }
    BankAccount(BankAccount &a) : amount(a.amount)
    {
        cout << "Copy constructor called" << endl
             << "Amount: " << amount << "$" << endl
             << endl;
    }
    void deduct()
    {
        if(amount < 200)
        {
            cout << "insufficient balance!" << endl;
            return;
        }
        cout << "Deducting 200$"<<endl;
        amount-=200;
    }
    double getAmount()
    {
        return amount;
    }
};
int main()
{
    BankAccount b1;
    BankAccount b2(5000);
    BankAccount b3=b2;
    b3.deduct();
    cout << "Amount: "<< b3.getAmount()<< endl << endl;
    cout << "-----------------------------" <<endl;
    cout << "SUMMARY"<< endl;
    cout << "-----------------------------" <<endl;
    cout << "Account 1 Amount: " << b1.getAmount()<<endl;
    cout << "Account 2 Amount: " << b2.getAmount()<<endl;
    cout << "Account 3 Amount: " << b3.getAmount()<<endl;
}