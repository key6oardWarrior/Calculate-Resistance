#include <iostream>
#include <string>
using namespace std;

class Calculator {
	int numOfResistors;

public:
	Calculator();
	double sHelper(double totR, bool isER);
	double pHelper(double totR, bool isER);
	double equivalentResistance(double totR);
};

double Calculator::sHelper(double totR, bool isER) {
	double resistor;

	cout << "What is the value of this resistor (AB * 10^C) ";
	cin >> resistor;

	totR += resistor;
	numOfResistors--;

	if(numOfResistors <= 0) {
		if(isER == false) { // base case
			cout << "Total Resistance of this circuit is: " << totR;
			return totR;
		} else {
			return totR;
		}
	}
	return sHelper(totR, isER);
}

double Calculator::pHelper(double totR, bool isER) {
	double resistor;

	cout << "What is the value of this resistor (AB * 10^C) ";
	cin >> resistor;

	totR += 1 / resistor;
	numOfResistors--;

	if(numOfResistors <= 0) {
		if(isER == false) { // base case
			cout << "Total Resistance of this circuit is: " << totR;
			return totR;
		} else {
			return totR;
		}
	}
	return pHelper(totR, isER);
}

double Calculator::equivalentResistance(double totR) {
	char x;
	numOfResistors = 2;

	cout << "Is this part of the circuit in parallel? Y/N ";
	cin >> x;

	if(x == 'Y') {
		totR += pHelper(0, true);
	} else {
		totR += sHelper(0, true);
	}

	cout << "Are there more calculations needed to find the equivalent resistance? Y/N ";
	cin >> x;

	if(x == 'N') { // base case
		return totR;
	} else {
		return equivalentResistance(totR);
	}
}

Calculator::Calculator() {
	char x;

	cout << "Do you want to find Total resistance (T) or Equivalent resistance (E)? T/E ";
	cin >> x;

	if(x == 'E') {
		double totR = 0.0;

		totR = equivalentResistance(0);
		cout << "The equivalent resistance is: " << totR << "\nRestart to run again.";
		while(true) {}
	}

	cout << "How many resistors are there? ";
	cin >> numOfResistors;

	if(numOfResistors == 0) {
		cout << "Resistor value must be greater than 0. Please restart program";
		while(true) {}
	}

	cout << "Is the circuit in parallel? Y/N ";
	cin >> x;

	if(x == 'Y') {
		pHelper(0, false);
	} else {
		sHelper(0, false);
	}
	while(true) {}
}

int main() {
	Calculator* cal = new Calculator();
	return 0;
}