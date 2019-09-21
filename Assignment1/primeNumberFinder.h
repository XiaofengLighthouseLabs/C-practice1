/*
 * primeNumberFinder.h
 *
 *  Created on: May 30, 2019
 *      Author: Xiaofeng
 */

#ifndef PRIMENUMBERFINDER_H_
#define PRIMENUMBERFINDER_H_

#include <iostream>
using namespace std;

class PrimeNumberFinder {
private:
	int num1, num2;

public:
	void setNum1(int number1){     //number1 is a positive integer
		if(number1 > 0){
			num1 = number1;
		} else{
			number1 = 1;
			cout << "Please enter a positive integer." << endl;
		}
	}
	void setNum2(int number2){     // number2 is a positive integer
		if(number2 > 0 ){
			num2 = number2;
		} else{
			number2 = 1;
			cout << "Please enter a positive integer." << endl;
		}
	}
	// get num1 and num2
	int getNum1() const{
		return num1;
	}
	int getNum2() const{
		return num2;
	}
     //member function to display prime numbers
	void primeFinder(int n1, int n2){
		int tmp;
		if(n1 > n2){
				tmp = n1;
				n1 = n2;
				n2 = tmp;
			}
		if(n1 == 1){
			n1 = n1 + 1;
		}
		for(int i = n1; i <= n2; i++){
			int prime = 0;
			for (int j = 2; j  < i; j++){
				if(i % j == 0){
					prime = 1;
					break;
				}
			}
			if(prime == 0){
				cout << i << " ";
			}
		}
	}
};

#endif /* PRIMENUMBERFINDER_H_ */
