/*
 * Shawn Neal
 * CS-210-Q5952-20EW5
 * June 7, 2020
 */

#include <iostream>
#include <stdexcept>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <memory>
#include "Investment.h"

using namespace std;

//Function for processing user input
double getDouble(string t_prompt) {
	//Bool for exception handling
	bool validEntry;
	//Input for conversion
	string userEntryAsString;
	//Input double for return
	double userEntry;

	//Exception handling for user entry
	do {
		validEntry = true;
		try {
			cout << t_prompt << endl;
			cin >> userEntryAsString;
			userEntry = stod(userEntryAsString);
		}

		// Catch an invalid argument
		catch (invalid_argument& excpt) {
            cout << "Invalid Input. Enter a number." << endl << endl;
            validEntry = false;
	    }
	} while (!validEntry);
	return userEntry;
}

//function for investment amount
double inputInvestment(string t_prompt) {
	//Bool for exception handling
	bool validEntry;
	//Investment amount
	double investmentAmount;


	do {
		validEntry = true;
		try {
			investmentAmount = getDouble(t_prompt);
			if (investmentAmount <= 0) {
				throw runtime_error("Invalid Input. Enter a amount greater than $0.");
			}
		}
		// Catch error if investment =< 0
		catch(runtime_error& excpt) {
			cout << excpt.what() << endl << endl;
			validEntry = false;
		}

	} while(!validEntry);

	return investmentAmount;
}

//Function for deposit
double inputDeposit(string t_prompt) {
	// bool for exception handling
	bool validEntry;
	//deposit amount
	double depositAmount;

	do {
		validEntry = true;
		try {
			depositAmount = getDouble(t_prompt);
			if (depositAmount <= 0) {
				throw runtime_error("Invalid Input. Enter a amount greater than $0.");
			}
		}
		// Catch a deposit amount =< 0
		catch(runtime_error& excpt) {
			cout << excpt.what() << endl << endl;
			validEntry = false;
		}

	} while(!validEntry);

	return depositAmount;
}

//function for interest rate
double inputInterestRate(string t_prompt) {
	//bool for exception handling
	bool validEntry;
	// Interest Rate
	double interestRate;


	do {
		validEntry = true;
		try {
			interestRate = getDouble(t_prompt);
			if (interestRate < 0) {
				throw runtime_error("Invalid input. Enter a non-negative interest rate.");
			}
		}
		// Catch an interest rate < 0
		catch(runtime_error& excpt) {
			cout << excpt.what() << endl << endl;
			validEntry = false;
		}

	} while(!validEntry);

	return interestRate;
}

// Function for number of years
double inputNumberYears(string t_prompt) {
	//bool for exception handling
	bool validEntry;
	//Years
	double numberYears;

	do {
		validEntry = true;
		try {
			numberYears = getDouble(t_prompt);
			if (numberYears < 1) {
				throw runtime_error("Invalid entry. Please enter 1 year or more.");
			}
		}
		// Catch years < 1
		catch(runtime_error& excpt) {
			cout << excpt.what() << endl << endl;
			validEntry = false;
		}

	} while(!validEntry);

	return numberYears;
}

// function for deposit amount
double grabDepositAmout() {
	//bool for exception handling
	bool validEntry;
	//deposit amount
	double depositAmount;
	char userEntry;

	do {
		validEntry = true;		// assume initially the entry will be valid
		try {
			cout << "Would you like to add a monthly deposit (Y/N)? ";
			cin >> userEntry;
			if ((userEntry != 'N') && (userEntry != 'n') && (userEntry != 'Y') && (userEntry != 'y')) {
				throw runtime_error("Invalid Input. Enter Y or N.");
			}
		}
		// Catch invalid input
		catch(runtime_error& excpt) {
			cout << excpt.what() << endl << endl;
			validEntry = false;
		}

	} while(!validEntry);

	if((userEntry == 'Y') || (userEntry == 'y')) {
		depositAmount = inputDeposit("Enter your deposit amount.");
	}
	else {
		depositAmount = 0;
	}
	return depositAmount;
}

//Function to print border
void printHorizontalBorder(int t_length, char t_printChar) {
	for (int i = 0; i < t_length; ++i) {
			cout << t_printChar;
		}
	return;
}

//Function to display attributes of investment
void printInvestmentSnapshot() {
	const int MENU_WIDTH = 35;
	string menuTitle = "Data Input";
	char menuChar = '*';
	printHorizontalBorder(MENU_WIDTH, menuChar);
	cout << endl;
	printHorizontalBorder((((MENU_WIDTH - menuTitle.length()) / 2) - 1), menuChar);
	cout << " " << menuTitle << " ";
	printHorizontalBorder((((MENU_WIDTH - menuTitle.length()) / 2)), menuChar);
	cout << endl;
	cout << "Initial Investment Amount: " << endl;
	cout << "Monthly Deposit: " << endl;
	cout << "Annual Interest: " << endl;
	cout << "Number of Years: " << endl;
	system("pause");
	return;
}

//Function to print investment snapshot
void printInvestmentSnapshot(Investment& t_investment) {
	const int MENU_WIDTH = 35;
	string menuTitle = "Data Input";
	char menuChar = '*';
	printHorizontalBorder(MENU_WIDTH, menuChar);
	cout << endl;
	printHorizontalBorder((((MENU_WIDTH - menuTitle.length()) / 2) - 1), menuChar);
	cout << " " << menuTitle << " ";
	printHorizontalBorder((((MENU_WIDTH - menuTitle.length()) / 2)), menuChar);
	cout << endl;
	cout << "Initial Investment Amount: $" << t_investment.getInvestmentAmount() << endl;
	cout << "Monthly Deposit: $" << t_investment.getMonthlyDeposit() << endl;
	cout << "Annual Interest: " << t_investment.getInterestRate() << "%" << endl;
	cout << "Number of Years: " << t_investment.getNumberYears() << endl;
	system("pause");
	return;
}

//function to display growth output
void printGrowth(Investment& t_investment, bool t_withMonthly) {
	const int MENU_WIDTH = 75;
	const double MONTHS_IN_YEAR = 12.00;
	string menuTitleNoDeposit = "Balance and Interest - No Additional Deposits";
	string menuTitleWithDeposits = "Balance and Interest - With Monthly Deposits";
	string menuTitle;

	if(t_withMonthly) {
		menuTitle = menuTitleWithDeposits;
	}
	else {
		menuTitle = menuTitleNoDeposit;
	}

	int menuTitleWhiteSpace = MENU_WIDTH - menuTitle.length();
	string headerOne = "Year";
	string headerTwo = "Interest Earned";
	string headerThree = "Year End Balance";
	char menuChar = '=';
	char outputChar = ' ';

	// Print top border for title
	printHorizontalBorder(MENU_WIDTH, menuChar);
	cout << endl;
	// Print leading whitespace for title
	printHorizontalBorder((menuTitleWhiteSpace / 2), outputChar);
	// Print menu title
	cout << menuTitle;
	// Print trailing whitespace for title
	printHorizontalBorder((menuTitleWhiteSpace / 2), outputChar);
	cout << endl;
	// Print bottom border for title
	printHorizontalBorder(MENU_WIDTH, menuChar);
	cout << endl;
	// Print column one header
	cout << "\t" << headerOne;
	// Print column two header
	cout << "\t\t" << headerTwo;
	// Print column three header
	cout << "\t\t" << headerThree;
	cout << endl;

	// set investment amount as beginning amount
	double begBalance = t_investment.getInvestmentAmount();
	for (int i = 0; i < t_investment.getNumberYears(); ++i) {
		int year = (i + 1);
		double interestRate = t_investment.getInterestRate() / 100.00;
		double interestEarned;
		double totalInterest;
		double endBalance;
		double monthEndBalance;
		if(t_withMonthly) {
			interestEarned = 0;
			totalInterest = 0;
			interestRate = interestRate / MONTHS_IN_YEAR;
			for (int i = 0; i < MONTHS_IN_YEAR; ++i) {
				begBalance += t_investment.getMonthlyDeposit();
				interestEarned = (begBalance * (1 + interestRate)) - begBalance;
				monthEndBalance = begBalance + interestEarned;
				begBalance = monthEndBalance;
				totalInterest += interestEarned;
			}
		}
		else {
			totalInterest = (begBalance * (1 + interestRate)) - begBalance;
		}

		if(t_withMonthly) {
			endBalance = begBalance;
		}
		else {
			endBalance = begBalance + totalInterest;
			begBalance = endBalance;
		}
		// Print column one
		cout << "\t" << year;
		// Print column two
		cout << "\t\t" << "$" << setprecision(2) << fixed << totalInterest;
		// Print column three
		cout << "\t\t\t" << "$" << setprecision(2) << fixed << endBalance;
		cout << endl;
	}
	return;
}

//Function to display options menu
void printOptions() {
	string optionsMenu = 	"What would you like to do?\n"
							"1 - Change Initial Investment Amount\n"
							"2 - Change Monthly Deposit Amount\n"
							"3 - Change Interest Rate\n"
							"4 - Change Investment Duration (years)\n"
							"5 - Print Investment Growth - No Deposit\n"
							"6 - Print Investment Growth - With Deposits\n"
							"7 - Quit.";
	const int MENU_WIDTH = 50;
	const char MENU_CHAR = '*';
	printHorizontalBorder(MENU_WIDTH, MENU_CHAR);
	cout << endl;
	cout << optionsMenu;
	cout << endl;
	printHorizontalBorder(MENU_WIDTH, MENU_CHAR);
	cout << endl;
	return;
}

//Function for looping through menu functions
void investmentSimulation	(Investment& t_investment, std::shared_ptr<double> t_investmentAmount,
							std::shared_ptr<double> t_interestRate, std::shared_ptr<double> t_numberYears,
							std::shared_ptr<double> t_depositAmount) {

	//Bool for exception handling
	bool validEntry;
	//user input for conversion
	string userEntryAsString;	// store user input to convert to double
	//user input as int
	int userEntry = 0;

	//loop options until user selects quit
	while (userEntry != 7) {
		//exception handling
		do {
			validEntry = true;
			try {
				printOptions();
				cin >> userEntryAsString;
				userEntry = stoi(userEntryAsString);
				if((userEntry < 1) || (userEntry > 7)) {
					throw runtime_error("Invalid Input. Enter a number between 1 and 7");
				}
			}
			// Catch an invalid input
			catch(invalid_argument& excpt) {
				cout << "Invalid input, rnter a number." << endl << endl;
				validEntry = false;
			}
			catch (runtime_error& excpt) {
				cout << excpt.what() << endl << endl;
				validEntry = false;
			}
		} while(!validEntry);
		cout << endl;
			switch(userEntry) {
				case 1:
					// Print current snapshot
					printInvestmentSnapshot(t_investment);
					*t_investmentAmount = inputInvestment("Enter new investment amount: ");
					t_investment.setInvestmentAmount(*t_investmentAmount);
					// Print new snapshot
					printInvestmentSnapshot(t_investment);
					break;
				case 2:	// Change deposit amount
					// Print current snapshot
					printInvestmentSnapshot(t_investment);
					*t_depositAmount = inputDeposit("Enter new deposit amount: ");
					t_investment.setMonthlyDeposit(*t_depositAmount);
					// Print new snapshot
					printInvestmentSnapshot(t_investment);
					break;
				case 3:	// Change interest rate
					// Print current snapshot
					printInvestmentSnapshot(t_investment);
					*t_interestRate = inputInterestRate("Enter new interest rate: ");
					t_investment.setInterestRate(*t_interestRate);
					// Print new snapshot
					printInvestmentSnapshot(t_investment);
					break;
				case 4:	// Change investment duration
					// Print current snapshot
					printInvestmentSnapshot(t_investment);
					*t_numberYears = inputNumberYears("Enter new duration: ");
					t_investment.setNumberYears(*t_numberYears);
					// Print new snapshot
					printInvestmentSnapshot(t_investment);
					break;
				case 5:
					printGrowth(t_investment, false);
					cout << endl << endl;
					break;
				case 6:
					printGrowth(t_investment, true);
					cout << endl << endl;
					break;
				default:
					break;
		}
	}
	return;
}

