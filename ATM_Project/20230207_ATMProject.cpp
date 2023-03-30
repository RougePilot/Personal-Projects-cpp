/*
2023.2.7
Alessandro Accardi
ATM Project
V.4.3 (2023.03.30)
*/

#include <iostream>
#include <cmath>
#include <fstream>
#include <time.h>
using namespace std;

class ATM {
protected:
    double Balance;
    int AccNum;
public:
    double amt;
    ATM();
    ~ATM();
    virtual void Deposit() {
        cout << "Enter amount in USD to deposit into your account: ";
        cin >> amt;
        Balance = Balance + amt;
        cout << "New balance is: $" << GetBal() << "\n";
    }
    virtual void Withdraw() {
        cout << "Enter amount in USD to withdraw from your account: ";
        cin >> amt;
        if (amt > Balance) {
            cout<< "Your balance is less than $" << amt << ", so you may not withdraw this amount.\n";
        }
        else {
            Balance = Balance - amt;
            cout << "New balance is: $" << Balance << "\n";
        }
    }
    virtual void Inquire() {
        cout << "Current balance is: $" << Balance << "\n";
    }
    double GetBal(){ return Balance; }
    void SetBal(double nb){ Balance = nb; }
    double GetAccNum() { return AccNum; }
    void SetAccNum(int ncn) { AccNum = ncn; }
};
ATM::ATM() {
    cout << "Welcome to Based Bank, where we keep your money safe and secure.\n";
}
ATM::~ATM() {
    cout << "Thank you for using Based Bank. Remember to eat healthy, lift often, and don't drink the corn syrup.\n";
}

class CheckingAccount :public ATM {
public:
    CheckingAccount() { cout << "You have one CHECKING ACCOUNT\n"; }
    ~CheckingAccount() { cout << "Signing out of CHECKING ACCOUNT\n"; }
};
class SavingsAccount :public ATM {
public:
    void GainLoss() {
        srand(time(0));
        double multiplier = (rand()%50-50);
        multiplier = multiplier / 100;
        Balance = Balance + Balance * multiplier;
    }
    SavingsAccount() {
        cout << "You have one SAVINGS ACCOUNT\n";
    }
    ~SavingsAccount() { cout << "Signing out of SAVINGS ACCOUNT\n"; }

    void Deposit() {
        GainLoss();
        cout << "Enter amount in USD to deposit into your account: ";
        cin >> amt;
        Balance = Balance + amt;
        cout << "New balance is: $" << GetBal() << "\n";
    }
    void Withdraw() {
        GainLoss();
        cout << "Enter amount in USD to withdraw from your account: ";
        cin >> amt;
        if (amt > Balance) {
            cout << "Your balance is less than $" << amt << ", so you may not withdraw this amount.\n";
        }
        else {
            Balance = Balance - amt;
            cout << "New balance is: $" << Balance << "\n";
        }
    }
    void Inquire() {
        GainLoss();
        cout << "Current balance is: $" << Balance << "\n";
    }
};

class User {
private:
    int ID;
    int PIN;
public:
    int GetPIN() { return PIN; }
    void SetPIN(int np) { PIN = np; }
    int GetID() { return ID; }
    void SetID(int ni) { ID = ni; }

    CheckingAccount* CheckingAcc = new CheckingAccount;
    SavingsAccount* SavingsAcc = new SavingsAccount;

    User() {  }
    ~User() {  }
};

//Normal Functions
User OpenAccount(User Users[100], int i) {
    int pin;
    int id   = Users[i-1].GetID() + 1;
    int cnum = 1000 + i + 1;
    int snum = 2000 + i + 1;
    cout << endl << "Please enter a PIN for your account: ";
    cin >> pin;
    Users[i].SetID(id);
    Users[i].SetPIN(pin);
    Users[i].CheckingAcc->SetAccNum(cnum);
    Users[i].CheckingAcc->SetBal(0);
    Users[i].SavingsAcc->SetAccNum(snum);
    Users[i].SavingsAcc->SetBal(0);
    cout << "\nUser Info:\n==========\nID: " << id << "\nPIN: " << pin << "\nChecking Account number: " << cnum << "\nSavings Account number: " << snum << endl << endl;
    return Users[i];
}

void CloseAccount(User* CU) {
    CU->SetPIN(-1);
    CU->CheckingAcc->SetAccNum(-1);
    CU->CheckingAcc->SetBal(-1);
    CU->SavingsAcc->SetAccNum(-1);
    CU->SavingsAcc->SetBal(-1);
}

User *DoTransaction(User *CU) {
    int uname; //Holder variable for username entry
    bool ans = false;//holder variable for
    int hold;
    string selection;
    do {
        ans = false;
        do {
            cout << "Please input your ACCOUNT NUMBER: ";
            cin >> uname;
            cout << "\n";
            for (int i = 0; i < 10; i++) {
                if (uname == CU->CheckingAcc->GetAccNum()) {
                    ans = true;
                    do {
                        cout << "Select an operation to perform: [DEPOSIT] [WITHDRAW] [INQUIRE] [CLOSE]\n";
                        cin >> selection;
                        if (selection == "DEPOSIT") {
                            CU->CheckingAcc->Deposit();
                        }
                        else if (selection == "WITHDRAW") {
                            CU->CheckingAcc->Withdraw();
                        }
                        else if (selection == "INQUIRE") {
                            CU->CheckingAcc->Inquire();
                        }
                        else if (selection == "CLOSE") {
                            CloseAccount(CU);
                            goto skips;
                        }
                        else {
                            cout << "<INVALID OPERATION>\n";
                            selection = "Y";
                            goto skip4;
                        }

                        cout << "Would you like to perform another transaction? [Y] [N] :";
                        cin >> selection;
                    skip4:;
                    } while (selection == "Y");
                    goto skips;
                }
                else if (uname == CU->SavingsAcc->GetAccNum()) {
                    ans = true;
                    do {
                        cout << "Select an operation to perform: [DEPOSIT] [WITHDRAW] [INQUIRE] [CLOSE]\n";
                        cin >> selection;
                        if (selection == "DEPOSIT") {
                            CU->SavingsAcc->Deposit();
                        }
                        else if (selection == "WITHDRAW") {
                            CU->SavingsAcc->Withdraw();
                        }
                        else if (selection == "INQUIRE") {
                            CU->SavingsAcc->Inquire();
                        }
                        else if (selection == "CLOSE") {
                            CloseAccount(CU);
                            goto skips;
                        }
                        else {
                            cout << "<INVALID OPERATION>\n";
                            selection = "Y";
                            goto skip5;
                        }

                        cout << "Would you like to perform another transaction? [Y] [N] :";
                        cin >> selection;
                    skip5:;
                    } while (selection == "Y");
                    goto skips;
                }
                else {
                    ans = false;
                    cout << "Account Number is incorrect, please try again: \n";
                    goto skip3;
                }
            }
        skip3:;
        } while (ans == false);
        cout << "ERROR: ACCOUNT NUMBER and PIN combination is incorrect. Please try again.\n";
    } while (ans == false);

skips:;
    return CU;
}

void WriteUserData(User CU[100], int hold) {
    ofstream UserList("accounts.txt");
    for (int i = 0; i < hold; i++) {
        if (CU[i].GetPIN() != (-1)) {
            UserList << CU[i].GetID() << " " << CU[i].GetPIN() << " " << CU[i].CheckingAcc->GetAccNum() << " " << CU[i].CheckingAcc->GetBal() << " " << CU[i].SavingsAcc->GetAccNum() << " " << CU[i].SavingsAcc->GetBal();
            if (i < hold - 1) {
                UserList << endl;
            }
        }
    }
    UserList.close();
}

int CheckUser(User CU[100]) {
    int uname; //Holder variable for username entry
    int pin1;//Holder variable for pin entry
    bool ans = false;//holder variable for
    int hold;
    do {
        cout << "Please input your ACCOUNT ID and PIN: ";
        cin >> uname >> pin1;
        cout << "\n";
        for (int i = 0; i < 100; i++) {
            if (uname == CU[i].GetID() && pin1 == CU[i].GetPIN()) {
                ans = true;
                hold = i;
                goto skips;
            }
        }
        cout << "ERROR: ACCOUNT NUMBER and PIN combination is incorrect. Please try again.\n";
    } while (ans == false);
skips:;
    return hold;
}

int main() {
    User Users[100];
    User* CurrentUser = new User;

    ifstream UserList("accounts.txt");
    int i = 0;
    int a,c,e,f;
    double b, d;
    while (!UserList.eof()) {
        UserList >> e >> f >> a >> b >> c >> d;
        Users[i].SetID(e);
        Users[i].SetPIN(f);
        Users[i].CheckingAcc->SetAccNum(a);
        Users[i].CheckingAcc->SetBal(b);
        Users[i].SavingsAcc->SetAccNum(c);
        Users[i].SavingsAcc->SetBal(d);
        i++;
    }
    UserList.close();
    string ans;
    bool op;
    
    do {
        cout << "Please select operation: [LOGIN] [OPEN]\n";
        cin >> ans;
        if (ans == "LOGIN") {
            op = true;
            break;
        }
        else if (ans == "OPEN") {
            Users[i] = OpenAccount(Users, (i));
            i++;
            op = true;
        }
        else {
            op = false;
            cout << "<INVALID OPERATION>\n";
        }
    } while (op == false);


    int hold    = CheckUser(Users);

    *CurrentUser = Users[hold];

    CurrentUser = DoTransaction(CurrentUser);

    Users[hold] = *CurrentUser;
    
    WriteUserData(Users, i);
}
