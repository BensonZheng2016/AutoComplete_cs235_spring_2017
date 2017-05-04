/***************************************************************
Title: Auto-Complete
Author: Yi Zong Kuang
Date Created: late april 2017
Class: Spring 2017, CSCI 235, Mon & Wed 5:35pm-6:50pm
Professor: Michael Garod
Purpose: Project 3 - Auto complete incomplete words.
Description: Defining a trie class.
***************************************************************/

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
  std::string findWord(const std::map<char,trieNode>::iterator& nodeIt);

 private:
  trieNode _root;
  unsigned int _wordcount;
};
#endif 
