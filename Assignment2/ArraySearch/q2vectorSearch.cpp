//============================================================================
// Name        : q2vectorSearch.cpp
// Author      : Xiaofeng Zhang
// Version     :
// Copyright   : Your copyright notice
// Description : vectorSearch
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

void showValues(vector<int>);
void sortVector(vector<int> &a);
float avgVector(vector<int>);
float medianVector(vector<int>);
int binarySearchVector(vector<int>, int);
void modeInArray(vector<int>);

int main() {
	cout << "***************************************************" << endl;
	cout << "/                                                 /" << endl;
	cout << "/           SEARCH AND SORT INTEGER               /" << endl;
	cout << "/                -- VECTOR --                     /" << endl;
	cout << "/                                                 /" << endl;
	cout << "***************************************************" << endl;
	int vecSize, searchNumber, found;
	float average, median;
	do{
		cout << "Please enter the size of the array: ";
		cin >> vecSize;
		if(!cin || vecSize < 1){
			cout << "The size should be greater than 1." << endl;
			cin.clear();
			cin.ignore();
			vecSize = 0;
		}
	}while(!vecSize);

	vector<int> numbers;


	for(int i = 0; i < vecSize; i++){
		int vecElement;
		cout << "Please enter the " << i + 1 << " elements: ";
		cin >> vecElement;
		if(!cin ){
			cin.clear();
			cin.ignore();
			cout << "Please enter an integer.\n";
			i--;
		}else if(vecElement < 0){
			cout << "Elements should be no negative integers.\n";
			i--;
		}else{
			numbers.push_back(vecElement);
		}

	}

	//display numbers
	cout << "Your input are: " ;
	showValues(numbers);
	cout << "\nThe size of array you entered is: " << numbers.size() << endl;

	// sort numbers
	cout << "\nThe sorted numbers is: ";
	sortVector(numbers);

	//average
	average = avgVector(numbers);
	cout << "\nThe average is: " << average << endl;

	//median
	median = medianVector(numbers);
	if(median){
		cout << "The median is: " << median << endl;
	}else{
		cout << "No value in the vector." << endl;
	}

	cout << "The mode(s) of the vector is: " ;
	// mode in the vector
	modeInArray(numbers);

	//binary search
	cout << "Enter the integer need to be searched: ";
	cin >> searchNumber;
	found = binarySearchVector(numbers, searchNumber);
	if(found == -1){
		cout << "The number can't be found in the array.\n";
	} else{
		cout << "The number " << searchNumber << " was found in ";
		for(unsigned int i = 0;i < numbers.size(); i++){
			if(numbers.at(i) == numbers.at(found)){
				cout <<  "index " << i << " ";
			}
		}
		cout << "of the sorted vector." << endl;
	}


	return 0;
}
//----------------------------------------------------------functions---------------------------------------------------------
// show numbers function
void showValues(vector<int>vect){
	for(unsigned int i = 0; i < vect.size(); i++){
		cout << vect[i] << " ";
	}
}
//sort function
void swap(int &a, int&b){
	int temp = a;
	a = b;
	b = temp;
}
void sortVector(vector<int> &vect){
	int max, index;
	for(max = vect.size() - 1; max > 0; max--){
		for(index = 0; index < max; index++){
			if(vect.at(index) > vect.at(index + 1)){
				swap(vect.at(index), vect.at(index + 1));
			}
		}
	}
	for(unsigned int i = 0; i < vect.size(); i++){
		cout << vect.at(i) << " ";
	}
}

//average function
float avgVector(vector<int> vect){
	int sum = 0;
	float avg = 0.0;
	if(vect.empty()){
		cout << "No value to average.\n";
	}else{
		for(unsigned int i = 0; i < vect.size(); i++){
			sum += vect[i];
		}
		avg = static_cast<float>(sum) / vect.size();
	}
	return avg;
}
//median function
float medianVector(vector<int> vect){
	if(vect.empty()){
		return 0;
	}else{
		if(vect.size() % 2 == 0){
			return (static_cast<float>(vect[vect.size() / 2] + vect[vect.size() / 2 - 1]) / 2);
		}
		else{
			return vect[vect.size() / 2];
		}
	}
}
// mode function
void modeInArray(vector<int> vect){
	int biggestMode = 1;
	vector<int> mode;
	vector<int> numbers;
	numbers.push_back(vect.at(0));
	mode.push_back(1);
	int count = 0;
	for(unsigned int i = 1; i < vect.size(); i++){
		if(vect.at(i) == numbers.at(count)){
			mode.at(count)++;
		}else{
			if (biggestMode < mode.at(count)){
				biggestMode = mode.at(count);
			}
			count++;
			mode.push_back(1);
			numbers.push_back(vect.at(i));
		}
	}

	bool same = true;
	for(unsigned int i = 1; i < mode.size(); i++){

		if(mode.at(i) == mode.at(0)){
			continue;
		}else{
			same = false;
		}
	}
	if(same == true){
		cout << "No mode in the array." << endl;
		mode.clear();
	}

	for(unsigned int i = 0; i < mode.size(); i++){
		if(mode.at(i) == biggestMode){
			cout << numbers.at(i) << " ";
		}
	}
	cout << endl;
}

//binary search function

int binarySearchVector(vector<int> vect, int value){
	int first = 0, last = vect.size(), middle, position = -1;
	bool found = false;
	while(!found && first <= last){
		middle = (first + last) / 2;
		if(vect.at(middle) == value){
			found = true;
			position = middle;
		}
		else if(vect.at(middle) > value){
			last = middle - 1;
		}else{
			first = middle + 1;
		}
	}
	return position;
}
