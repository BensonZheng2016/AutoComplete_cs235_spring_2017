#ifndef DICTIONARY_H
#define DICTIONARY_H
#include "trie.h"
#include "trieNode.h"
#include <vector>

class dictionary {
 public:
  dictionary();
  dictionary(std::ifstream& myDictionaryFile);
  ~dictionary();

  bool load(std::string a);
  bool isLegalWord(std::string a);
  unsigned int numWords();
  std::vector<std::string> suggest(std::string s, int n);

  //for testing purposes
  void print();
  trieNode* findAny(std::string a);

 private:
  trie _data;  
};
#endif
