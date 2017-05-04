#ifndef TRIENODE_H
#define TRIENODE_H
#include <map>

struct trieNode {
  void show(int i);
  bool empty();
  bool contain(char& a);
  trieNode* find(std::string& a);
  trieNode* findAny(std::string& a);
  char upperToLower(char& a);
  bool insert(char& a);
  bool insert(std::string& a);
  void print(std::string& a);
  bool remove(char& a);
  bool remove(std::string& a);
  unsigned int countNodes();
  std::string findWordHelper(std::string& a, const std::map<char,trieNode>::iterator& nodeIt, std::string& suffix);
  std::string findWord(const std::map<char,trieNode>::iterator& nodeIt);
 
  std::map<char, trieNode> child;
  bool endOfWord = false;
};
#endif
