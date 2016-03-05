========================================================================
    CONSOLE APPLICATION : ReversedWord Project Overview
========================================================================

This file contains a summary of what you will find in each of the files that
make up the (this) ReversedWord application.

Main Task:
	Is it true or not, that the words of an array are the same by reading them towards and backwards, too?

main.cpp
	This is the main source file, that initialize the solution of the task.
	In this file, you can find the main() function, in which it declares a vector for the task, called 'Words'.
	Also, calles a function, called menu() for menu items. (see in FunctionDeclaration.h).

FunctionDeclarations.h
	This is the header file for declaring the functions for the task.
	You can find a specification for each functions delcared there.

FunctionDefinitions.cpp
	This is the source file for the function of the task declared in FunctionDeclarations.h file.
	Here, too, is included a specification that specifies the functions one-by-one.

Specification (short):
	(1): 'Words' is a vector of words that are input by the user from console
	(2): The index of 'Words' is `1..n` (whereas `1..n` are declared as unsigned integers, `n` can be 100 at the maximum)
	(3): isTheSameTowardsANDBackwards() is a logical (boolean) function,
		which examines that the current element of 'Words' vector is the same by reading it towards and bcakwards, too
	(4): searchWordsAreTheSameTowardsANDBackwards() implements (3) function for all the elements of 'Words'
	(5): taskResult() outputs the answer of the task for each element of 'Words'
	(6): menu() function for menu items

ReversedWord.vcxproj
    This is the main project file for VC++ projects generated using an Application Wizard.
    It contains information about the version of Visual C++ that generated the file, and
    information about the platforms, configurations, and project features selected with the
    Application Wizard.

ReversedWord.vcxproj.filters
    This is the filters file for VC++ projects generated using an Application Wizard. 
    It contains information about the association between the files in your project 
    and the filters. This association is used in the IDE to show grouping of files with
    similar extensions under a specific node (for e.g. ".cpp" files are associated with the
    "Source Files" filter).

ReversedWord.cpp
    This is the main application source file.

/////////////////////////////////////////////////////////////////////////////
Other standard files:

StdAfx.h, StdAfx.cpp
    These files are used to build a precompiled header (PCH) file
    named ReversedWord.pch and a precompiled types file named StdAfx.obj.

/////////////////////////////////////////////////////////////////////////////
Other notes:

AppWizard uses "TODO:" comments to indicate parts of the source code you
should add to or customize.

/////////////////////////////////////////////////////////////////////////////
