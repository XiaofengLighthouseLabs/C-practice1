//============================================================================
// Name        : Q4 healthRecords.cpp
// Author      : Xiaofeng Zhang  
// Version     :
// Copyright   : Your copyright notice
// Description : design HealthProfile class for a person
//               The class attributes should include the person’s first name,
//               last name, gender, date of birth (consisting of separate attributes
//               for the month, day and year of birth), height (in meters) and weight (in kg).
//				 Your class should have a constructor that receives this data. For each attribute,
//				 provide set and get functions. The class should also include functions that calculate
//				 and return the user’s age in years, maximum heart rate and target-heart-rate range,
//				 and body mass index (BMI). Write an application that prompts for the person’s information,
//				 instantiates an object of class HealthProfile for that person and prints the information from
//				 that object—including the person’s first name, last name, gender, date of birth, height and
//				 weight—then calculates and prints the person’s age in years, BMI, maximum heart rate and target-heart-rate range.
//============================================================================

#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <math.h>
#include "healthRecords.h"
using namespace std;

int main() {

	string fName, lName, gen;
	int dobYear{0}, dobMon{0}, dobDay{0}, curYear, curMon, curDay, maxHeartRate, age;
	float w, h, bmi;
	char n{'A'};
	// create a HealthProfile object person1
	HealthProfile person1(fName, lName, gen, dobYear, dobMon, dobDay, h, w);
	cout << "***************************************************" << endl;
	cout << "/                                                  /" << endl;
	cout << "/             PATIENT HEALTH RECORDS               /" << endl;
	cout << "/                                                  /" << endl;
	cout << "***************************************************" << endl;
	cout << endl;

	// prompt and obtain user input
	cout << "Please enter your first name: ";
	getline (cin, fName);
	person1.setFirstName(fName);
	cout << "Please enter you last name: ";
	getline (cin, lName);
	person1.setLastName(lName);

	do{
		cout << "Please enter you gender (male / female): ";
		getline (cin, gen);
	} while((gen != "male") && gen != "female");
	person1.setGender(gen);

	person1.setDobDate(dobYear, dobMon, dobDay, n);

	do{
		cout << "Please enter your height (positive number)(meter): ";
		cin >> h;
		if((!cin) ||h <= 0){
			cout << "Try again" << endl;
			cin.clear();
			cin.ignore();
			h = -1;
		}
		else{
			person1.setHeight(h);
		}
	}while (h == -1);

	do{
		cout << "Please enter your weight (positive number)(kg): ";
		cin >> w;
		if((!cin) ||w <= 0){
			cout << "Try again" << endl;
			cin.clear();
			cin.ignore();
			w = -1;
		}
		else{
			person1.setWeight(w);
		}
	}while (w == -1);

	time_t now = time(0);
	struct tm current;
	current = *localtime(&now);
	curMon = current.tm_mon+1;
	curDay = current.tm_mday;
	curYear = current.tm_year+1900;
	dobDay = person1.getDobDay() ;
	dobMon = person1.getDobMon();
	dobYear = person1.getDobYear();

	// display attributes of person1
	cout << "\n\nFull Name: " << person1.getFirstName() << " " << person1.getLastName() << endl;
	cout << "Gender: " << person1.getGender() << endl;
	cout << "Date of Birth (dd/mm/yyyy): " << dobDay << "/" << dobMon << "/" << dobYear << endl;
	age = person1.findAge(dobDay, dobMon, dobYear, curDay, curMon, curYear);
	cout << "Age: " << age << endl;
	cout << "Height (m): " << person1.getHeight() << endl;
	cout << "Weight (kg): " << person1.getWeight() << endl;
	maxHeartRate = person1.maxHeartRate(age);
	cout << "Maximum Heart Rate: " << maxHeartRate << endl;
	cout << "Target-heart-rate Range: " << round(maxHeartRate * 0.5) << " - " << round(maxHeartRate * 0.85) << endl;
	bmi = person1.getBmi(w,h);
	cout << setprecision(1) << fixed;
	cout << "BMI: " << bmi << endl;
	// conditionally display bmi value
	cout << "BMI Value: ";
	if(bmi < 18.5){
		cout << "Underweight" << endl;
	}
	else if(bmi >= 18.5 && bmi <= 24.9){
		cout << "Normal" << endl;
	}
	else if(bmi >=25 && bmi <= 29.9){
		cout << "Overweight" << endl;
	}
	else{
		cout << "Obese" << endl;
	}
	return 0;
}
