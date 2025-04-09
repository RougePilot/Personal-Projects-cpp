/*
2022.11.22
Alessandro Accardi
Searching for a word in a text file and giving the number of times the word appears
*/

#include <iostream>
#include <fstream>

int main(int argc, char* argv[])
{
	std::string FileName = argv[1];
	std::string word;
	std::string aword;

	std::string ans = "Y";
	while (ans == "Y" || ans == "Yes") {
		std::ifstream Document(FileName);
		int count = 0;
		std::cout << "Enter an English word: ";
		std::cin >> word;

		do {
			Document >> aword;
			if (aword == word || aword == word + "." || aword == word + "," || aword == word + "'s") {count++;}
		} while (!Document.eof());

		std::cout << word << " appears " << count << " times.\n";

		std::cout << "Would you like to continue the program? (Y/N): \n";
		std::cin >> ans;
		Document.close();

	}

}
