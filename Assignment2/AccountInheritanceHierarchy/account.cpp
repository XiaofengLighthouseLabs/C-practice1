/*
 * account.cpp
 *
 *  Created on: Jul 12, 2019
 *  	Author: Xiaofeng Zhang
 */

#include <iostream>
#include <string>
#include "account.h"
using namespace std;

//Account constructor
Account :: Account(const string &fName, const string &lName, double iBalance)
:firstName(fName), lastName(lName)
{
	setInitialBalance(iBalance);
}

// set initial balance
void Account :: setInitialBalance(double iBalance){
	if(iBalance >= 0){
		balance = iBalance;
	}else{
		balance = 0;
		cout << "Invalid enter! Initial balance should be greater than or equal to 0.0." << endl;
	}
}

// get balance
double Account :: getBalance() const{
	return balance;
}

//credit function
bool Account :: credit(double creditAmount){
	bool transaction = false;
	if(creditAmount >= 0){
		balance = balance  + creditAmount;
		transaction = true;
	} else{
		cout << "Invalid credit amount." << endl;
	}
	return transaction;
}
//debit function
bool Account :: debit(double debitAmount){
	bool transaction = false;
	if(debitAmount >= 0){
		if(debitAmount <= getBalance()){
			balance = balance - debitAmount;
			transaction = true;
		}else{
			cout << "Error: Debit amount exceeded account balance." << endl;
		}
	}else{
		cout << "Error: Invalid debit amount." << endl;
	}
	return transaction;
}

//set name function
void Account :: setFirstName(const string &fName){
	firstName = fName;
}
void Account:: setLastName(const string &lName){
	lastName = lName;
}

//get name function
string Account ::getFirstName() const{
	return firstName;
}
string Account :: getLastName() const{
	return lastName;
}
//print Account object
void Account :: print() const{
	cout << "Updated Account Information:" << endl;;
    cout << "Account First Name: "<< getFirstName() << endl;
    cout << "Account Last Name: "<< getLastName() << endl;
    cout << "Account Current Balance is: " << getBalance() << endl;

}
