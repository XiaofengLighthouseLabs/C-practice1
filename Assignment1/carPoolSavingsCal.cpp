//============================================================================
// Name        : Q1 carPoolSavingsCal.cpp
// Author      : Xiaofeng Zhang   
// Version     :
// Copyright   : Your copyright notice
// Description : Create an application that calculates your daily driving cost,
//               so that you can estimate how much money could be saved by carpooling,
//               which also has other advantages such as reducing carbon emissions
//                and reducing traffic congestion. The application should input the
//                following information and display the user’s cost per day of driving to work:
//					a) Total kilometers driven per day.
//					b) Cost per liter of gasoline.
//					c) Average liter per 100 km.
//					d) Parking fees per day.
//					e) Tolls per day.
//============================================================================

#include <iostream>
#include "carPoolSavings.h" // include definition of class Calculator
using namespace std;

int main() {

	float kmPk{0}, costPgas{0}, avg{0}, park{0}, tolls{0}, totalCost{0};
	char choice;
	// create a Calculator object myCalculator
	Calculator myCalculator;

	cout << "***************************************************" << endl;
	cout << "/                                                 /" << endl;
	cout << "/           CAR - POOL SAVINGS CALCULATOR         /" << endl;
	cout << "/                                                 /" << endl;
	cout << "***************************************************" << endl;
	cout << endl;
	// prompt and obtain user input
	do{
		do{
			cout << "Enter total kilometers you drive (non-negative number): ";
			cin >> kmPk;
			if((!cin)){
				cin.clear();
				cin.ignore();
				cout << "Enter number please.\n";
			}
			myCalculator.setKmPerday(kmPk);
		} while(!(kmPk >= 0));
		fflush(stdin);
		do{
			cout << "Enter the cost per liter of gasoline (non-negative number) ($): ";
			cin >> costPgas;
			if((!cin)){
				cin.clear();
				cin.ignore();
				cout << "Enter number please.\n";
			}
			myCalculator.setCostPerLiterGas(costPgas);
		} while(!(costPgas >= 0));
		fflush(stdin);

		do{
			cout << "Enter your average liters per 100 kilometers (non-negative number): ";
			cin >> avg;
			if(cin.fail()){
				cin.clear();
				cin.ignore();
				cout << "Enter number please.\n";
			}
			myCalculator.setAvgLiterPerhkm(avg);
		}while(!(avg >= 0));
		fflush(stdin);
		do{
			cout << "Enter your parking fees per day (non-negative number): ";
			cin >> park;
			if(cin.fail()){
				cin.clear();
				cin.ignore();
				cout << "Enter number please.\n";
			}
			myCalculator.setParkingFee(park);
		}while(!(park >= 0));
		fflush(stdin);

		do{
			cout << "Enter your tolls per day (non-negative number): ";
			cin >> tolls;
			if(cin.fail()){
				cin.clear();
				cin.ignore();
				cout << "Enter number please.\n";
			}
			myCalculator.setTolls(tolls);
		}while(!(tolls >= 0));
		fflush(stdin);


		totalCost = myCalculator.getCostPerday(myCalculator.getKmPerday(), myCalculator.getCostPerLiterGas(), myCalculator.getAvgLiterPerhkm(),
				myCalculator.getParkingFee(), myCalculator.getTolls());
		// display cost per day of driving
		cout << "\nYou will cost $"<< totalCost << " per day of driving to work." << endl;
		// display savings by carpooling
		cout << "\nIf 2 people share the car, each person will cost  $"<< myCalculator.costPerPerson(totalCost, 2) << " per day of driving to work."
				<< "It will save $" << myCalculator.savePerday(totalCost, 2) << " per day" << endl;
		cout << "\nIf 3 people share the car, each person will cost  $"<< myCalculator.costPerPerson(totalCost, 3) << " per day of driving to work."
				<< "It will save $" << myCalculator.savePerday(totalCost, 3) << " per day" << endl;
		cout << "\nIf 4 people share the car, each person will cost  $"<< myCalculator.costPerPerson(totalCost, 4) << " per day of driving to work."
				<< "It will save $" << myCalculator.savePerday(totalCost, 4) << " per day" << endl;
		cout << "\nIf 5 people share the car, each person will cost  $"<< myCalculator.costPerPerson(totalCost, 5) << " per day of driving to work."
						<< "It will save $" << myCalculator.savePerday(totalCost, 5) << " per day" << endl;

		cout << "\nDo you want to continue the calculation? (Y /y for continue): ";
		cin >> choice;
	} while (choice == 'Y' || choice == 'y');
	cout << "Thank you and Bye!" << endl;






	return 0;
}
