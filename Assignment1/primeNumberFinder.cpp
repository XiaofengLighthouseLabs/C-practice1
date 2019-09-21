//============================================================================
// Name        : Q2 primeNumberFinder.cpp
// Author      : Xiaofeng Zhang  
// Version     :
// Copyright   : Your copyright notice
// Description : Write a program that finds and prints all of the prime numbers between 1 and 100. A prime number is a whole number greater
//				 than 1 whose only factors are 1 and itself. A factor is a whole numbers that can be divided evenly into another number.
//				 (for example, 2, 3, 5, 7, 11, 13, 17, 19, 23, …).
//============================================================================

#include <iostream>
#include "primeNumberFinder.h"
using namespace std;

int main() {
	int number1, number2;
	int num1, num2;
	char choice;

	//create an object myPrimeNumberFinder
	PrimeNumberFinder myPrimeNumberFinder;

	cout << "***************************************************" << endl;
	cout << "/                                                 /" << endl;
	cout << "/               PRIME NUMBER FINDER               /" << endl;
	cout << "/                                                 /" << endl;
	cout << "***************************************************" << endl;
	cout << endl;
	cout << "Enter two different positive integers. I will print prime numbers between them." << endl;
	do{
		do {
			cout << "The first number: ";   //user enter first validated number
			cin >> number1;
			if(cin.fail()){
				cin.clear();
				cin.ignore();
			}
			myPrimeNumberFinder.setNum1(number1);
			fflush(stdin);
		}while(!(number1 > 0));

		do{
			cout << "The second number: ";    //user enter second validated number
			cin >> number2;
			if(cin.fail()){
				cin.clear();
				cin.ignore();
			}
			myPrimeNumberFinder.setNum2(number2);
			fflush(stdin);
		}while(!(number2 > 0));

		num1 = myPrimeNumberFinder.getNum1();
		num2 = myPrimeNumberFinder.getNum2();

		cout << "The prime numbers between " << num1 << " and " << num2 << " are: " << endl;
		myPrimeNumberFinder.primeFinder(num1, num2);      //use member function to find prime numbers
		cout << "\nDo you want to try again? (Y / y to continue, else quit the program)" << endl;
		cin >> choice;
	} while(choice == 'Y' || choice == 'y'); // user choose y to continue

	cout << "Thank you. Bye! " << endl;


	return 0;
}
