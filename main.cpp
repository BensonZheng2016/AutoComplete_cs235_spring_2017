/***************************************************************
Title: Auto-Complete
Author: Yi Zong Kuang
Date Created: late april 2017
Class: Spring 2017, CSCI 235, Mon & Wed 5:35pm-6:50pm
Professor: Michael Garod
Purpose: Project 3 - Auto complete incomplete words.
Description: The main interface with user. Doesn't have a way to terminate the program, must do ctrl + c on terminal to do so.
***************************************************************/

#include <iostream>
#include <fstream>
#include "trie.h"
#include "dictionary.h"
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
  //setting up.
  if (argc > 2) {
    cout << "You have enter more than one argument to the program, this program will only take the first argument you provided." << endl;
    cout << "----------------------" << endl;
  }
  if (argc == 1) {
    cout << "You have enter only one input, dictionary " << endl;
    cout << "----------------------" << endl;
  }
  
  std::cout << "Generating dictionary..."<< std::endl << std::endl;
  ifstream myfile(argv[1]);
  
  if (!myfile.is_open()) {
    cout << "Input file not found. Dictionary will be empty, please restart program with correct text file input." << endl;
    cout << "----------------------" << endl;
  }
  
  dictionary mydict(myfile);

  //showing some statistic about the dictionary.
  cout << "Some statistic about the current dictionary..." << endl;
  cout << "This Dictionary contains this many words: "<< mydict.numWords() << endl;
  cout << "And contains this many nodes: " << mydict.countNodes() << endl << endl; 

  //inputing from user.
  string input = "";
  int n = 0;
  do {
    cout << "Enter a string to be autocompleted: " << endl;
    cin >> input;
    cout << "Enter number of suggestions: " << endl;
    cin >> n;

    vector<string> suggestion = mydict.suggest(input,n);
  
    if (suggestion.size() == 0)
      cout << "No suggestion!" << endl;
    else {
      cout << "Suggestion: " << endl;
      for (unsigned int i = 0; i < suggestion.size(); ++i) {
        cout << suggestion[i] << endl;
      }
    }
    cout << endl;
    cout << "----------------------" << endl;
  } while (true);

  return 0;
}
