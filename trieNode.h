#ifndef TRIENODE_H
#define TRIENODE_H
#include <map>

//uses a map (or can be array of size 26) for fast access. 
struct trieNode {
  void show(int i);
  bool empty();
  bool contain(char& a);
  trieNode* find(std::string& a);
  trieNode* findAny(std::string& a);
  //bool contain(std::string a, std::string& buffer);
  char upperToLower(char& a);
  bool insert(char& a);
  bool insert(std::string& a);
  void print(std::string& a);
  bool remove(char& a);
  bool remove(std::string& a);
  unsigned int countNodes();
 
  std::map<char, trieNode> child;
  bool endOfWord = false;
};
#endif
