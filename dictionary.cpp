#include "dictionary.h"
#include <queue>
#include <iostream>

dictionary::dictionary() {
  trie _data;
}

//assumes the ifstream argument is valid and openable. Using initilization list to make sure the constructure of _data is paired up with a argument.
dictionary::dictionary(std::ifstream& myDictionaryFile) 
  : _data(myDictionaryFile)
{

}

dictionary::~dictionary() {

}

//calls load on the trie class.
bool dictionary::load(std::string a) {
  return _data.load(a);
}

//chks if word is contained in this dictionary by calling trie's find funciton.
bool dictionary::isLegalWord(std::string a){
  return _data.find(a);
}

//return number of word in dictionary through calling trie's fct.
unsigned int dictionary::numWords() {
  return _data.numWords();
}

//suggests up to n number of word that is considered closed to the string s.
std::vector<std::string> dictionary::suggest(std::string s, int n){
  std::vector<std::string> closewords;
  if (s == "")
    return closewords;		//should be of size 0 at this point.

  trieNode* ptr = _data.findAny(s);
  if (ptr == nullptr or ptr->child.size() == 0)			//if ptr is leaf or null, return vector of size 0, no match to suggest.
    return closewords;	

  if (ptr->endOfWord == true) {						//if the input word is a legal word, add to vector.
    closewords.push_back(s);
    if (n == 1)	//if number of suggestion n == 1, an return here.
      return closewords;
  }

  std::queue<trieNode*> workingspace;
  workingspace.push(ptr);

  while(!workingspace.empty()) {
    //int counter = 0;
    trieNode* ptr2 = workingspace.front(); 

    for (std::map<char,trieNode>::iterator it = ptr2->child.begin(); it != ptr2->child.end(); ++it) {	//level traversal, this entire while loop.
      if (it->second.endOfWord == true) {
        std::string temp = s; 
        //temp += ptr2->findWord(it->second);		//take string s, and search after this current node. Should reduce search time by quite a lot in large dictionary.
        temp += ptr->findWord(it);    //std::cout<<&it->second<<std::endl;
        if (temp != "")	{	//sometime findWord() will return an empty string, not sure why.
          closewords.push_back(temp);		//will search for word and push back on to the vector.
   std::cout<<"pushing back: "<<temp<<" with flag: "<<it->second.endOfWord<<" and key: "<<it->first<<" and address of it->second: "<<&it->second<<std::endl;
          //++counter;
        }
        if (temp == "")						//for debuging purposes.
          std::cout<<"findword(it) returned empty string"<<std::endl;
      }
    
      if (closewords.size() == unsigned(n))
        return closewords;			//once we found n number of words that's close enough for suggest, return the vector.  
     
      workingspace.push(&it->second);
    }//std::cout<<"couter:"<<counter<<std::endl;
    workingspace.pop();
  }
  return closewords;		//at this point, this vector should be filled with some amount of words, less than n, if coundn't find more than n word.
}

//for testing purposes, print all words contained in this dicitonary.
void dictionary::print() {
  _data.print();
}

//given a string, find its pattern in the trie, if not exist, return nullptr.
trieNode* dictionary::findAny(std::string a) {
  return _data.findAny(a);
}

//helper to suggest(), find a word in the trie that has its last char same address as the argument.
std::string dictionary::findWord(const std::map<char,trieNode>::iterator& nodeIt) {
  return _data.findWord(nodeIt);
}

unsigned int dictionary::countNodes() {
  return _data.countNodes();
}
