/*
 * Shawn Neal
 * CS-210-Q5952-20EW5
 * June 7, 2020
 */

#include <iostream>
#include <memory>

#include "Investment.h"
#include "bankFunctions.h"

using namespace std;

int main() {
	// Open the program with empty snapshot
	printInvestmentSnapshot();
	// Capture user input and instantiate object
	shared_ptr<double> investmentAmount(new double(inputInvestment("Enter initial investment amount: ")));
	shared_ptr<double> interestRate(new double(inputInterestRate("Enter rate of interest: ")));
	shared_ptr<double> numberYears(new double(inputNumberYears("Enter investment duration (in years): ")));
	shared_ptr<double> depositAmount(new double(grabDepositAmout()));
	Investment myInvestment(*investmentAmount, *interestRate, *numberYears, *depositAmount);
	// Display updated snapshot
	printInvestmentSnapshot(myInvestment);
	// Print investment growth charts with and w/o monthly deposits
	printGrowth(myInvestment, false);
	cout << endl;
	printGrowth(myInvestment, true);
	cout << endl << endl << endl;
	// Display an options menu and loop
	investmentSimulation(myInvestment, investmentAmount, interestRate, numberYears, depositAmount);
	cout << endl << "Goodbye.";
	return 0;
}
