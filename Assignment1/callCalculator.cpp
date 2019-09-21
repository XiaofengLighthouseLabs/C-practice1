//============================================================================
// Name        : Q3 callCalculator.cpp
// Author      : Xiaofeng Zhang  
// Version     :
// Copyright   : Your copyright notice
// Description : Write a program that computes the cost of a long-distance call
//               The cost of the call is determined according to the following rate schedule:
//               a) Any call started between 8:00 am and 6:00 pm, Monday through Friday, is billed at a rate of $0.40 per minute.
//               b) Any call starting before 8:00 am or after 6:00 pm, Monday through Friday, is charged at a rate of $0.25 per minute.
//               c) Any call started on a Saturday or Sunday is charged at a rate of $0.15 per minute.
//============================================================================

#include <iostream>
#include "callCalculator.h"
using namespace std;

int main() {

	char firLetter = 'F', secLetter = 'S', choice = 'Y', n = 'A';
	int  hr{0}, min{0};
	float mins{0};

	// create a CallCalculator object myCallCalculator
	CallCalculator myCallCalculator;
	cout << "***************************************************" << endl;
	cout << "/                                                 /" << endl;
	cout << "/           LONG DISTANCE CALL CALCULATOR         /" << endl;
	cout << "/                                                 /" << endl;
	cout << "***************************************************" << endl;
    cout << endl;
	// prompt and display day and time
	cout << "I will calculate the cost of your call: " << endl;
	do{
		myCallCalculator.setCallDay(firLetter, secLetter);
		myCallCalculator.setStartTime(hr, n, min);
		myCallCalculator.setCallMinutes(mins);
		//display cost of the call
		if(myCallCalculator.getCost() == -1){
			cout << "You entered something wrong. Please try again." << endl;
		}else{
			cout << "Your total call cost is: $" << myCallCalculator.getCost() << endl;
		}
		cout << "Do you want to continue? (Y / N) ";
		cin >> choice;
	} while (choice == 'Y' || choice == 'y'); //repleat the calculation if choice is yes
        cout << "Thank you! Bye!" << endl;
	return 0;
}
