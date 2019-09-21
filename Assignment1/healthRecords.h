/*
 * healthRecords.h
 *
 *  Created on: May 30, 2019
 *      Author: Xiaofeng
 */

#ifndef HEALTHRECORDS_H_
#define HEALTHRECORDS_H_
#include <iostream>
#include <ctime>
#include <string>
using namespace std;

class HealthProfile{
private:
	string firstName, lastName, gender;
	float height, weight;
	int dobMon, dobDay, dobYear;

public:
	//  HealthProfile constructor initializes the class's data members
	explicit HealthProfile(string fName, string lName, string gen, int year, int mon, int day, float h, float w)
	:firstName(fName), lastName(lName), gender(gen){
		if(year > 0){
			dobYear = year;
		}
		if(mon >=1 && mon <= 12){
			dobMon = mon;
		}
		if(day >= 1 && day <= 31){
			dobDay = day;
		}
		if(h > 0){
			height = h;
		}
		if(weight > 0){
			weight = w;
		}
	}
	// functions to set and get each data member
	void setFirstName(string fName){
		firstName = fName;
	}
	void setLastName(string lName){
		lastName = lName;
	}
	void setGender(string gen){
		gender = gen;
	}
	void setDobDate(int year, int mon, int day, char n){
		do{

			cout << "Please enter your date of birth (dd/mm/yyyy): ";
			cin >> day >> n >> mon >> n >> year;
			if((year > 0) && (day >= 1 && day <=31) && (mon >=1 && mon <=12) && (n == '/')){
				dobYear = year;
				dobMon = mon;
				dobDay = day;
			} else {
				cout << "Try again." << endl;
				cin.clear();
				cin.ignore();
				year = -1;
			}
		} while(year == -1);
		fflush(stdin);
	}

	void setHeight(float h){
		height = h;
	}
	void setWeight(float w){
		weight = w;
	}



	string getFirstName() const{
		return firstName;
	}
	string getLastName() const{
		return lastName;
	}
	string getGender() const{
		return gender;
	}
	int getDobYear() const{
		return dobYear;
	}
	int getDobMon() const{
		return dobMon;
	}
	int getDobDay() const{
		return dobDay;
	}

	float getHeight() const{
		return height;
	}
	float getWeight() const{
		return weight;
	}


	// calculate age based on current date and dob date
	int findAge(int birDay, int birMon, int birYear, int curDay, int curMon, int curYear){
		if(birDay >= curDay){
			curMon = curMon - 1;
		}
		if(birMon >= curMon){
			curYear = curYear - 1;
		}
		int curAge = curYear - birYear;
		return curAge;
	}
	// calculate maxHeratRate based on age
	int maxHeartRate(int age) const{
		return (220 - age);
	}
	// calculate bmi base on weight and height
	float getBmi(float w, float h) const{
		return (w / (h * h));
	}

};




#endif /* HEALTHRECORDS_H_ */
