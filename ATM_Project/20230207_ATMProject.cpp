/*
2023.2.7
Alessandro Accardi
ATM Project
V.3 (2023.3.2)
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

    CheckingAccount CheckingAcc;
    SavingsAccount SavingsAcc;

    User() {  }
    ~User() {  }
};

//Normal Functions
User DoTransaction(User CU) {
    int uname; //Holder variable for username entry
    bool ans = false;//holder variable for
    int hold;
    string selection;
    do {
        cout << "Please input your ACCOUNT NUMBER: ";
        cin >> uname;
        cout << "\n";
        for (int i = 0; i < 10; i++) {
            if (uname == CU.CheckingAcc.GetAccNum()) {
                ans = true;
                do {
                    cout << "Select an operation to perform: [DEPOSIT] [WITHDRAW] [INQUIRE]\n";
                    cin >> selection;
                    if (selection == "DEPOSIT") {
                        CU.CheckingAcc.Deposit();
                    }
                    else if (selection == "WITHDRAW") {
                        CU.CheckingAcc.Withdraw();
                    }
                    else if (selection == "INQUIRE") {
                        CU.CheckingAcc.Inquire();
                    }

                    cout << "Would you like to perform another transaction? [Y] [N] :";
                    cin >> selection;
                } while (selection == "Y");
            }
            else if (uname == CU.SavingsAcc.GetAccNum()) {
                ans = true;
                //cout << CU.SavingsAcc.GetBal() << " Before GainLoss()" << endl << endl;//DEBUG
                CU.SavingsAcc.GainLoss();
                //cout << CU.SavingsAcc.GetBal()<< " After GainLoss()"<< endl << endl ;//DEBUG
                do {
                    cout << "Select an operation to perform: [DEPOSIT] [WITHDRAW] [INQUIRE]\n";
                    cin >> selection;
                    if (selection == "DEPOSIT") {
                        CU.SavingsAcc.Deposit();
                    }
                    else if (selection == "WITHDRAW") {
                        CU.SavingsAcc.Withdraw();
                    }
                    else if (selection == "INQUIRE") {
                        CU.SavingsAcc.Inquire();
                    }

                    cout << "Would you like to perform another transaction? [Y] [N] :";
                    cin >> selection;
                } while (selection == "Y");
                
            }
            goto skips;
        }
        cout << "ERROR: ACCOUNT NUMBER and PIN combination is incorrect. Please try again.\n";
    } while (ans == false);

skips:;
    return CU;
}

void WriteUserData(User CU[10]) {
    ofstream UserList("accounts.txt");
    for (int i = 0; i < 10; i++) {
        UserList << CU[i].GetID() << " " << CU[i].GetPIN() << " " << CU[i].CheckingAcc.GetAccNum() << " " << CU[i].CheckingAcc.GetBal() << " " << CU[i].SavingsAcc.GetAccNum() << " " << CU[i].SavingsAcc.GetBal();
        if (i < 9) {
            UserList << endl;
        }
    }
    UserList.close();
}

int CheckUser(User CU[10]) {
    int uname; //Holder variable for username entry
    int pin1;//Holder variable for pin entry
    bool ans = false;//holder variable for
    int hold;
    do {
        cout << "Please input your ACCOUNT ID and PIN: ";
        cin >> uname >> pin1;
        cout << "\n";
        for (int i = 0; i < 10; i++) {
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
    User Users[10];
    User CurrentUser;

    ifstream UserList("accounts.txt");
    int i = 0;
    int a,c,e,f;
    double b, d;
    while (!UserList.eof()) {
        UserList >> e >> f >> a >> b >> c >> d;
        Users[i].SetID(e);
        Users[i].SetPIN(f);
        Users[i].CheckingAcc.SetAccNum(a);
        Users[i].CheckingAcc.SetBal(b);
        Users[i].SavingsAcc.SetAccNum(c);
        Users[i].SavingsAcc.SetBal(d);
        i++;
    }
    UserList.close();

    int hold    = CheckUser(Users);
    CurrentUser = Users[hold];
    //cout << CurrentUser.SavingsAcc.GetBal() << " Before Transaction" << endl << endl;//DEBUG
    CurrentUser = DoTransaction(CurrentUser);
    //cout << CurrentUser.SavingsAcc.GetBal() << " After Transaction" << endl << endl;//DEBUG
    Users[hold] = CurrentUser;
    
    WriteUserData(Users);
}
