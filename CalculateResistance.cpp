#include <iostream>
#include <string>
using namespace std;

/*
Find the total resistance of any circuit.
*/
class Calculator {
	int numOfResistors;

public:
	Calculator();
	double sHelper(double &totR);
	double pHelper(double &totR);
	double equivalentResistance(double &totR);
};

/*
Find the resistance of a circuit in series
*/
double Calculator::sHelper(double &totR) {
	double resistor;

	cout << "What is the value of this resistor (AB * 10^C) ";
	cin >> resistor;

	totR += resistor;
	numOfResistors--;

	if(numOfResistors <= 0) { // base case
		return totR;
	}
	return sHelper(totR);
}

/*
Find the resistance of a circuit in parpallel
*/
double Calculator::pHelper(double &totR) {
	double resistor;

	cout << "What is the value of this resistor (AB * 10^C) ";
	cin >> resistor;

	totR += 1 / resistor;
	numOfResistors--;

	if(numOfResistors <= 0) { // base case
		return totR;
	}
	return pHelper(totR);
}

/*
Find the equivalent resistance of a circuit
*/
double Calculator::equivalentResistance(double &totR) {
	char x;

	cout << "Is this part of the circuit in parallel? Y/N ";
	cin >> x;

	cout << "How many resistors are there in this part of the circuit? ";
	cin >> numOfResistors;

	if(x == 'Y') {
		pHelper(totR);
	} else {
		sHelper(totR);
	}

	cout << "Are there more calculations needed to find the equivalent resistance? Y/N ";
	cin >> x;

	if(x == 'N') { // base case
		return totR;
	}
	return equivalentResistance(totR);
}

/*
Driver code. Take input and give the user output
*/
Calculator::Calculator() {
	char x;
	double totR = 0.0;

	cout << "Do you want to find Total resistance (T) or Equivalent resistance (E)? T/E ";
	cin >> x;

	if(x == 'E') {
		equivalentResistance(totR);
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
		pHelper(totR);
	} else {
		sHelper(totR);
	}

	cout << "The total resistance is: " << totR << "\nRestart to run again.";
	while(true) {}
}

int main() {
	Calculator* cal = new Calculator();
	delete cal;
	cal = nullptr;

	return 0;
}
