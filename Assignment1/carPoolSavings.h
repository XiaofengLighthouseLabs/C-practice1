/*
 * carPoolSavings.h
 *
 *  Created on: May 29, 2019
 *      Author: Xiaofeng
 */

#ifndef CARPOOLSAVINGS_H_
#define CARPOOLSAVINGS_H_
#include <iostream>
#include <iomanip>  // parameterized stream manipulators

using namespace std;

class Calculator {
private:
	float totalKmPerday, costPerLiterGas, avgLiterPerhkm, parkingFee, tollsPerday;

public:

	// functions that set and return each private data member.
	void setKmPerday(float kmPk){
		if(kmPk < 0){
			kmPk = 0;
			cout << "Please enter non-negative number." << endl;
		}else{
			totalKmPerday = kmPk;
		}
	}
	void setCostPerLiterGas(float costPgas){
		if(costPgas < 0){
			costPgas = 0;
			cout << "Please enter non-negative number." << endl;

		}else{
			costPerLiterGas = costPgas;
		}
	}
	void setAvgLiterPerhkm(float avg){
		if(avg < 0){
			cout << "Please enter non-negative number." << endl;
			avg = 0;
		}else{
			avgLiterPerhkm = avg;
		}

	}
	void setParkingFee(float park){
		if(park < 0){
			cout << "Please enter non-negative number." << endl;
			park = 0;
		}else{
			parkingFee = park;
		}

	}
	void setTolls(float tolls){
		if(tolls < 0){
			cout << "Please enter non-negative number." << endl;
			tolls = 0;
		}else{
			tollsPerday = tolls;
		}

	}
	float getKmPerday() const{
		return totalKmPerday;
	}
	float getCostPerLiterGas() const{
		return	costPerLiterGas;
	}
	float getAvgLiterPerhkm() const{
		return avgLiterPerhkm;
	}
	float getParkingFee() const{
		return	parkingFee;
	}
	float getTolls() const{
		return tollsPerday;
	}
	// function that calculate cost per day of driving.
	float getCostPerday(float kmPk, float costPgas, float avg, float park, float tolls  ) const {
		cout << setprecision( 2 ) << fixed;
		return kmPk * avg * 0.01 * costPgas + park + tolls;
	}
	float costPerPerson(float totalCost, int person){
		cout << setprecision( 2 ) << fixed;
		return (totalCost/person);
	}
	float savePerday(float totalCost, int n){
		cout << setprecision( 2 ) << fixed;
		return (totalCost - totalCost /n);
	}
};


#endif /* CARPOOLSAVINGS_H_ */
