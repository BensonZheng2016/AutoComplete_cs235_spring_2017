#include "trieNode.h"
#include <iostream>

//shows all level of each char.
void trieNode::show(int i) {
  std::map<char,trieNode>::iterator it;
  it = child.begin();
  ++i;
  //trasverse the map, appent to string, once base case it hit, popback from string, output string only when endOfWord is true.
  for (; it != child.end(); ++it) {		//base case is when it go to end of the map.
    std::cout<<i<<". "<<it->first;

    if (it->second.endOfWord == true)
      std::cout<<" true flag on";
    std::cout<<std::endl;

    child[it->first].show(i);			//recursivly call sub map.
  }

}

//return true if the map is empty, else false.
bool trieNode::empty() {
  return child.empty();
}

//return true if char a is contained in the map. Doesn't auto translate upper case to lower case.
bool trieNode::contain(char& a) {
  std::map<char, trieNode>::iterator it;
  
  it = child.find(a);

  if (it == child.end())		//if it is at end, means it went through whole map and found no match.
    return false;
  else
    return true;
}

//find a given string starting from the root of the trie, this functions gets called from a trie class. Handles upper and lower case.
trieNode* trieNode::find(std::string& a) {
  if (a == "")
    return this;		//calls starts at the root, so if empty string, return the root.

  trieNode* itr = this;

  for (unsigned int i = 0; i < a.size(); i++) {	//suppose to go down one level on each iteration.
    char temp = a[i];
    if (temp >= 'A' and temp <= 'Z')
      temp += 32; 			//changes to lower case.

    if (itr->contain(temp) == false)			//checks the child map.
      return nullptr;

    itr = &itr->child[temp];
  }

  if (itr->endOfWord == true)
    return itr;					//itr will hold the reference of the trieNode with the key of the last char and its child map.
  else {
    std::map<char,trieNode>::iterator it;
    it = itr->child.begin();			//THIS PART CAN BE DELETED, ONLY HERE FOR TESING.
    for (;it!=itr->child.end();++it) {
      std::cout<<it->first<<std::endl;
    }

    //std::cout<<"last null returned"<<std::endl;
    return nullptr;
  }
}

//find if a pattern exist in the trie, and return it if it does.
trieNode* trieNode::findAny(std::string& a) {
  if (a == "")
    return this;		//calls starts at the root, so if empty string, return the root.

  trieNode* itr = this;

  for (unsigned int i = 0; i < a.size(); i++) {	//suppose to go down one level on each iteration.
    char temp = a[i];
    if (temp >= 'A' and temp <= 'Z')
      temp += 32; 			//changes to lower case.

    if (itr->contain(temp) == false)			//checks the child map.
      return nullptr;

    itr = &itr->child[temp];
  }

  return itr;					//itr will hold the reference of the trieNode with the key of the last char and its child map.
}

//chk if a string is contained in the trie as a complete word. a contain the word to be searched for, and buffer is the words to be made from the trie.
//bool trieNode::contain(std::string a, std::string& buffer) {
/* The following will be able to chk contain(string) but only on string with all lower case.

  std::map<char,trieNode>::iterator it;
  it = child.begin();

  for (; it != child.end(); ++it) {		//base case is when it go to end of the map.
    buffer += it->first;
    if (it->second.endOfWord == true and a == buffer)	//end of word flag is on and a == buffer, means word is found in the trie.
      return true;
    //std::cout<<buffer<<std::endl;
    if ( child[it->first].contain(a,buffer) == true)	//recursivly call sub map. It is still ran even though it's in a if statement.
      return true;
    buffer.erase(buffer.end()-1);
  }
  
  //at this point it is assumed it is at child.end() so the inputed string was not found.
  return false;
*/
//}

//converts upper case to lower case (char).
char trieNode::upperToLower(char& a) {
  return (a+32);
}

//return true if insert was successful.
bool trieNode::insert(char& a) {
  if (contain(a) == true)			//checks if child map contain char a.
    return false;

  trieNode temp;				//creates a new trieNode that will be passed as reference in the insert function of the map.
  child.insert( std::pair<char,trieNode>(a,temp) );		//inserted down one level, so at that one level it's default to be endOfWord=false.
  //endOfWord = false;				//set end of word to false(on current level), now that there is something to insert after this current node. defualt is set to false.
  return true;
}

//take first char of the string and calls insert(char a), then pass the remaining substring recursively into deeper level. Base case is when string == "".
bool trieNode::insert(std::string& a) {
  if (a == "") {				//base case, end of word will set endOfWord = true, it's return false, but it doesn't really matter.
    endOfWord = true;				//takes care of the case when entered words are sub words of longer words.
    return false;
  }			

  char firstchar = a[0];
  if (firstchar >= 'A' and firstchar<= 'Z') {			//chk if it's upper case.
    firstchar = upperToLower(firstchar);
    //std::cout<<"ran: "<<firstchar<<std::endl;
  }

  insert(firstchar);

  a.erase(a.begin());
  child[firstchar].insert(a);			//find a[0] in the child map, go to it. then call its insert(). recursive call to insert(string), passing substring without first char into it.
  return true;
}

//print all the complete word in the trie.
void trieNode::print(std::string& a) {

  std::map<char,trieNode>::iterator it;
  it = child.begin();
/*
  for (; it != child.end(); ++it) {		//base case is when it go to end of the map.
    std::cout << it->first << it->second.endOfWord << std::endl;
    child[it->first].print();			//recursivly call sub map.
    std::cout<<"----"<<std::endl;
  }
*/

  //trasverse the map, appent to string, once base case it hit, popback from string, output string only when endOfWord is true.
  for (; it != child.end(); ++it) {		//base case is when it go to end of the map.
    a += it->first;
    if (it->second.endOfWord == true)
      std::cout<<a<<std::endl;
    child[it->first].print(a);			//recursivly call sub map.
    a.erase(a.end()-1);
  }
}

//removes a node from current level's map base on a char.
bool trieNode::remove(char& a) {
//call map's removal of [a]???
  child.erase(a);
  return true;
}

//removes a node base on a inputted string. it is assumed that a is not a empty string, and the string is contained in the map, that the overhead function that calls this will chk for both of that.
//works with complete word as well as subwords. Also deals with Capital letter.
bool trieNode::remove(std::string& a) {

  if (a == "") {	//base case, the return false means nothing in this context.
    return false;
  }
  
  char temp = a[0];
  if (temp >= 'A' and temp <= 'Z') 
    temp = temp + 32;
  a.erase(a.begin());
 
  child[temp].remove(a);	//recursive call. Goes down one level.

  if (a.size() == 0) {		//when the size string to be remove is 0, it means we have come to an end of word in the trie.
    child[temp].endOfWord = false;
  }

  if (child[temp].child.size() == 0 and (child[temp].endOfWord == false or a.size() == 0) ) {//end of word flag will stop the erase fct once it hit a end of word flag true. THere fore will not remove prefix, will have an exception when a leaf is reached.
    child.erase(temp);		//erase from child map, if the temp's child map's size is zero, which means it's at the end of the tree (in other words, end of the word).
    //std::cout<<"erasing child["<<temp<<"]"<<std::endl;
  }

  //maybe i dont need this, cuz if it's not size 0, it's gonna be some word, no need to change the flag.
  //if (child.size() > 0 and child[temp].endOfWord != true)	{	//this means the string being deleted is a sub word. Will change all flag to false until the next flag true is reached.
    //child[temp].endOfWord = false;		
    //std::cout<<"setting end of word to false for one level above: "<<temp<<std::endl; 
  //}
    
  return true;

  //only change the flag if it is a sub word.
  //how to detect if it's a sub word?
  //maybe last char of the string has a child.size > 0.


  //if last char is one of the last nodes, delete from map, and keep deleting up the level util (child.size > 1 or endOfWord flag = true is hit). Logic of trie is that all end branches MUST be true for the flag. and the logic for the child.size is that that node have other chars in its child, so it won't make sense to delete those other chars too.

  //to detect if last char is one of the end node, simply chk if child.size == 0.


  //probably would need an recusive solution. iterative might need two pointer, one points to the upper level, and the otehr points to the current level. might be complicated.
}

//recursivly count how many node are in the trie in real time. It really counts just the number of child under each node.
unsigned int trieNode::countNodes() {
  if (child.size() == 0)				//base case for when it hit a leaf node.
    return 0;						//this return accounts for when there's no child.

  std::map<char,trieNode>::iterator it;
  it = child.begin();
  unsigned int childNumber = 0;

  for (; it != child.end(); ++it, ++childNumber) {	//base case is when it go to end of the map. Also updates child number.
    childNumber += child[it->first].countNodes();	//recursivly call sub map. Will add on to child number the number of child of the child.
  } 
  //std::cout<<"This should not run"<<std::endl;
  return childNumber;						
}

//findWord helper, recursive call, will sometime return a empty string, if 
std::string trieNode::findWordHelper(std::string& a, const trieNode& node) {
  std::map<char,trieNode>::iterator it;
  it = child.begin();
  std::string word = "";

  //trasverse the map, appent to string, once base case it hit, popback from string, return the string if address matches.
  for (; it != child.end(); ++it) {		//base case is when it go to end of the map.
    a += it->first;
    if (&it->second == &node)
      return a;			//base case if address == address.
    word = child[it->first].findWordHelper(a,node);			//recursivly call sub map, store the base case output to be return when recursive call returns.
    a.erase(a.end()-1);
  }
  return word;
}

//called by dictionary class's suggest(), search trie for any word with last char that is the same address as the argument.
std::string trieNode::findWord(const trieNode& a) {
  std::string word = "";
  return findWordHelper(word,a);
}
