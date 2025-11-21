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
    virtual int AccountCheck(int enteredaccno) = 0;
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
    int AccountCheck(int enteredaccno) override
    {
        int enteredPin;
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
    Transactions utkarsh[100];
    int i = 0;
    while (true)
    {
        int InNum = 0;
        cout << "-------------------Welcome To Utkarsh's ATM-------------------" << endl;
        cout << "1.)Press 1 To open a Bank Account" << endl;
        cout << "2.)Press 2 to login to existing account" << endl;
        cout << "3.)press 3 to exit" << endl;
        cin >> InNum;
        if (InNum == 1)
        {
            utkarsh[i].openAccount();
            i++;
            continue;
        }
        else if (InNum == 2)
        {
            while (true)
            {
                int enteredaccno;
                cout << "enter your Account Number" << endl;
                cin >> enteredaccno;
                if (utkarsh[enteredaccno].AccountCheck(enteredaccno))
                {
                    while (true)
                    {
                        int input = 0;
                        cout << "1.)press 1 to withdraw Money" << endl;
                        cout << "2.)press 2 to Deposit Money" << endl;
                        cout << "3.)press 3 to Check Account Balance" << endl;
                        cout << "4.)press 4 to Return to last Menu" << endl;
                        cout << "5.)press 5 to exit" << endl;
                        cin >> input;

                        if (input == 1)
                        {
                            utkarsh[enteredaccno].withdraw();
                            continue;
                        }
                        else if (input == 2)
                        {
                            utkarsh[enteredaccno].deposit();
                            continue;
                        }
                        else if (input == 3)
                        {
                            utkarsh[enteredaccno].checkBalance();
                            continue;
                        }
                        else if (input == 4)
                        {
                            break;
                        }
                        else if (input == 5)
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
        }
        else if (InNum == 3)
        {
            return 0;
        }
        else
        {
            cout << "Invalid Input" << endl;
            continue;
        }
    }
    return 0;
}