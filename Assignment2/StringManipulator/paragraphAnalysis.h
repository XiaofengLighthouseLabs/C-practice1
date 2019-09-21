/*
 * paragraphAnalysis.h
 *
 *  Created on: Jul 3, 2019
 *  	Author: Xiaofeng Zhang
 */

#ifndef PARAGRAPHANALYSIS_H_
#define PARAGRAPHANALYSIS_H_

#include <iostream>
#include <string>
#include <locale>
using namespace std;

class Paragraph_Analysis{
private:
	string paragraph, word, lowerParagraph, lowerWord, replace, fileName;
	char letter, repLetter;
public:

	void setFileName(string fName){
		if(fName.length() > 0){
			fileName = fName;
		}else{
			cout << "Please enter the file name." << endl;
		}
	}

	bool setParagraph(string text){
		bool hasParagraph = false;
		if(text.length() > 0 && text.length() <= 500){
			paragraph = text;
			hasParagraph = true;
		}else{
			cout << "Invalid" << endl;
		}
		return hasParagraph;
	}


	void setWord(string w){
		if(w.length() > 0){
			word = w;
		} else{
			cout << "Please enter a word." << endl;
		}
	}

	void setLetter(char l){
		letter = l;
	}

	void setReplace(string rep){
		if(rep.length() > 0){
			replace = rep;
		}else{
			cout << "Please enter a replace word. ";
		}
	}
	void setRepLetter(char rl){
		repLetter = rl;
	}

	string getParagraph() const{
		return paragraph;
	}
	string getWord() const{
		return word;
	}
	char getLetter() const{
		return letter;
	}
	string getReplace() const{
		return replace;
	}

	char getRepLetter() const{
		return repLetter;
	}


	// lowercase

//	string getLowerParagraph(){
//		locale loc;
//		if(paragraph.length() > 0){
//			for(unsigned int i = 0; i < paragraph.length(); i++){
//				lowerParagraph += tolower(paragraph[i], loc);
//			}
//		}else{
//			cout << "no text";
//		}
//		return lowerParagraph;
//	}

//	string getLowerWord(){
//		locale loc;
//		if(word.length() > 0){
//			for(unsigned int i = 0; i < word.length(); i++){
//				lowerWord += tolower(word[i], loc);
//			}
//		}else{
//			cout << "no word";
//		}
//		return lowerWord;
//
//	}

	//search word function
	void searchWord(){
		int foundNo{0};
		unsigned int found = paragraph.find(word, 0);
		cout << "The word \"" <<  word << "\" found at index: ";
		while(found!= string::npos){
			if(!isalpha( paragraph.at(found - 1)) && !isalpha( paragraph.at(found + word.length()))){
				foundNo++;
				cout << found << " ";
			}

			found =  paragraph.find(word, found + 1);
		}
		if(found ==  paragraph.find(word, 0)){
			cout << "No Match!";
		}
		cout << "\nThe word \"" <<  word << "\" found " << foundNo << " times." << endl;
	}

	//searchLetter
	void searchLetter(){
		bool found = false;
		cout << "The letter \"" <<  letter << "\" found at index: ";
		for(unsigned int i = 0; i < paragraph.length(); i++){
			if(letter == paragraph.at(i)){
				cout << i << " ";
				found = true;
			}
		}
		if(!found){
			cout << "No Match!";
		}

		cout << endl;
	}
	//count letter
	void letterCount(){
		int foundNo{0};
		for(unsigned int i = 0; i < paragraph.length(); i++){
			if(letter == paragraph.at(i)){
				foundNo++;
			}
		}
		cout << "The letter \"" <<  letter << "\" found " << foundNo << " times." << endl;
	}


	string getFileName() const{
		return fileName;
	}

	// count words
	int wordCount(){
		unsigned int words{0}, start{0};

		while(isspace(paragraph.at(start))){
			start++;
		}

		for(unsigned int i = start; paragraph[i] != '\0'; i++){
			if(isspace(paragraph.at(i))){
				words++;
				if(isspace(paragraph.at(i + 1))){
					words--;
				}
			}
		}
		return (words + 1);
	}

	// find and replace a word
	string findReplaceWord(){
		unsigned int foundNo{0};
		unsigned int found = 0;
		while((found = paragraph.find(word, found)) != string :: npos){
			if(!isalpha(paragraph.at(found - 1)) && !isalpha(paragraph.at(found + word.length()))){
				paragraph.replace(found, word.length(), replace);
				foundNo++;
			}
			found += replace.length();

		}
		cout << foundNo << " word(s) " << word << " replaced to " << replace << endl;
		if (foundNo == 0){
			cout << "No Match!" << endl;
		}
		return paragraph;
	}

	//find and replace a letter
	string findReplaceLetter(){
		unsigned int foundNo{0};
		for(unsigned int i = 0; i < paragraph.length(); i++){
			if(paragraph[i] == letter){
				paragraph[i] = repLetter;
				foundNo++;
			}
		}
		cout << foundNo << " letter " << letter << " replaced to " << repLetter << endl;
		if (foundNo == 0){
					cout << "No Match!" << endl;
				}
		return paragraph;
	}

	//display summary of frequency of each letter within the paragraph
	void summary(){
		unsigned int i{0}, x{0};
		unsigned int countLowerCase[26] = {0}, countUpperCase[26] = {0};
		for(i = 0; i < paragraph.length(); i++){
			if(paragraph[i] >= 'a' && paragraph[i] <= 'z'){
				x = paragraph[i] - 'a';
				countLowerCase[x]++;
			}
			if(paragraph[i] >= 'A' && paragraph[i] <= 'Z'){
				x = paragraph[i] - 'A';
				countUpperCase[x]++;
			}
		}
		for(i = 0; i < 26; i++){
			if(countLowerCase[i] != 0){
				cout << static_cast<char>(i + 'a') << " occurs " << countLowerCase[i] << " times in the string." << endl;
			}
		}
		for(i = 0; i < 26; i ++) {
			if(countUpperCase[i] != 0){
				cout << static_cast<char>(i  + 'A') << " occurs " << countUpperCase[i] << " times in the string." << endl;
			}
		}
	}
};




#endif /* PARAGRAPHANALYSIS_H_ */
