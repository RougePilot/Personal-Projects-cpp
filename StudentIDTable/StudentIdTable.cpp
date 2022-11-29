/*
2022.11.17
RougePilot
Program will ask for Student info and put it into a table (txt file)
*/

#include <iostream>
#include <fstream>
#include <iomanip>

int main()
{
    std::string name;
    std::string lname;
    std::string id;
    int totStudents;//number of students

    std::ofstream nliTable("nliTable.txt", std::ios::out);

    std::cout << "Enter Number of Students: ";
    std::cin >> totStudents;

    for (int i = 0; i <= totStudents; i++) {
        if (i == 0) {
            //will create the table header
            nliTable << std::left << "| " << std::setw(10) << "Name" << " | " << std::setw(10) << "Last Name" << " | " << std::setw(13) << "School ID No." << " | \n";
            nliTable << "+============+============+===============+\n";
        }
        else {
            std::cout << "Enter First Name, Last Name, and ID Number: ";
            std::cin >> name >> lname >> id;

            if (name == "00" || lname == "00" || id == "00") {
                break;
            }
            

            //creates the rows for each student with name, last name, and ID number
            nliTable << std::left << "| " << std::setw(10) << name << " | " << std::setw(10) << lname << " | " << std::setw(13) << id << " | \n";
        }
    }
    nliTable.close();
}