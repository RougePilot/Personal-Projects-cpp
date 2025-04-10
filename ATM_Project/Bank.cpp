#include <iostream>
#include <cmath>
#include <fstream>
#include <time.h>
#include "Bank.h"


//Normal Functions
User OpenAccount(User Users[100], int i) {
    int pin;
    int id   = Users[i-1].GetID() + 1;
    int cnum = 1000 + i + 1;
    int snum = 2000 + i + 1;
    std::cout << std::endl << "Please enter a PIN for your account: ";
    std::cin >> pin;
    Users[i].SetID(id);
    Users[i].SetPIN(pin);
    Users[i].CheckingAcc->SetAccNum(cnum);
    Users[i].CheckingAcc->SetBal(0);
    Users[i].SavingsAcc->SetAccNum(snum);
    Users[i].SavingsAcc->SetBal(0);
    std::cout << "\nUser Info:\n==========\nID: " << id << "\nPIN: " << pin << "\nChecking Account number: " << cnum << "\nSavings Account number: " << snum << std::endl << std::endl;
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
    std::string selection;
    do {
        ans = false;
        do {
            std::cout << "Please input your ACCOUNT NUMBER: ";
            std::cin >> uname;
            std::cout << "\n";
            for (int i = 0; i < 10; i++) {
                if (uname == CU->CheckingAcc->GetAccNum()) {
                    ans = true;
                    do {
                        std::cout << "Select an operation to perform: [DEPOSIT] [WITHDRAW] [INQUIRE] [CLOSE]\n";
                        std::cin >> selection;
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
                            std::cout << "<INVALID OPERATION>\n";
                            selection = "Y";
                            goto skip4;
                        }

                        std::cout << "Would you like to perform another transaction? [Y] [N] :";
                        std::cin >> selection;
                    skip4:;
                    } while (selection == "Y");
                    goto skips;
                }
                else if (uname == CU->SavingsAcc->GetAccNum()) {
                    ans = true;
                    do {
                        std::cout << "Select an operation to perform: [DEPOSIT] [WITHDRAW] [INQUIRE] [CLOSE]\n";
                        std::cin >> selection;
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
                            std::cout << "<INVALID OPERATION>\n";
                            selection = "Y";
                            goto skip5;
                        }

                        std::cout << "Would you like to perform another transaction? [Y] [N] :";
                        std::cin >> selection;
                    skip5:;
                    } while (selection == "Y");
                    goto skips;
                }
                else {
                    ans = false;
                    std::cout << "Account Number is incorrect, please try again: \n";
                    goto skip3;
                }
            }
        skip3:;
        } while (ans == false);
        std::cout << "ERROR: ACCOUNT NUMBER and PIN combination is incorrect. Please try again.\n";
    } while (ans == false);

skips:;
    return CU;
}

void WriteUserData(User CU[100], int hold) {
    std::ofstream UserList("accounts.txt");
    for (int i = 0; i < hold; i++) {
        if (CU[i].GetPIN() != (-1)) {
            UserList << CU[i].GetID() << " " << CU[i].GetPIN() << " " << CU[i].CheckingAcc->GetAccNum() << " " << CU[i].CheckingAcc->GetBal() << " " << CU[i].SavingsAcc->GetAccNum() << " " << CU[i].SavingsAcc->GetBal();
            if (i < hold - 1) {
                UserList << std::endl;
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
        std::cout << "Please input your ACCOUNT ID and PIN: ";
        std::cin >> uname >> pin1;
        std::cout << "\n";
        for (int i = 0; i < 100; i++) {
            if (uname == CU[i].GetID() && pin1 == CU[i].GetPIN()) {
                ans = true;
                hold = i;
                goto skips;
            }
        }
        std::cout << "ERROR: ACCOUNT NUMBER and PIN combination is incorrect. Please try again.\n";
    } while (ans == false);
skips:;
    return hold;
}

