/*
2022.11.22
Alessandro Accardi
Searching for a word in a text file and giving the number of times the word appears
*/

#include <iostream>
#include <fstream>

int main()
{
	std::string word;
	std::string aword;
	std::ifstream Document("article.txt");

	std::string x = "Y";
	while (x == "Y" || x == "Yes") {

		int count = 0;

		bool fail = true;
		while (fail == true) {
			std::cout << "Enter an English word: ";
			std::cin >> word;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.sync();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Fail" << "\n" << "Error: input is not a word, please input a word" << "\n";
			}
			else {
				fail = false;
				continue;
			}
		}

		while (!Document.eof()) {
			Document >> aword;
			if (aword == word || aword == word + "." || aword == word + ",") {
				count++;
			}
		}

		std::cout << word << " appears " << count << " times.\n";

		std::cout << "Would you like to continue the program? (Y/N): \n";
		std::cin >> x;
	}

	Document.close();
}