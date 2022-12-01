#pragma once
/*
2022.10.11
calculator functions
*/
#include<iostream>
#include<cmath>

double Add(double n1, double n2) {
	double sum = n1 + n2;
	return sum;
}

double Sub(double n1, double n2) {
	double dif = n1 - n2;
	return dif;
}

double Mult(double n1, double n2) {
	double prod = n1 * n2;
	return prod;
}

double Div(double n1, double n2) {
	double quot = n1 / n2;
	return quot;
}

void Calculate() {
	
	double n1, n2;
	std::string op; //operator
	bool fail = true;
	while (fail == true) {
		std::cout << "Please input operation type (+,-,*,/,^,sqrt): ";
		std::cin >> op;
		if (op == "+") {
			std::cout << "Please input the numbers you wish to add (n1+n2): ";
			std::cin >> n1 >> n2;
			double sum = Add(n1, n2);
			std::cout << "=" << sum << "\n";
			fail = false;
		}
		else if (op == "-") {
			std::cout << "Please input the numbers you wish to subtract (n1-n2): ";
			std::cin >> n1 >> n2;
			double dif = Sub(n1, n2);
			std::cout << "=" << dif << "\n";
			fail = false;
		}
		else if (op == "*") {
			std::cout << "Please input the numbers you wish to multiply (n1*n2): ";
			std::cin >> n1 >> n2;
			double prod = Mult(n1, n2);
			std::cout << "=" << prod << "\n";
			fail = false;
		}
		else if (op == "/") {
			std::cout << "Please input the numbers you wish to divide (n1/n2): ";
			std::cin >> n1 >> n2;
			double quot = Div(n1, n2);
			std::cout << "=" << quot << "\n";
			fail = false;
		}
		else if (op == "^") {
			std::cout << "Please input the numbers you wish to take to the power (n1^n2): ";
			std::cin >> n1 >> n2;
			double Pow = pow(n1, n2);
			std::cout << "=" << Pow << "\n";
			fail = false;
		}
		else if (op == "sqrt") {
			std::cout << "Please input the number you wish to take the square root of (sqrt(n1)): ";
			std::cin >> n1;
			if (n1 >= 0) {
				double Sqrt = sqrt(n1);
				std::cout << "=" << Sqrt << "\n";
			}
			else {
				std::cout << "Error, PLease input positive number\n";
			}
			fail = false;
		}
		else {
			std::cout << "Error, please enter one of the operators given (+,-,*,/,^,sqrt)\n";
			fail = true;
		}

	}
}

