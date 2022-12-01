/*
2022.11.29
Alessandro Accardi
Will search a database for a student with matching ID number
*/


#include <iostream>
#include <fstream>
#include <iomanip>

int main()
{
	int n = 10;//number of students in database
	int StuID;//for searching the ID of the student
	std::string lname;//for searching the last name of the student
	int* ID=new int[n];
	std::string* Name=new std::string[n];
	std::string* LName=new std::string[10];
	double* GPA=new double[n];
	int i = 0;//counting for the array scraper
	int k;
	std::string ans = "ID";


	std::ifstream StuInfo("StudentInfo.txt");

	while (!StuInfo.eof()) {
		StuInfo >> ID[i] >> Name[i] >> LName[i] >> GPA[i];
		i++;
	}

	StuInfo.close();

	bool Answer=true;

	std::cout << "GSST Student Information System\n\n";
	
	do {
		std::cout << "Would you like to search by ID number or Last Name? (ID/LName): ";
		std::cin >> ans;

		if (ans == "ID") {
			std::cout << "Please enter the student's ID Number: ";
			std::cin >> StuID;
			std::cout << "\n";
			Answer = true;
			break;
		}
		else if (ans == "LName") {
			std::cout << "Please enter the student's last name: ";
			std::cin >> lname;
			std::cout << "\n";
			Answer == true;
			break;
		}
		else {
			std::cout << "\nError: Please enter either 'ID' or 'LName' to select a search type.\n";
			Answer = false;
		}
	} while (Answer == false);

	std::cout << std::left << "| " << std::setw(6) << "ID No." << " | " << std::setw(15) << "Name" << " | " << std::setw(15) << "Last Name" << " | " << std::setw(3) << "GPA" << " | \n";
	std::cout << "+========+=================+=================+=====+\n";

	if (ans == "ID") {
		for (int j = 0; j < n; j++) {
			if (StuID == ID[j]) {
				std::cout << std::left << "| " << std::setw(6) << ID[j] << " | " << std::setw(15) << Name[j] << " | " << std::setw(15) << LName[j] << " | " << std::setw(3) << GPA[j] << " | \n";
			}
		}
	}
	else if(ans=="LName") {
		for (int j = 0; j < n; j++) {
			if (lname == LName[j]) {
				std::cout << std::left << "| " << std::setw(6) << ID[j] << " | " << std::setw(15) << Name[j] << " | " << std::setw(15) << LName[j] << " | " << std::setw(3) << GPA[j] << " | \n";
			}
		}
	}
}
