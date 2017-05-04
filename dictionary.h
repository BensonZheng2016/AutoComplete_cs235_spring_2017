/***************************************************************
Title: Auto-Complete
Author: Yi Zong Kuang
Date Created: late april 2017
Class: Spring 2017, CSCI 235, Mon & Wed 5:35pm-6:50pm
Professor: Michael Garod
Purpose: Project 3 - Auto complete incomplete words.
Description: Defining a dictionary class. Which is a wrapper around a trie class.
***************************************************************/

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
  void print();
  trieNode* findAny(std::string a);
  std::string findWord(const std::map<char,trieNode>::iterator& nodeIt);
  unsigned int countNodes();

 private:
  trie _data;  
};
#endif
