/*
 * checkingAccount.h
 *
 *  Created on: Jul 12, 2019
 *      Author: Xiaofeng Zhang
 */

#ifndef CHECKINGACCOUNT_H_
#define CHECKINGACCOUNT_H_

#include <iostream>
#include <string>
#include "account.h"
using namespace std;

class CheckingAccount : public Account{
private:
	double chargedFee;
public:
	explicit CheckingAccount(const string &fName, const string &lName, double iBalance, double fee)
	:Account(fName, lName, iBalance){
		setChargedFee(fee);
	}
	void setChargedFee(double fee){
		if(fee >= 0){
			chargedFee = fee;
		}else{
			cout << "Invalid enter! Initial fee should be greater than or equal to 0.0." << endl;
			fee = 0.0;
		}
	}
	double getChargedFee() const{
		return chargedFee;
	}

	bool credit(double creditAmount){
		return (Account :: credit(creditAmount  - chargedFee));

	}
	bool debit(double debitAmount){
		return (Account :: debit(debitAmount + chargedFee));
	}

	void print() const{
		Account :: print();
	}

};

#endif /* CHECKINGACCOUNT_H_ */
