/*
2023.2.7
Alessandro Accardi
ATM Project
*/

#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

class ATM {
private:
    int AccNums[10];
    int PIN[10];
    double Balance[10];
public:
    double amt;//amount depositing or withdrawing
    string selection;//operation selection

    ATM();
    ATM(int amt, string selection);
    ~ATM();
    void Deposit();
    void Withdraw();
    void Inquiry();
    int GetAccNum(int i);
    void SetAccNum(int i,int nn);
    double GetBal(int i);
    void SetBal(int i, double nb);
    int GetPIN(int i);
    void SetPIN(int i,int np);
};

//Member Functions
ATM::ATM() {
    cout << "Welcome to Based Bank, where we keep your money safe and secure.\n";
    ifstream UserList("accounts.txt");
    int i = 0;
    while (!UserList.eof()) {
        UserList >> AccNums[i] >> PIN[i] >> Balance[i];
        i++;
    }
    UserList.close();
}
ATM::ATM(int amt, string selection) {
    cout << "Welcome to Based Bank, where we keep your money safe and secure.\n";
    ifstream UserList("accounts.txt");
    int i = 0;
    while (!UserList.eof()) {
        UserList >> AccNums[i] >> PIN[i] >> Balance[i];
        i++;
    }
    UserList.close();
}

ATM::~ATM() {
    cout << "Thank you for using Based Bank. Remember to eat healthy, lift often, and don't drink the corn syrup.\n";
}

int ATM::GetAccNum(int i) {
    return AccNums[i];
}
void ATM::SetAccNum(int i,int nn) {
    AccNums[i] = nn;
}
double ATM::GetBal(int i) {
    return Balance[i];
}
void ATM::SetBal(int i,double nb) {
    Balance[i] = nb;
}
int ATM::GetPIN(int i) {
    return PIN[i];
}

//Normal Functions
int CheckUser(ATM Users[10]) {
    int uname; //Holder variable for username entry
    int pin1;//Holder variable for pin entry
    bool ans = false;//holder variable for
    int hold;//storage variable

    do {
        cout << "Please input your ACCOUNT NUMBER and PIN: ";
        cin >> uname >> pin1;
        cout << "\n";
        for (int i = 0; i < 10; i++) {
            if (uname == Users[i].GetAccNum(i) && pin1 == Users[i].GetPIN(i)) {
                ans = true;
                hold = i;
                goto skips;
            }
        }
        cout << "ERROR: ACCOUNT NUMBER and PIN combination is incorrect. Please try again.\n";
        skips:;
    } while (ans == false);

    return hold;
}

void DoTransaction(ATM User,int i) {
    do {
        cout << "Select an operation to perform: [DEPOSIT] [WITHDRAW] [INQUIRE]\n";
        cin >> User.selection;
        if (User.selection == "DEPOSIT") {
            cout << "Enter amount in USD to deposit into your account: ";
            cin >> User.amt;
            User.SetBal(i,(User.GetBal(i) + User.amt));
            cout << "New balance is: $" << User.GetBal(i) << "\n";
        }
        else if (User.selection == "WITHDRAW") {
            cout << "Enter amount in USD to withdraw from your account: ";
            cin >> User.amt;
            if (User.amt > User.GetBal(i)) {
                cout << "Your balance is less than $" << User.amt << ", so you may not withdraw this amount.\n";
            }
            else {
                User.SetBal(i, (User.GetBal(i) - User.amt));
                cout << "New balance is: $" << User.GetBal(i) << "\n";
            }
        }
        else if (User.selection == "INQUIRE") {
            cout << "Current balance is: $" << User.GetBal(i) << "\n";
        }

        cout << "Would you like to perform another transaction? [Y] [N] ";
        cin >> User.selection;
    } while (User.selection == "Y");
}

void WriteUserData(ATM User, int i) {
    ofstream UserList("accounts.txt");
    for (int i = 0; i < 10; i++) {
        UserList << User.GetAccNum(i) << " " << User.GetPIN(i) << " " << User.GetBal(i) << endl;
    }
    UserList.close();
}

int main() {
    ATM Users[10];

    int hold = CheckUser(Users);

    DoTransaction(Users[hold], hold);
    
    WriteUserData(Users[hold], hold);
}
