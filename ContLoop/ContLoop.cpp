/*
Program rerun
ALessandro Accardi
2022.09.20
Asks if user wants to sontinue the program/rerun it
*/

#include <iostream>


int main() {
    string x = "Y";
    while(x=="Y" || x == "Yes") {
        std::cout << "Would you like to continue the program?\n"<<"Please answer with Y for Yes or N for No:\n";
        std::cin >> x;
    }

    return 0;
}
