/*
 * Shawn Neal
 * CS-210-Q5952-20EW5
 * June, 7, 2020
 */

#ifndef INVESTMENT_H_
#define INVESTMENT_H_

class Investment {
	public:
		//Default constructor
		Investment();
		//Parameterized Constructors
		Investment(double t_investmentAmount, double t_interestRate, double t_numberYears, double t_monthlyDeposit=0);

		//Getters
		double getInvestmentAmount() const;
		double getMonthlyDeposit() const;
		double getInterestRate() const;
		double getNumberYears() const;

		//Setters
		void setInvestmentAmount(double t_investmentAmount);
		void setMonthlyDeposit(double t_monthlyDeposit);
		void setInterestRate(double t_interestRate);
		void setNumberYears(double t_numberYears);
	private:
		double m_investmentAmount;
		double m_monthlyDeposit;
		double m_interestRate;
		double m_numberYears;

};

#endif /* INVESTMENT_H_ */
