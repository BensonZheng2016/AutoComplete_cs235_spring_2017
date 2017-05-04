#include "trie.h"
#include <iostream>

trie::trie() {
  _root.endOfWord = false;
  _wordcount = 0;
}

//assumes myfile is valid, and openable.
trie::trie(std::ifstream& myDictionaryFile) {
  _root.endOfWord = false;
  _wordcount = 0;

  std::string line = "";

  while (getline(myDictionaryFile,line)) {
    insert(line);
  }
}

trie::~trie() {

}

//given a string, find the pointer pointing to the last char of the string in the trie. return null if no such string is contained in the trie.
trieNode* trie::find(std::string& a) {
  return _root.find(a);
}

//given a string, if this string pattern exist in trie, return the pointer, else return null ptr.
trieNode* trie::findAny(std::string& a) {
  return _root.findAny(a);
}

//shows all level of each char.
void trie::show() {
  if (_root.child.size() == 0)
    std::cout<<"This trie is empty. Nothing to show."<<std::endl;

  int i = 0;
  _root.show(i);
}

//find out if root's map is empty, means if the trie data structure is empty.
bool trie::empty() {
  return _root.empty();
}

//change a string to all lower case.
std::string trie::changeToAllLowerCase(std::string& a) {
  if (a == "")
    return a;

  std::string toBeReturn = "";

  for (int i = a.size() - 1; i > 0; --i) {
    toBeReturn += ((a[i]%65)%32);
  }
  return toBeReturn;
}

//find out if root contain a.
bool trie::contain(char a) {
  return _root.contain(a);
}

//find out if trie contain a string. Will deal with Upper case and Lower case, auto changes Upper case to lower case.
//for subword, will ony return true if endofword flag is true.
bool trie::contain(std::string a) {
  if (a == "")
    return false;

  trieNode* ptr = _root.find(a);
  if (ptr == nullptr)
    return false;
  else
    return true;

}

//insert a char input into root's map. Never should be called, cuz main.cpp will not have any insertion via a char input, it is always as a string input.
bool trie::insert(char a) {std::cout<<"ERROR: This functions is insert via char to root's map, should NEVER be called."<<std::endl;
  return _root.insert(a);		//calls to overloaded char version.
}

//insert string into ROOT's map, calls the insert char fct of the trie node. This will be what's called on main.cpp, it is the main gate to the recursive insertion calls.
//able to handle subword and complete word.
bool trie::insert(std::string a) {
  if (a == "")
    return false;

  if (contain(a) == true)		//if trie alrdy contain such word, return the fct.
    return false;
  
  ++_wordcount;
  return _root.insert(a);		//recursive call(to overloaded string version).
}

//print everything in the map of the current trieNODE (not trie).
void trie::print() {
  if (_root.child.size() == 0)
    std::cout<<"This trie is empty."<<std::endl;

  std::string a="";	//buffer string variable to store char until endOfWord is reached, and will print out its contents.
  _root.print(a);
}

//starts the recursly call to remove a word.
bool trie::remove(std::string a) {
  if (a == "")
    return false;
  if (contain(a) == false) 
    return false;

  --_wordcount;
  return _root.remove(a);
}

//since I am using hemp memory, I never used the keyword 'new', so this clear should be simple.
//This also means if I decide to change to using 'new', got to change this function, maybe.
void trie::clear() {
  _root.child.clear(); 
  _wordcount = 0;
}

//returns number of word in this trie.
unsigned int trie::numWords() {
  return _wordcount;
}

//return the number of nodes in this trie, calculated in real time.
unsigned int trie::countNodes() {
  return _root.countNodes();
}

//load words into the trie base on a filename
bool trie::load(std::string a) {
  if (a == "")
    return false;

  std::ifstream myDictionaryFile(a);
  std::string line = "";

  if (myDictionaryFile.is_open()) { 			//if contain such file in the directory, call consturctor.
    if(_wordcount != 0) 		//if this trie is already loaded with some data, clear it.
      clear();

    while (getline(myDictionaryFile,line)) {
      insert(line);
    }
    return true;
  }
  else
    return false;
}

//called by suggest() from dictionary class, find the a word by comparing to a trieNode address, starts at the node that is current in suggest().
std::string trie::findWord(const std::map<char,trieNode>::iterator& nodeIt) {
  return _root.findWord(nodeIt);
}
