//============================================================================
// Name        : q1StringManipulator.cpp
// Author      : Xiaofeng Zhang
// Version     :
// Copyright   : Your copyright notice
// Description : StringManipulator
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include "paragraphAnalysis.h"
using namespace std;

int main() {
	cout << "***************************************************" << endl;
	cout << "/                                                 /" << endl;
	cout << "/                  PARAGRAPH ANALYSIS             /" << endl;
	cout << "/                                                 /" << endl;
	cout << "***************************************************" << endl;

	Paragraph_Analysis myFile;

	ifstream exampleFile;
	string line, w, rep, fName;
	char l, rl;
	int chose;
	//open the file
	do{
		cout << "Please open a file: ";
		getline (cin, fName);
		myFile.setFileName(fName);
		exampleFile.open(myFile.getFileName());
		if(exampleFile.is_open()){
			while(!exampleFile.eof()){
				getline(exampleFile, line);
				cout << "The content of the file you opened is: " << endl;
				if(myFile.setParagraph(line)){
					cout << myFile.getParagraph() << endl;
				}else{
					cout << "Try to open files that characters are less than 500." << endl;
					exampleFile.close();
					break;
				}
				//			myFile.getLowerParagraph();
				do{

					cout << "\nMENU" << endl;
					cout << "1. Search for a Particular Word\n" << "2. Search for a Particular Letter\n" << "3. Count Total Words\n" << "4. Count a Particular Letter\n" << "5. Find and Replace a Word\n"
							<< "6. Find and Replace a Letter\n" << "7. Summary\n" <<  "8. EXIT" << endl;
					cout << "Please choose from MENU (1 to 8): " << endl;
					cin >> chose;
					if((!cin)){
						cin.clear();
						cin.ignore();
					}
					switch(chose){
					case 1:
						// search word
						cout << "\nPlease enter the word need to be search (case-sensitive): ";
						cin >> w;
						myFile.setWord(w);
						//					myFile.getLowerWord();
						myFile.searchWord();
						break;
					case 2:
						//search letter
						cout << "\nPlease enter the letter need to be search: ";
						cin >> l;
						myFile.setLetter(l);
						myFile.getLetter();
						myFile.searchLetter();
						break;
					case 3:
						//words count
						cout << "\nThe total words are: " << myFile.wordCount() << endl;
						break;
					case 4:
						// letter count
						cout << "\nPlease enter the letter need to be count: ";
						cin >> l;
						myFile.setLetter(l);
						myFile.getLetter();
						myFile.letterCount();
						break;
					case 5:
						// find and replace a word
						cout << "\nPlease enter the word need to be replaced: ";
						cin >> w;
						myFile.setWord(w);
						cout << "\nPlease enter the replace word: ";
						cin >> rep;
						myFile.setReplace(rep);
						cout << myFile.findReplaceWord() << endl;
						break;
					case 6:
						//find and replace a letter
						cout << "\nPlease enter the letter need to be replaced: ";
						cin >> l;
						myFile.setLetter(l);
						cout << "\nPlease enter the replace letter: ";
						cin >> rl;
						myFile.setRepLetter(rl);
						cout << myFile.findReplaceLetter() << endl;
						break;
					case 7:
						// summary
						myFile.summary();
						break;
					case 8:
						cout << "Thanks and Bye!" << endl;
						break;
					default:
						cout << "Please enter the right number!" << endl;
					}
				}while(chose != 8);
			}
		} else{
			cout << "The file was not found." << endl;
		}

	}while(!myFile.getParagraph().length());

	exampleFile.close();

	return 0;
}
