#include <bits/stdc++.h>
using namespace std;

class mainFunctions
{
protected:
    static int accountNumber;
    double accountBalance = 0;
    string Name;
    int Age;
    int Pin;

public:
    virtual void deposit(double depamt) = 0;
    virtual void withdraw(double withamt) = 0;
    virtual int AccountCheck() = 0;
};

int mainFunctions::accountNumber;

class Transactions : mainFunctions
{
public:
    void deposit(double depamt) override
    {
        cout << "Enter Ammount";
        cin >> depamt;
        if (depamt > 0)
        {
            mainFunctions::accountBalance += depamt;
            cout << depamt << "Rs deposited Your updated balance is: " << accountBalance;
        }
        else
        {
            cout << "Invalid Ammount" << endl;
        }
    }
    void withdraw(double withamt) override
    {
        cout << "Enter Ammount";
        cin >> withamt;
        if (withamt <= accountBalance)
        {
            mainFunctions::accountBalance -= withamt;
            cout << withamt << "Rs withdrawn Your updated balance is: " << accountBalance;
        }
        else
        {
            cout << "Insuficient Balance" << endl;
        }
    }
    int AccountCheck() override
    {
        int enteredPin;
        int enteredaccno;
        cout << "enter your Account Number" << endl;
        cin >> enteredaccno;
        cout << "Hello Enter your Pin" << endl;
        cin >> enteredPin;
        if (accountNumber == enteredaccno && Pin == enteredPin)
        {
            cout << "Welcome " << endl
                 << "Name: " << Name << endl
                 << "Age: " << Age << endl
                 << "Account NO. : " << accountNumber << endl
                 << "Current Balance: " << accountBalance << endl;
            return 1;
        }
        else
        {
            return 0;
        }
    }

    void openAccount()
    {
        cout << "Enter Your Name" << endl;
        cin >> Name;
        cout << "Enter Your Age" << endl;
        cin >> Age;
        cout << "Please Set your 4 digit pin" << endl;
        cin >> Pin;
        if (double(Pin / 10000) >= 1 || double(Pin / 1000) < 1)
        {
            cout << "Invaid pin" << endl;
        }
        else
        {
            cout << "Congratualtions! " << Name << " your Account is Active Now with Account Number " << accountNumber << endl;
        }
    }
};

int main()
{
    Transactions utkarsh;
    utkarsh.openAccount();
    utkarsh.AccountCheck();
    return 0;
}