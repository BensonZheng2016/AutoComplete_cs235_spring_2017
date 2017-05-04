/***************************************************************
Title: Auto-Complete
Author: Yi Zong Kuang
Date Created: late april 2017
Class: Spring 2017, CSCI 235, Mon & Wed 5:35pm-6:50pm
Professor: Michael Garod
Purpose: Project 3 - Auto complete incomplete words.
Description: Defining trieNode struct.
***************************************************************/

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
