/*
2023.2.7
Alessandro Accardi
ATM Project
V.5 (2025.04.10)
*/

#include <iostream>
#include <cmath>
#include <fstream>
#include <time.h>
#include "Bank.h"


int main() {
    User Users[100];
    User* CurrentUser = new User;

    std::ifstream UserList("accounts.txt");
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
    std::string ans;
    bool op;
    
    do {
        std::cout << std::endl << "Please select operation: [LOGIN] [OPEN]\n";
        std::cin >> ans;
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
            std::cout << "<INVALID OPERATION>\n";
        }
    } while (op == false);


    int hold    = CheckUser(Users);

    *CurrentUser = Users[hold];

    CurrentUser = DoTransaction(CurrentUser);

    Users[hold] = *CurrentUser;
    
    WriteUserData(Users, i);
}
