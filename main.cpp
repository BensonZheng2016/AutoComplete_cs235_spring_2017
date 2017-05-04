#include <iostream>
#include <fstream>
#include "trie.h"
#include "dictionary.h"
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
  if (argc > 2) {
    cout << "You have enter more than one argument to the program, this program will only take the first argument you provided." << endl;
    cout << "----------------------" << endl;
  }
  if (argc == 1) {
    cout << "You have enter only one input, dictionary " << endl;
    cout << "----------------------" << endl;
  }
  
  ifstream myfile(argv[1]);
  
  if (!myfile.is_open()) {
    cout << "Input file not found. Dictionary will be empty, please restart program with correct text file input." << endl;
    cout << "----------------------" << endl;
  }
  
  dictionary mydict(myfile);
  //mydict.print();
  //cout << endl;
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
//cout<<temp.contain("abc")<<endl;
    cout << endl;
    cout << "----------------------" << endl;
  } while (true);

  return 0;
}
