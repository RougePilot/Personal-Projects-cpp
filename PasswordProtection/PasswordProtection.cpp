/*
2022.12.01
Alessandro Accardi
Password Protected Calculator
*/


#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include "calculator.h"


int main()
{
	int n = 10;//number of users in database
	std::string UPIN;//for searching the Password
	std::string UName;//for searching the username
	std::string* PIN = new std::string[n];
	std::string* Name = new std::string[n];
	int i = 0;//counting for the array scraper
	int k;
	bool ans = true;
	bool cont = false;
	char answer = 'Y';

	std::ifstream UPass("UserPass.txt");

	while (!UPass.eof()) {
		UPass >> Name[i] >> PIN[i];
		i++;
	}

	UPass.close();

	std::cout << "GSST Calculator System\n\n";

	do {
		std::cout << "Please enter the username and password: ";
		std::cin >> UName >> UPIN;
		std::cout << "\n";

		for (int j = 0; j < n; j++) {
			if (UName == Name[j] && UPIN == PIN[j]) {

				do {
					Calculate();
					std::cout << "Would you like to run the calculator again? (Y/N): ";
					std::cin >> answer;

					if (answer == 'Y') {
						cont = true;
						std::cout << "\n\n";
					}
					else {
						cont = false;
						break;
					}
				} while (cont == true);

				ans = true;
				break;
			}
			else {
				std::cout << "Error: Username and/or Password are incorrect, please try again.";
				ans = false;
			}
		}
	} while (ans == false);
}