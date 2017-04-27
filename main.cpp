#include <iostream>
#include "trie.h"
#include "dictionary.h"

using namespace std;

int main(int argc, char* argv[]) {
  if (argc != 2)
    cout<<"you have enter more than one argument to the program, this program will only take the first argument you provided."<<endl;
  

  //trie mytrie; 
  /*
  //Testing functions within just one single level in the trie, meaning testing with fct in just one trieNode.
  cout<<"-------testing for empty map			---"<<endl;
  cout<<mytrie.empty()<<endl;

  cout<<"-------inputing keys				---"<<endl;
  cout<<"inputing..."<<endl;
  for (char input = 'a'; input < 'a'+ 26; ++input)
    mytrie.insert(input);   

  cout<<"-------testing for repeated insert		---"<<endl;
  cout << mytrie.insert('a');
  cout << mytrie.insert('b');
  cout << mytrie.insert('a')<<endl;

  cout<<"-------testing for empty map			---"<<endl;
  cout<<mytrie.empty()<<endl;
 
  cout<<"-------testing for printing map KEY		---"<<endl;
  mytrie.print();

  cout<<"-------testing for inserting CAP LETTER     	---"<<endl;
  for (char input = 'A'; input < 'A'+ 26; ++input)
    mytrie.insert(input);

  cout<<"-------testing for printing map KEY		---"<<endl;
  mytrie.print();
  
  cout<<"-------testing for upper to lower case fct    	---"<<endl;
  trieNode temp;
  for (char input1 = 'A'; input1<'A'+26; ++input1)
    cout<<temp.upperToLower(input1)<<endl;  
  */
/*
  cout<<"-------testing for empty string insertion    	---"<<endl;
  string teststring = "";
  cout<< mytrie.insert(teststring) <<endl;

  cout<<"-------testing for string insertion    	---"<<endl;
  teststring = "apple";
  cout << mytrie.insert(teststring) <<endl;

  cout<<"-------testing for result of string insertion 	---"<<endl;
  mytrie.print();
  cout<<"# of words: "<<mytrie.numWords()<<endl;

  cout<<"-------testing for multiple string insertion  	---"<<endl;
  teststring = "able";
  cout << mytrie.insert(teststring) <<endl;

  cout<<"-------testing for result of multiple string insertion 	---"<<endl;
  mytrie.print();
  cout<<"# of words: "<<mytrie.numWords()<<endl;

  cout<<"-------testing for multiple string insertion  	---"<<endl;
  cout<<mytrie.insert("Backup")<<endl;
  cout<<mytrie.insert("Ab")<<endl;
  cout<<mytrie.insert("back")<<endl;
  cout<<mytrie.insert("GaNges")<<endl;
  cout<<mytrie.insert("BACK")<<endl;

  cout<<"-------testing for result of multiple string insertion 	---"<<endl;
  mytrie.print();
  cout<<"# of words: "<<mytrie.numWords()<<endl;

  cout<<"-------testing for chking contain(string)	---"<<endl;
  cout<<mytrie.contain("")<<endl;
  cout<<mytrie.contain("Hello")<<endl;
  cout<<mytrie.contain("back")<<endl;
  cout<<mytrie.contain("Back")<<endl;
  cout<<mytrie.contain("GaNges")<<endl;

  cout<<"-------testing for chking contain(string)	---"<<endl;
  cout<<mytrie.remove("Jesus")<<endl;
  cout<<mytrie.remove("back")<<endl;

  cout<<"-------testing for printing after remove	---"<<endl;
  mytrie.print();
  mytrie.show();
  cout<<"# of words: "<<mytrie.numWords()<<endl;

  cout<<"-------testing for inserting subword		---"<<endl;
  cout<<mytrie.insert("back")<<endl; 

  cout<<"-------print after inserting subword		---"<<endl;
  mytrie.print();
  mytrie.show();
  cout<<"# of words: "<<mytrie.numWords()<<endl;

  cout<<"-------testing for remove with capital letter	---"<<endl;
  cout<<mytrie.remove("BaCk")<<endl;
  cout<<mytrie.remove("Bac")<<endl;
  cout<<mytrie.remove("eat")<<endl;

  cout<<"-------print after remove with captial letter	---"<<endl;
  mytrie.show();
  cout<<"# of words: "<<mytrie.numWords()<<endl;
*/ 
/*
  cout<<"-------inserting some word			---"<<endl;
  cout<<mytrie.insert("ab")<<endl;  
  cout<<mytrie.insert("able")<<endl;
  cout<<mytrie.insert("ab")<<endl;
  cout<<mytrie.insert("apple")<<endl;
  cout<<mytrie.insert("back")<<endl;
  cout<<mytrie.insert("backup")<<endl;
  cout<<mytrie.insert("giant")<<endl;
  cout<<mytrie.insert("giga")<<endl;
  cout<<mytrie.insert("gigaword")<<endl;
  cout<<mytrie.insert("hello")<<endl;

  cout<<"-------testing find()				---"<<endl;
  mytrie.print();
  cout<<endl;
  string testfind = "giant";
  trieNode* testptr = mytrie.find(testfind);
  if (testptr == nullptr)
    cout<<"null ptr, '"<<testfind<<"' not found in trie."<<endl;
  else
    cout<<"word found in the trie, don't have a way to show it atm."<<endl;

  cout<<"-------testing trie.contain(string)		---"<<endl;
  cout<<mytrie.contain("apple")<<endl;
  cout<<mytrie.contain("many")<<endl;
  cout<<mytrie.contain("ApPle")<<endl;

  cout<<"-------print some info				---"<<endl;
  mytrie.show();
  mytrie.print();
  cout<<"Number of word in trie: "<<mytrie.numWords()<<endl;
  cout<<"Number of Nodes in trie: "<<mytrie.countNodes()<<endl;

  cout<<"-------testing trie.clear()			---"<<endl;
  mytrie.clear();
  mytrie.print();
  mytrie.show();
*/
/*
  cout<<"-------testing load()				---"<<endl;
  cout<<mytrie.load("words.txt")<<endl;

  cout<<"-------printing out some info			---"<<endl;
  mytrie.show();
  mytrie.print();
  cout<<"Number of word in trie: "<<mytrie.numWords()<<endl;
  cout<<"Number of Nodes in trie: "<<mytrie.countNodes()<<endl;

  cout<<"-------confirming some function		---"<<endl;
  cout<<mytrie.contain("abashedness")<<endl;
  cout<<mytrie.contain("AbaSHeDneSS")<<endl;
  cout<<mytrie.contain("jessu crhis")<<endl;

  cout<<"-------testing constructor			---"<<endl;
  ifstream myfile(argv[1]);
  if (myfile.is_open()) {
    trie newtrie(myfile);
    newtrie.print();
    cout<<"Number of word in trie: "<<newtrie.numWords()<<endl;
    cout<<"Number of Nodes in trie: "<<newtrie.countNodes()<<endl;
  }
  else
    cout<<"file not found, no trie were constructed."<<endl;
*/

  cout<<"-------testing dictionary class		---"<<endl;
  ifstream myfile(argv[1]);
  //assumes myfile is valid.
  dictionary mydict(myfile);
  mydict.print();
  cout<<"Number of word in dictionary: "<<mydict.numWords()<<endl;

  cout<<"-------testing dictionary fct			---"<<endl;
  cout<<mydict.load("even_shorter_words.txt")<<endl;
  mydict.print();
  cout<<"Number of word in dictionary: "<<mydict.numWords()<<endl;
  cout<<mydict.isLegalWord("aBasTardize")<<endl;
  cout<<mydict.isLegalWord("abastardize")<<endl;
  cout<<mydict.isLegalWord("Jessuschirt")<<endl;
  cout<<mydict.isLegalWord("absolutevodka")<<endl;
  cout<<mydict.isLegalWord("able")<<endl;
  
  cout<<"-------testing dictionary suggest()		---"<<endl;
  mydict.suggest("ab",10);

  trieNode* testing = mydict.findAny("abso");
  cout<<endl<<testing->child.size()<<" at address: "<<testing<<endl;	//looks like address at 'o' is not same in suggest()'s 'o'
    

  return 0;
}
