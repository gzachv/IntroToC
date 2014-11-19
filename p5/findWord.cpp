/*
 * findWord.cpp
 *
 * Read in a word (sequence of non-whitespace chars) and the name of a file from
 *  the command line. For each line in which the given word occurs, the program
 *  prints out the entire line preceded by the line number. After processing the
 *  entire file, the program reports the total number of occurrences of the
 *  given word within the file.
 *
 */

/*******************************************************************************
Author:        Gustavo Zach Vargas
CS Login:      gustavo

Pair Partner:  <name of your pair programming partner (if applicable)>
CS Login:      <your partner's login name>

Credits:       <name of anyone (other than your pair programming partner) who
                helped you write your program>

Course:         CS 368, Fall 2013
Assignment:     Programming Assignment 5
 *******************************************************************************/

#include <fstream>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;


/*
 * find
 *
 * does the major work of the description above. (finds number of words in .txt)
 */
int find(string & word, string & fileName) {

	//Open input .txt file
	ifstream inFile(fileName.c_str());
	if (!inFile) {
		cerr << "Unable to open " << fileName << " for reading" << endl;
		return -1;
	}

	cout << "Searching for the word '" << word << "' in file '" << fileName
			<< "' " << endl;

	int count = 0; // count of total number of occurrences of the word
	string line; // line to be scanned for word
	int found = 0; // location of word in line
	int lineNum = 0; //line number

	while (!getline(inFile, line).eof()) {

		for(int i = line.find(word);
				i != string::npos; i = line.find(word,i + word.length())){
			count ++;
			cout << "Line " << lineNum << ": " << line << endl;
		}

		lineNum ++;
	}

	return count;
}


int main(int argc, char *argv[]) {

	//if proper number of args are given show the user the proper usage
	if(argc != 3){
		if(argc!=0){
			cout << "ERROR: please use correct format for findWord: " << endl;
		}
		cout << "Proper usage: findWord <word> <file> where: " << endl;
		cout << "    <word> is a sequence of non-whitespace characters" << endl;
		cout << "    <file> is the file in which to search for the word" << endl;
		cout << "example: findWord the test.txt" << endl;
	}

	string word = argv[1];
	string fileName = argv[2];

	int count = find(word,fileName);

	if (count == -1){
		return 1;
	}

	cout << "# of occurrences of the word '" << word << "': " << count << endl;
	return 0;
}


