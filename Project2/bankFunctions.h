/*
 * Shawn Neal
 * CS-210-Q5952-20EW5
 * June, 7, 2020
 */

#ifndef BANKFUNCTIONS_H_
#define BANKFUNCTIONS_H_

//User Input
double getDouble(std::string t_prompt);
//Investment amount
double inputInvestment(std::string t_prompt);
//Monthly deposit amount
double inputDeposit(std::string t_prompt);
//Interest rate amount
double inputInterestRate(std::string t_prompt);
// Years amount
double inputNumberYears(std::string t_prompt);
//Prompt for deposit amount
double grabDepositAmout();
//Print horizontal border
void printHorizontalBorder(int t_length, char t_printChar);
//Print empty snapshot
void printHorizontalBorder(int t_length, char t_printChar);
//Print empty investment
void printInvestmentSnapshot();
//Print investment attribute snapshot
void printInvestmentSnapshot(Investment& t_investment);
//Print growth
void printGrowth(Investment& t_investment, bool t_withMonthly=false);
//User sim function
void investmentSimulation(	Investment& t_investment,
							std::shared_ptr<double> t_investmentAmount,
							std::shared_ptr<double> t_interestRate,
							std::shared_ptr<double> t_numberYears,
							std::shared_ptr<double> t_depositAmount);
#endif /* BANKFUNCTIONS_H_ */
