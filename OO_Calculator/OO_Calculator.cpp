/*
2023.2.7
Alessandro Accardi
Calculator with OOP
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

class Calculator {
public:
	double num1;
	double num2;
	char operation;
	double mem;
	string ans;

	Calculator();
	~Calculator();

	void Add();
	void Subtract();
	void Multiply();
	void Divide();
	void Pow();
};

Calculator::Calculator() {
	num1 = 0;
	num2 = 0;
	cout << "Welcome to the calculator!\nAvailable operations: + - * / ^\nType 'C0' to clear memory and '0 0 0' to exit\n";
	cin >> num1 >> operation >> num2;
	mem = num1;
	do {
		if (operation == '+') {
			Add();
		}
		else if (operation == '-') {
			Subtract();
		}
		else if (operation == '*') {
			Multiply();
		}
		else if (operation == '/') {
			Divide();
		}
		else if (operation == '^') {
			Pow();
		}
		else if (operation == 'C') {
			cout << "Memory Cleared\n";
			cin >> num1 >> operation >> num2;
			mem = num1;
			continue;
		}
		else if (operation == '0') {
			break;
		}
		cin >> operation >> num2;
	} while (operation != '0');
}

Calculator::~Calculator() {
	cout << "Thank you for using the calculator!\nShutting down...";
}

void Calculator::Add() {
	mem = mem + num2;
	cout << "= " << mem <<"\n";
}

void Calculator::Subtract() {
	mem = mem - num2;
	cout << "= " << mem << "\n";
}

void Calculator::Multiply() {
	mem = mem * num2;
	cout << "= " << mem << "\n";
}

void Calculator::Divide() {
	mem = mem / num2;
	cout << "= " << mem << "\n";
}

void Calculator::Pow() {
	mem = pow(mem,num2);
	cout << "= " << mem << "\n";
}

int main()
{
	Calculator calc;
}
