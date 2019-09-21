//============================================================================
// Name        : q2arraySearch.cpp
// Author      : Xiaofeng Zhang
// Version     :
// Copyright   : Your copyright notice
// Description : arraySearch
//============================================================================

#include <iostream>
#include <vector>

using namespace std;

void sort(int *arrPtr, int size);
int binarySearch(int *array, int size, int value);
float meanInArray(int *array, int size);
float medianInArray(int *array, int size);
void modeInArray(int *array, int size);

int main() {
	cout << "***************************************************" << endl;
	cout << "/                                                 /" << endl;
	cout << "/           SEARCH AND SORT INTEGER ARRAY         /" << endl;
	cout << "/                                                 /" << endl;
	cout << "***************************************************" << endl;
	int arraySize, searchNumber, found;
	int *arrPtr = nullptr;
	float median= 0.0, mean= 0.0;

	do{
		cout << "Please enter the number of elements you want to type: ";
		cin >> arraySize;
		if(arraySize < 1){
			arraySize = 0;
			cout << "Array size should be greater than 1." << endl;
		}
	}while(!arraySize);

	arrPtr = new int[arraySize];
	if(arrPtr == nullptr || arraySize < 1){
		cout << "Sorry! Memory could not be allocated." << endl;
		return 1;
	}
	cout << "Please enter the non negative integer elements." << endl;
	for(int i = 0; i < arraySize; i++){
		cout << "Enter " << i + 1 << " element: " ;
		cin >> *(arrPtr + i);
		if(!cin ){
			cin.clear();
			cin.ignore();
			cout << "Please enter an integer.\n";
			i--;
		}
		if(arrPtr[i] < 0){
			cout << "Elements should be no negative integers.\n";
			i--;
		}
	}
	cout << "The array you entered is: ";
	for(int i = 0; i < arraySize; i++){
		cout << arrPtr[i] << " ";
	}
	cout << "\nThe size of array you entered is: " << arraySize << endl;
	//sort array use sort function

	sort(arrPtr, arraySize);
	cout << "\nThe sorted array is: ";
	for(int i = 0; i < arraySize; i++){
		cout << arrPtr[i] << " ";
	}

	//mean in the array
	mean = meanInArray(arrPtr, arraySize);
	//median in the array
	median = medianInArray(arrPtr, arraySize);

	cout << "\nThe average of the array is: " << mean << endl;
	cout << "The median of the array is: " << median << endl;
	cout << "The mode(s) of the array is: " ;
	// mode in the array
	modeInArray(arrPtr, arraySize);


	//search array use binarySearch function
	cout << "Enter the integer need to be searched: ";
	cin >> searchNumber;
	found = binarySearch(arrPtr, arraySize, searchNumber);
	if(found == -1){
		cout << "The number can't be found in the array.\n";
	} else{
		cout << "The number " << searchNumber << " was found in ";
		for(int i = 0;i < arraySize; i++){
			if(arrPtr[i] == arrPtr[found]){
				cout <<  "index " << i << " ";
			}
		}
		cout << "of the sorted array." << endl;
	}
	delete[]arrPtr;
	arrPtr = nullptr;

	return 0;
}
//---------------------------------------------functions------------------------------------------------------------------------
// bubble sort
template <class T>
void swap(T &a, T &b){
	T temp = a;
	a = b;
	b = temp;
}
void sort(int *array, int size){
	int max, index;
	for(max = size - 1; max > 0; max--){
		for(index = 0; index < max; index++){
			if(array[index] > array[index + 1]){
				::swap(array[index], array[index + 1]);
			}
		}
	}
}
// binary search
int binarySearch(int *array, int size, int value){
	int first = 0, last = size - 1, middle, position = -1;
	bool found = false;
	while(!found && first <= last){
		middle = (first + last) / 2;
		if(array[middle] == value){
			found = true;
			position = middle;
		}
		else if(array[middle] > value){
			last = middle - 1;
		}else{
			first = middle + 1;
		}
	}
	return position;
}
//mean
float meanInArray(int *array, int size){
	if(size < 1){
		return 0;
	}
	float sum = 0;
	for(int i = 0; i < size; i++){
		sum += array[i];
	}
	return (static_cast<float>(sum) / size);
}
//median
float medianInArray(int *array, int size){
	if(size < 1){
		return 0;
	}
	if(!size % 2){
		return (array[size / 2]);
	}else{
		return (static_cast<float>(array[size / 2] + array[size / 2 - 1]) / 2);
	}
}
//mode
void modeInArray(int *array, int size){
	int biggestMode = 1;
	vector<int> mode;
	vector<int> numbers;
	numbers.push_back(array[0]);
	mode.push_back(1);
	int count = 0;
	for(int i = 1; i < size; i++){
		if(array[i] == numbers.at(count)){
			mode.at(count)++;
		}else{
			if (biggestMode < mode.at(count)){
				biggestMode = mode.at(count);
			}
			count++;
			mode.push_back(1);
			numbers.push_back(array[i]);
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
