/*****************************************************************************************************************

Specification (short):
(1): 'Words' is a vector of words that are input by the user from console
(2): The index of 'Words' is `1..n` (whereas `1..n` are declared as unsigned integers)
(3): isTheSameTowardsANDBackwards() is a logical (boolean) function,
which examines that the current element of 'Words' vector is the same by reading it towards and bcakwards, too
(4): searchWordsAreTheSameTowardsANDBackwards() implements (3) function for all the elements of 'Words'
(5): taskResult() outputs the answer of the task for each element of 'Words'
(6): menu() function for menu items

*****************************************************************************************************************/

#pragma once
#ifndef FUNCTIONDECLARATIONS_H_INCLUDED
#define FUNCTIONDECLARATIONS_H_INCLUDE

	#include <iostream>
	#include <vector>

	//--------------------------------

	void setWords(std::vector<std::string>& _Words); //This function sets the elements of 'Words' vector 

	void testWords(std::vector<std::string>& _Words); //This function gets the elements of 'Words' vector (for only testing cases)

	//for more and detailed information please visit FunctionDefinitons.cpp
	bool isTheSameTowardsANDBackwards(std::vector<std::string>& _Words, unsigned int& index);
	void searchWordsAreTheSameTowardsANDBackwards(std::vector<std::string>& _Words, 
		bool(*_isTheSameTowardsANDBackwards)(std::vector<std::string>&, unsigned int&));
	void taskResult(std::vector<std::string>& _Words);
	void menu(std::vector<std::string>& _Words);

#endif