#ifndef BANK_H
#define BANK_H


#include <iostream>
#include <cmath>
#include <fstream>
#include <time.h>

class ATM {
protected:
    double Balance;
    int AccNum;
public:
    double amt;
    // ATM() {std::cout<<"A1";}
    // ~ATM() {std::cout<<"A2";}
    virtual void Deposit() {
	std::cout << "Enter amount in USD to deposit into your account: ";
	std::cin >> amt;
        Balance = Balance + amt;
        std::cout << "New balance is: $" << GetBal() << "\n";
    }
    virtual void Withdraw() {
        std::cout << "Enter amount in USD to withdraw from your account: ";
        std::cin >> amt;
        if (amt > Balance) {
            std::cout<< "Your balance is less than $" << amt << ", so you may not withdraw this amount.\n";
        }
        else {
            Balance = Balance - amt;
            std::cout << "New balance is: $" << Balance << "\n";
        }
    }
    virtual void Inquire() {
        std::cout << "Current balance is: $" << Balance << "\n";
    }
    double GetBal(){ return Balance; }
    void SetBal(double nb){ Balance = nb; }
    double GetAccNum() { return AccNum; }
    void SetAccNum(int ncn) { AccNum = ncn; }
};

class CheckingAccount :public ATM {
public:
    // CheckingAccount() {std::cout<<"C1";}
    // ~CheckingAccount() {std::cout<<"C2";}
};
class SavingsAccount :public ATM {
public:
    void GainLoss() {
        srand(time(0));
        double multiplier = (rand()%50-50);
        multiplier = multiplier / 100;
        Balance = Balance + Balance * multiplier;
    }
    // SavingsAccount() {std::cout<<"S1";}
    // ~SavingsAccount() {std::cout<<"S2";}

    void Deposit() {
        GainLoss();
        std::cout << "Enter amount in USD to deposit into your account: ";
        std::cin >> amt;
        Balance = Balance + amt;
        std::cout << "New balance is: $" << GetBal() << "\n";
    }
    void Withdraw() {
        GainLoss();
        std::cout << "Enter amount in USD to withdraw from your account: ";
        std::cin >> amt;
        if (amt > Balance) {
            std::cout << "Your balance is less than $" << amt << ", so you may not withdraw this amount.\n";
        }
        else {
            Balance = Balance - amt;
            std::cout << "New balance is: $" << Balance << "\n";
        }
    }
    void Inquire() {
        GainLoss();
        std::cout << "Current balance is: $" << Balance << "\n";
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

User OpenAccount(User Users[100], int i);

User *DoTransaction(User *CU);

void WriteUserData(User CU[100], int hold);

int CheckUser(User CU[100]);





#endif
