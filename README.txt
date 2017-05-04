/***************************************************************
Title: Auto-Complete
Author: Yi Zong Kuang
Date Created: late april 2017
Class: Spring 2017, CSCI 235, Mon & Wed 5:35pm-6:50pm
Professor: Michael Garod
Purpose: Project 3 - Auto complete incomplete words.
Description: Read Me File.
***************************************************************/

Build Instruction:
	1. In terminal, go to file directory.
 	2. type in "make" , without the quotation marks.
	3. type in "./Autocomplete" to run program, without the quotation marks.

Known bug:
	1. find() sometime returns an empty string. Doesn't affect program, but does affect slightly on efficiency.

Program structure:
	Data: trieNode.
     	
   	Container: Trie, and Dictionary.

 	Interface: Main.cpp.

	
	-Trie contains the root trieNode. 
	-A trieNode contain a end of word flag (if true, it's a end of word character) and a map of more trieNode.
	-A dictionary is a wrapper around a trie. Only difference is it will return a vector of strings from the trie through the call to suggest().
	-Main.cpp creates a dictionary through a constructor with a filestream as parameter.
	-Program doesn't terminate until ctrl + c is press on terminal.
