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
/*
  std::vector<std::string> closewords;

  if (s == "")
    return closewords;		//which should be of size 0.

  trieNode* ptr = _data.findAny(s);		 //ERROR!!! THis only find complete word, for purpose of this program, user may enter incomplete word!!! Make a new find() for such purpose.

  //testing if find return the right pointer location.
  for (std::map<char,trieNode>::iterator it = ptr->child.begin(); it != ptr->child.end(); ++it) {
    std::cout<<it->first<<std::endl;
  }
  std::cout<<std::endl;

  if (ptr == nullptr or ptr->child.size() == 0)
    return closewords;		//s wasn't in the dictionary, or last char of s was a leaf in the trie so no more suffix, so return vector of size 0.

  //at this points, it's assumed there are definitely words that are similar to s.
  std::queue<trieNode*> workingspace;

  workingspace.push(ptr);
  trieNode* tempptr;
 
  std::map<char,trieNode>::iterator it;
  
  while(!workingspace.empty()) {
    tempptr = workingspace.front(); std::cout<<"looking at address: "<<workingspace.front()<<std::endl;
    //tempptr->show(0);
    //std::cout<<"queue size: "<<workingspace.size()<<std::endl;
    std::cout<<"first of queue's child size: "<<tempptr->child.size()<<" endofwrod flag:"<<tempptr->endOfWord<<std::endl;
    workingspace.pop();
											//use temp vector to stroe forming string, then once a certain number is meet, transfer for the complete word to final vector, can store the index in an another vector?
    for (it = tempptr->child.begin(); it != tempptr->child.end(); ++it) {		//append to strings s, for each element, once end of word flag is true, push back to vector.
      std::cout<<it->first<<" "<<it->second.endOfWord<<std::endl;			//once vector size() == n, return the vector.	This part may not be needed. move it to second loop.
    }
     
    //testing
    //it = tempptr->child.begin();
    if (tempptr->child.size() == 0) {		//tempptr and it are on different lv, got to make sure i am not comparing the wrong thing.
      //std::cout<<"child size is 0: "<<std::endl;
    }

    //std::cout<<"going through child's contenet: ";
    for (it = tempptr->child.begin(); it != tempptr->child.end(); ++it) {			//somehow at this part, can append every child key to parent key to make new word. error, index is not int.
      std::cout<<"pushing into queue: "<<it->first<<" address: "<<ptr->child[it->first]<<std::endl;
      workingspace.push(&ptr->child[it->first]);
    }
    //std::cout<<std::endl;
  }

  return closewords;			//when there's not enough suggestions to surpass n, this will get call and return.
*/

  std::vector<std::string> closewords;
  if (s == "")
    return closewords;		//should be of size 0 at this point.

  trieNode* ptr = _data.findAny(s);
  if (ptr == nullptr or ptr->child.size() == 0)			//if ptr is leave or null, return vector of size 0, no match to suggest.
    return closewords;	
  //std::cout<<ptr->child['s'].child['o'].child.size()<<std::endl;	//detects 'o' correctly.

  std::queue<trieNode*> workingspace;
  workingspace.push(ptr);

/*
  workingspace.push(&ptr->child['s']);
  workingspace.push(&ptr->child['s'].child['o']);

  std::cout<<workingspace.front()->child.size()<<std::endl;  
  workingspace.pop();
  std::cout<<workingspace.front()->child.size()<<std::endl;
  workingspace.pop();
  std::cout<<workingspace.front()->child.size()<<std::endl;
  workingspace.pop();
*/
  //vector
  while(!workingspace.empty()) {
    int counter = 0;
    trieNode* ptr2 = workingspace.front();

    for (std::map<char,trieNode>::iterator it = ptr2->child.begin(); it != ptr2->child.end(); ++it) {	//level traversal, this entire while loop.
      std::cout<<"pushing: "<<it->first<<std::endl;
      if (it->second.endOfWord == true) {
        std::string temp = _data.findWord(it->second);
        if (temp != "")	{	//sometime findWord() will return an empty string, not sure why.
          closewords.push_back(temp);		//will search for word and push back on to the vector.
          ++counter;
        }
      }
    
      if (counter == n)
        return closewords;			//once we found n number of words that's close enough for suggest, return the vector.  
     
      workingspace.push(&it->second);
    }
    std::cout<<std::endl;

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
std::string dictionary::findWord(const trieNode& a) {
  return _data.findWord(a);
}
