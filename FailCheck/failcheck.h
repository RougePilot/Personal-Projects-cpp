#pragma once

/*
Program answer redundancy library
2022.10.06
Alessandro Accardi
Short loops to ask user to retry the input if it fails
*/

#include <iostream>

void FCInt() { //Fail check for integers
    int ans;
    bool cinfail = true;
    while (cinfail == true) {
        std::cout << "Please enter an integer: ";
        std::cin >> ans;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.sync();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Fail" << "\n" << "Error: input is not an integer, please input an integer" << "\n";
        }
        else {
            std::cout << "Success!" << "\n";
            cinfail = false;
        }
    }
}

void FCDouble() { //Fail check forfloating point numbers
    double ans;
    bool cinfail = true;
    while (cinfail == true) {
        std::cout << "please enter a number: ";
        std::cin >> ans;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.sync();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Fail" << "\n" << "Error: input is not a number, please input a number" << "\n";
        }
        else {
            std::cout << "Success!" << "\n";
            cinfail = false;
        }
    }
}
