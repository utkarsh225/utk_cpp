#include <bits/stdc++.h>
using namespace std;

class mainFunctions
{

protected:
    static int globalCounter;
    int accountNumber;
    double accountBalance = 0;
    string Name;
    int Age;
    int Pin;

public:
    mainFunctions()
    {
        accountNumber = globalCounter;
        globalCounter++;
    }
    virtual void deposit() = 0;
    virtual void withdraw() = 0;
    virtual int AccountCheck() = 0;
    virtual void checkBalance() = 0;
};

int mainFunctions::globalCounter;

class Transactions : mainFunctions
{
public:
    void deposit() override
    {
        double depamt;
        cout << "Enter Ammount: ";
        cin >> depamt;
        if (depamt > 0)
        {
            mainFunctions::accountBalance += depamt;
            cout << depamt << " Rs deposited Your updated balance is: " << accountBalance << endl
                 << endl;
        }
        else
        {
            cout << "Invalid Ammount" << endl
                 << endl;
        }
    }
    void withdraw() override
    {
        double withamt;
        cout << "Enter Ammount: ";
        cin >> withamt;
        if (withamt <= accountBalance)
        {
            mainFunctions::accountBalance -= withamt;
            cout << withamt << " Rs withdrawn Your updated balance is: " << accountBalance << endl
                 << endl;
        }
        else
        {
            cout << "Insuficient Balance" << endl
                 << endl;
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
                 << endl;
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
        while (true)
        {
            cout << "Please Set your 4 digit pin" << endl;
            cin >> Pin;
            if (Pin >= 1000 && Pin <= 9999)
            {
                cout << "Congratualtions! " << Name << " your Account is Active Now with Account Number " << accountNumber << endl;
                break;
            }
            else
            {
                cout << "Invaid pin" << endl;
                continue;
            }
        }
    }
    void checkBalance()
    {
        cout << "Current Balance: " << accountBalance << endl
             << endl;
    }
};

int main()
{
    Transactions utkarsh;
    utkarsh.openAccount();
    while (true)
    {
        if (utkarsh.AccountCheck())
        {
            while (true)
            {
                int input = 0;
                cout << "1.)press 1 to withdraw Money" << endl;
                cout << "2.)press 2 to Deposit Money" << endl;
                cout << "3.)press 3 to Check Account Balance" << endl;
                cout << "4.)press 4 to exit" << endl;
                cin >> input;

                if (input == 1)
                {
                    utkarsh.withdraw();
                    continue;
                }
                else if (input == 2)
                {
                    utkarsh.deposit();
                    continue;
                }
                else if (input == 3)
                {
                    utkarsh.checkBalance();
                    continue;
                }
                else if (input == 4)
                {
                    return 0;
                }
                else
                {
                    cout << "Invalid Input" << endl;
                    continue;
                }
            }
            break;
        }
        else
        {
            cout << "Invalid Account No. or Pin" << endl;
            continue;
        }
    }
    return 0;   
}