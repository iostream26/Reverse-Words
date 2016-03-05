#include "stdafx.h" //Fundamental header file for 'Visual Studio 2015 C++'
#include "FunctionDeclarations.h"
#include <iostream> //Header file for standard library (std::)
#include <vector> //Header file for vectors
#include <string> //Header file for std::cin, to be able to read 'string' input from console
#include <Windows.h> //Header file for system("pause"), which makes console wait until 'Enter' is pressed
#include <algorithm> //Header file for reverse() void function

//--------------------------------

void errorHandling(unsigned int& _userSet_sizeOfWordsVector, std::string& _userSet_elementOfWordsVector) {
	do {
		std::cout << "How many words would you like to set?: ";
		std::cin >> _userSet_sizeOfWordsVector;

		if (_userSet_sizeOfWordsVector > 100 || _userSet_sizeOfWordsVector < 1) {
			do {
				std::cout << "  You can set only (1-100). Try again: ";
				std::cin >> _userSet_sizeOfWordsVector;
			} while (_userSet_sizeOfWordsVector > 100 || _userSet_sizeOfWordsVector < 1);
		}
	} while (_userSet_sizeOfWordsVector > 100 || _userSet_sizeOfWordsVector < 1);
}

//--------------------------------


/// <summary>
/// Task: sets the words for the vector.
///
/// Input: 
///		1. userSet_sizeOfWordsVector: user can set how many words are required to input
///		2. userSet_elementOfWordsVector: this is a temporary variable, which gets a string to add to the 'Words' vector
///		3. _Words.push_back(userSet_elementOfWordsVector): adds the temporary variable in 2. to the 'Words' vector using a pointer			declared as an argument
///
///	Output: -	
/// </summary>
/// <param name="_Words">The _ words.</param>
void setWords(std::vector<std::string>& _Words) 
{
	unsigned int userSet_sizeOfWordsVector;
	std::string userSet_elementOfWordsVector;

	errorHandling(userSet_sizeOfWordsVector, userSet_elementOfWordsVector);

	for (unsigned int i = 1; i <= userSet_sizeOfWordsVector; i = i + 1) {
		std::cout << i << ". element: ";
		std::cin >> userSet_elementOfWordsVector;

		_Words.push_back(userSet_elementOfWordsVector);
	}
}

//--------------------------------

/// <summary>
/// Task: sends the content of the 'Words' vector to the output (only for testing cases)
///
///	Input:
///		1. The 'Words' vector passed as an argument as a pointer
///
///	Output:
///		1. ALL of the elements of 'Words'
/// </summary>
/// <param name="_Words">The _ words.</param>
void testWords(std::vector<std::string>& _Words) 
{
	for (unsigned int i = 0; i < _Words.size(); i = i + 1) {
		std::cout << std::endl << _Words[i];
	}
	system("pause");
}

//--------------------------------

/// <summary>
///	Task: determines whether or not the !!current!! element - that is examined at the moment - can be red towards and backwards, too
///
///	Input:
///		1. 'Words' vector as a pointer
///		2. index pointer for 'Words' vector
///		3. _WordsReversed is a temporary vector that contains the current element in a reversed form
///		4. reverse() void function - included in algorithm.h - is reversing the elements of a string from the start to the end
///	Output:
///		1. since it is a boolean function, if the condition is true, it returns true value, else false
/// </summary> 
/// <param name="_Words">The _ words.</param>
/// <param name="index">The index.</param>
/// <returns></returns>
bool isTheSameTowardsANDBackwards(std::vector<std::string>& _Words, unsigned int& index) 
{
	std::vector<std::string> _WordsReversed;

	_WordsReversed.push_back(_Words[index]);

	reverse(_WordsReversed[0].begin(), _WordsReversed[0].end()); 

	if (_Words[index] == _WordsReversed[0]) {
		_WordsReversed.clear();
		return true;
	}
	else {
		_WordsReversed.clear();
		return false;
	}

	return false; //in the case of any error, it is needed to return false
}

//--------------------------------

/// <summary>
/// Task: takes the 'Words' vector as a pointer, and implements isTheSameTowardsANDBackwards() to all of its elements
///
///	Input:
///		1. 'Words' vector's pointer as an argument
///		2. isTheSameTowardsANDBackwards() function's pointer as an argument
///
///	Ouput:
///		1: text answer
/// </summary>
/// <param name="_Words">The _ words.</param>
void searchWordsAreTheSameTowardsANDBackwards(std::vector<std::string>& _Words, 
	bool (*_isTheSameTowardsANDBackwards)(std::vector<std::string>&, unsigned int&)) 
{
	for (unsigned int i = 0; i < _Words.size(); i++) {
		if (_isTheSameTowardsANDBackwards(_Words, i)) {
			std::cout << i + 1 << ". word is the same by reading towards and backwards, too!" << std::endl;
		}
		else {
			std::cout << i + 1 << ". word is NOT the same by reading towards and backwards, too!" << std::endl;
		}
	}
}

//--------------------------------

/// <summary>
/// Task: finally this function gathers the main functions for solving the task
///
///	Input:
///		1. setWords() function will ask the input from the user for 'Words' vector passed as a pointer argument
///
///	Output:
///		1. implementation of the method by searchWordsAreTheSameTowardsANDBackwards() function
/// </summary>
/// <param name="_Words">The _ words.</param>
void taskResult(std::vector<std::string>& _Words) 
{
	setWords(_Words);
	searchWordsAreTheSameTowardsANDBackwards(_Words, &isTheSameTowardsANDBackwards);
}

//--------------------------------

/// <summary>
/// Menu function for easing the control of the program.
///
///	Input:
///		1. userInput for user's choice
///
///	Output:
///		1. in the case of the choice, it calls the correct function or exits in the case of any error
/// </summary>
/// <param name="_Words">The _ words.</param>
void menu(std::vector<std::string>& _Words) 
{
	unsigned int userInput;

	do {

		std::cout << "Type (1) to start, type (2) to exit: ";
		std::cin >> userInput;

		switch (userInput) {
		case 1:
			taskResult(_Words);
			break;
		case 2:
			break;
		default:
			std::cout << "Wrong data! ";
			system("pause");
			userInput = 2;
			break;
		}
	} while (userInput != 2);
}