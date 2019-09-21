/*
 * callCalculator.h
 *
 *  Created on: May 30, 2019
 *      Author: Xiaofeng
 */

#ifndef CALLCALCULATOR_H_
#define CALLCALCULATOR_H_

#include <iostream>
#include <iomanip>
using namespace std;

class CallCalculator{
private:
	char dayFirLetter, daySecLetter, choice;
	float cost{0}, callInMinutes{0};
	int startHour{0}, startMinute{0};

public:
	// functions to get call's day and time
	void setCallDay(char first, char second){
		do{
			cout << "Please enter first two letters of the day of the call (Mo, Tu, We, Th, Fr, Sa, Su): ";
			cin >> first >> second;
			if (((first =='M'|| first == 'm') && (second == 'O' || second == 'o')) || ((first =='T'|| first == 't') && (second == 'U' || second == 'u')) ||
					((first =='W'|| first == 'w') && (second == 'E' || second == 'e')) || ((first =='T'|| first == 't') && (second == 'H' || second == 'h'))
					||( (first =='F'|| first == 'f') && (second == 'R' || second == 'r')) || ((first =='S'|| first == 's') && (second == 'A' || second == 'a')) ||
					((first =='S'|| first == 's') && (second == 'U' || second == 'u'))){
				dayFirLetter = first;
				daySecLetter = second;
			}else {
				cout << "Try again." << endl;
				cin.clear();
				cin.ignore();
				first = 'A';
			}
		} while (first == 'A');

	}
	char getFirstLetter() const{
		return dayFirLetter;
	}
	char getSecondLetter() const{
		return daySecLetter;
	}

	void setStartTime(int hr, char n, int min){
		do{

			cout << "Please enter the time the call started in 24-hour notation (HH : MM): ";
			cin >> hr >> n >> min;
			if((hr >= 0 && hr <=23) && (min >=0 && min <=59) && (n == ':')){
				startHour = hr;
				startMinute = min;
			} else {
				cout << "Try again." << endl;
				cin.clear();
				cin.ignore();
				hr = -1;
			}
		} while(hr == -1);
		fflush(stdin);

	}
	int getHour() const{
		return startHour;
	}
	int getMin() const{
		return startMinute;
	}

	void setCallMinutes(int mins){
		do{
			cout << "Please enter the length of the call in minutes (non negative integer): ";
			cin >> mins;
			if((!cin) || (mins < 0)){
				cin.clear();
				cin.ignore();
				cout << "Try again." << endl;
				mins = -1;
			}else{
				callInMinutes = mins;
			}
		}while(mins == -1);
		fflush(stdin);
	}
	//calculate the cost of the call
	float getCost(){
		cout << setprecision( 2 ) << fixed;
		if(((dayFirLetter == 'M' || dayFirLetter == 'm')&&(daySecLetter == 'O' || daySecLetter == 'o'))||
				((dayFirLetter == 'T' || dayFirLetter == 't')&&(daySecLetter == 'U' || daySecLetter == 'u'))||
				((dayFirLetter == 'W' || dayFirLetter == 'w')&&(daySecLetter == 'E' || daySecLetter == 'e'))||
				((dayFirLetter == 'T' || dayFirLetter == 't')&&(daySecLetter == 'H' || daySecLetter == 'h'))||
				((dayFirLetter == 'F' || dayFirLetter == 'f')&&(daySecLetter == 'R' || daySecLetter == 'r'))){
			if(startHour >= 8 && startHour <18 && (startMinute >= 0) && (startMinute <= 59)){
				return cost = callInMinutes * 0.4;
			}
			else if (((startHour >= 0 && startHour < 8) || (startHour >= 18 && startHour <= 23)) && (startMinute >= 0) && (startMinute <= 59)){
				return cost = callInMinutes * 0.25;
			}
			else{
				return -1;
			}
		}
		else if (((dayFirLetter == 'S' || dayFirLetter == 's')&&(daySecLetter == 'A' || daySecLetter == 'a'))||
				((dayFirLetter == 'S' || dayFirLetter == 's')&&(daySecLetter == 'U' || daySecLetter == 'u'))){
			if((startHour >= 0 && startHour <= 23) && (startMinute >= 0) && (startMinute <= 59)){
				return cost = callInMinutes * 0.15;
			}
			else{
				return -1;
			}
		}
		else{
			return -1;
		}
	}

};



#endif /* CALLCALCULATOR_H_ */
