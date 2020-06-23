/*
 * Shawn Neal
 * CS-210-Q5952-20EW5
 * June 7, 2020
 */

#include <iostream>
#include <memory>
#include "Investment.h"

//Default constructor
Investment::Investment() {
	this->m_investmentAmount = 0;
	this->m_monthlyDeposit = 0;
	this->m_interestRate = 0;
	this->m_numberYears = 1;
}

Investment::Investment(double t_investmentAmount, double t_interestRate, double t_numberYears, double t_monthlyDeposit) {
	this->m_investmentAmount = t_investmentAmount;
	this->m_monthlyDeposit = t_monthlyDeposit;
	this->m_interestRate = t_interestRate;
	this->m_numberYears = t_numberYears;
}

// Getters
double Investment::getInvestmentAmount() const {
	return this->m_investmentAmount;
}

double Investment::getInterestRate() const {
	return this->m_interestRate;
}

double Investment::getNumberYears() const {
	return this->m_numberYears;
}

double Investment::getMonthlyDeposit() const {
	return this->m_monthlyDeposit;
}

// Setters
void Investment::setInvestmentAmount(double t_investmentAmount) {
	this->m_investmentAmount = t_investmentAmount;
}


void Investment::setInterestRate(double t_interestRate) {
	this->m_interestRate = t_interestRate;
}

void Investment::setNumberYears(double t_numberYears) {
	this->m_numberYears = t_numberYears;
}

void Investment::setMonthlyDeposit(double t_monthlyDeposit) {
	this->m_monthlyDeposit = t_monthlyDeposit;
}