//============================================================================
// Name        : q3AccountInheritanceHierarchy.cpp
// Author      : Xiaofeng Zhang
// Version     :
// Copyright   : Your copyright notice
// Description : AccountInheritanceHierarchy
//============================================================================

#include <iostream>
#include <string>
#include <iomanip>
#include "savingAccount.h"
#include "checkingAccount.h"
using namespace std;

int main() {
	string fName, lName;
	double iBalance{0}, creditAmount{0}, debitAmount{0}, rate{0}, fee{0};
	int  choose;
	char testChoose;

	Account account1{fName, lName, iBalance};
	SavingAccount account2{fName, lName, iBalance, rate};
	CheckingAccount account3{fName, lName, iBalance, fee};

	cout << fixed << setprecision(2);
	do{
		cout << "A Test Account Class. " << endl;
		cout << "B Test SavingAccount Class. " << endl;
		cout << "C Test CheckingAccount Class. " << endl;
		cout << "D Finish Test. " << endl;
		cout << "choose a class to test: ";
		cin >> testChoose;

		switch(testChoose){
		case 'A':
		case 'a':
			cin.clear();
			cin.ignore();
			//test Account class using object acocunt1
			cout << "Please enter account1 first name: ";
			getline (cin, fName);
			account1.setFirstName(fName);
			cout << "Please enter account1 last name: ";
			getline (cin, lName);
			account1.setLastName(lName);
			do{
				cout << "Please enter account1 initial balance: ";
				cin >> iBalance;
				if(!cin){
					cin.clear();
					cin.ignore();
					cout << "Invalid enter. Please enter numbers." << endl;
				}
				account1.setInitialBalance(iBalance);
			}while(!iBalance);

			cout << "Account1 information: " << endl;
			cout << "Account1 First Name: " << account1.getFirstName() << endl;
			cout << "Account1 Last Name: " << account1.getLastName() << endl;
			cout << "Account1 Initial Balance: " << account1.getBalance() << endl;

			do{
				cout << "Menu\n" << "1. Credit\n" << "2. Debit\n" << "3. Quit\n";
				cout << "Please enter your choice: ";
				cin >> choose;
				switch(choose){
				case 1:
					do{
						cout << "Enter credit amount: ";
						cin >> creditAmount;
						if(!cin){
							cin.clear();
							cin.ignore();
							cout << "Invalid enter. Please enter numbers." << endl;
						}
					}while(creditAmount < 0);
					account1.credit(creditAmount);
					account1.getBalance();
					account1.print();
					break;
				case 2:
					do{
						cout << "Enter withdraw amount: ";
						cin >> debitAmount;
						if(!cin){
							cin.clear();
							cin.ignore();
							cout << "Invalid enter. Please enter numbers." << endl;
						}
					}while(debitAmount < 0);

					account1.debit(debitAmount);
					account1.getBalance();
					account1.print();
					break;
				case 3:
					cout << "Thanks! Bye!\n";
					break;
				default:
					cin.clear();
					cin.ignore();
					cout << "Please enter the right number." << endl;
				}

			}while(choose != 3);

			cin.clear();
			cin.ignore();
			break;
		case 'B':
		case 'b':
			cin.clear();
			cin.ignore();
			//test SavingAccount class using object acocunt2
			cout << "Please enter account2 first name: ";
			getline (cin, fName);
			account2.setFirstName(fName);
			cout << "Please enter account2 last name: ";
			getline (cin, lName);
			account2.setLastName(lName);
			do{
				cout << "Please enter account2 initial balance: ";
				cin >> iBalance;
				if(!cin){
					cin.clear();
					cin.ignore();
					cout << "Invalid enter. Please enter numbers." << endl;
				}
				account2.setInitialBalance(iBalance);
			}while(!iBalance);

			do{
				cout << "Please enter account2 initial value for interest rate (0 - 1): ";
				cin >> rate;
				if(!cin){
					cin.clear();
					cin.ignore();
					cout << "Invalid enter. Please enter numbers." << endl;
				}
				account2.setInterestRate(rate);
			}while(rate < 0 || rate > 1);

			cout << "Account2 information: " << endl;
			cout << "Account2 First Name: " << account2.getFirstName() << endl;
			cout << "Account2 Last Name: " << account2.getLastName() << endl;
			cout << "Account2 Initial Balance: " << account2.getBalance() << endl;
			cout << "Account2 Initial Rate Value: " << account2.getRate() << endl;

			do{
				cout << "Menu\n" << "1. Credit\n" << "2. Debit\n" << "3. Quit\n";
				cout << "Please enter your choice: ";
				cin >> choose;
				switch(choose){
				case 1:
					do{
						cout << "Enter credit amount: ";
						cin >> creditAmount;
						if(!cin){
							cin.clear();
							cin.ignore();
							cout << "Invalid enter. Please enter numbers." << endl;
						}
					}while(creditAmount < 0);
					account2.credit(creditAmount);
					account2.getBalance();
					account2.print();
					break;
				case 2:
					do{
						cout << "Enter withdraw amount: ";
						cin >> debitAmount;
						if(!cin){
							cin.clear();
							cin.ignore();
							cout << "Invalid enter. Please enter numbers." << endl;
						}
					}while(debitAmount < 0);

					account2.debit(debitAmount);
					account2.getBalance();
					account2.print();
					break;
				case 3:
					cout << "Thanks! Bye!\n";
					break;
				default:
					cin.clear();
					cin.ignore();
					cout << "Please enter the right number." << endl;
				}

			}while(choose != 3);

			cin.clear();
			cin.ignore();
			break;

		case 'C':
		case 'c':
			cin.clear();
			cin.ignore();
			//test CheckingAccount class using object acocunt3
			cout << "Please enter account3 first name: ";
			getline (cin, fName);
			account3.setFirstName(fName);
			cout << "Please enter account3 last name: ";
			getline (cin, lName);
			account3.setLastName(lName);
			do{
				cout << "Please enter account3 initial balance: ";
				cin >> iBalance;
				if(!cin){
					cin.clear();
					cin.ignore();
					cout << "Invalid enter. Please enter numbers." << endl;
				}
				account3.setInitialBalance(iBalance);
			}while(!iBalance);

			do{
				cout << "Please enter account3 charged fee: ";
				cin >> fee;
				if(!cin){
					cin.clear();
					cin.ignore();
					cout << "Invalid enter. Please enter numbers." << endl;
				}
				account3.setChargedFee(fee);
			}while(fee < 0);

			cout << "Account3 information: " << endl;
			cout << "Account3 First Name: " << account3.getFirstName() << endl;
			cout << "Account3 Last Name: " << account3.getLastName() << endl;
			cout << "Account3 Initial Balance: " << account3.getBalance() << endl;
			cout << "Account3 Charged Fee: " << account3.getChargedFee() << endl;

			do{
				cout << "Menu\n" << "1. Credit\n" << "2. Debit\n" << "3. Quit\n";
				cout << "Please enter your choice: ";
				cin >> choose;
				switch(choose){
				case 1:
					do{
						cout << "Enter credit amount: ";
						cin >> creditAmount;
						if(!cin){
							cin.clear();
							cin.ignore();
							cout << "Invalid enter. Please enter numbers." << endl;
						}
					}while(creditAmount < 0);
					account3.credit(creditAmount);
					account3.print();
					break;
				case 2:
					do{
						cout << "Enter withdraw amount: ";
						cin >> debitAmount;
						if(!cin){
							cin.clear();
							cin.ignore();
							cout << "Invalid enter. Please enter numbers." << endl;
						}
					}while(debitAmount < 0);

					account3.debit(debitAmount);
					account3.print();
					break;
				case 3:
					cout << "Thanks! Bye!\n";
					break;
				default:
					cin.clear();
					cin.ignore();
					cout << "Please enter the right number." << endl;
				}

			}while(choose != 3);
			cin.clear();
			cin.ignore();
			break;

		case'D':
		case'd':
			cout << "Finish the test." << endl;
		}
	}while(testChoose != 'D' && testChoose != 'd');



return 0;
}
