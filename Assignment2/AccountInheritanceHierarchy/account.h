/*
 * account.h
 *
 *  Created on: Jul 12, 2019
 *     Author: Xiaofeng Zhang
 */

#ifndef ACCOUNT_H_
#define ACCOUNT_H_

#include <iostream>
#include <string>
using namespace std;
class Account{
private:
	string firstName, lastName;
	double balance{0};
public:
	Account(const string &, const string &, double iBalance);
	void setInitialBalance(double iBalance);  //set initial balance;

	bool credit(double creditAmount);  //set credit

	bool debit(double debitAmount);   //set debit

	double getBalance() const;    //return balance

	void setFirstName(const string &);  //set first name
	void setLastName(const string &);    //set last name

	string getFirstName() const;  //get first name
	string getLastName() const;   //get last name
	void print() const;  //print object
};



#endif /* ACCOUNT_H_ */
