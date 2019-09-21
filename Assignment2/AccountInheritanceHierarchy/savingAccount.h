/*
 * savingAccount.h
 *
 *  Created on: Jul 12, 2019
 *      Author: Xiaofeng Zhang
 */

#ifndef SAVINGACCOUNT_H_
#define SAVINGACCOUNT_H_

#include <iostream>
#include <string>
#include "account.h"
using namespace std;

class SavingAccount : public Account{
private:
	double interestRate;
public:
	explicit SavingAccount(const string &fName, const string &lName, double iBalance, double rate)
	  : Account (fName, lName, iBalance){
		setInterestRate(rate);
	}
	// set interest rate
	void setInterestRate(double rate){
		if(rate >= 0.0 && rate <= 1.0){
			interestRate = rate;
		} else{
			cout << "Error: Invalid interest rate." << endl;
			rate = -1;
		}
	}
	// get interest rate
	double getRate() const{
		return interestRate;
	}
	//interest calculation function
	double interestCalculate() const{
        return (Account :: getBalance() * interestRate);
	}

	void print() const{
		Account :: print();
		cout << "The Interest Amount is: " << interestCalculate() << endl;
	}

};


#endif /* SAVINGACCOUNT_H_ */
