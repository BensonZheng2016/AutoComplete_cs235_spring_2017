#ifndef TRIE_H
#define TRIE_H
#include "trieNode.h"
#include <fstream> 

class trie {
 public:
  trie();
  trie(std::ifstream& myDictionaryFile);
  ~trie();

  trieNode* find(std::string& a);
  trieNode* findAny(std::string& a);
  void show();
  bool empty();
  std::string changeToAllLowerCase(std::string& a);
  bool contain(char a);
  bool contain(std::string a);
  bool insert(char a);
  bool insert(std::string a);
  void print();
  bool remove(std::string a);
  void clear();
  unsigned int numWords();
  unsigned int countNodes();
  bool load(std::string a);

 private:
  trieNode _root;
  unsigned int _wordcount;
};
#endif 
