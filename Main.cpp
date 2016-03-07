/*
	Author:  Ethan Brooks
	Class:   CSI-240-02
	Assignment:  Assignment 3
	Date Assigned: 2016-02-25
	Due Date:  2016-03-03, 11 AM
	Description: Creates, fills, resizes, and destroys dynamic arrays of strings.
	Certification of Authenticity:
	I certify that this is entirely my own work, except where I have given fully-documented references to the work of others. I understand the definition and consequences of plagiarism and acknowledge that the assessor of this assignment may, for the purpose of assessing this assignment:
	- Reproduce this assignment and provide a copy to another member of academic staff; and/or
	- Communicate a copy of this assignment to a plagiarism checking service (which may then retain a copy of this assignment on its database for the purpose of future plagiarism checking)
*/

#include "Common.h"
#include "Modes.h"
#include "WordArray.h"

#include <iostream>

const size_t DYNAMIC_ARRAY_INIT_VAL = 10;

int main(int argc, char* argv[])
{
	WordArray wordArray{DYNAMIC_ARRAY_INIT_VAL};
	bool quitRequested = false;
	char currentSelection = '\0';
	do
	{
		dirtyClear();
		std::cout << "The magical word machine!" << std::endl
			<< "The current array capacity is: " << wordArray.getCapacity() << std::endl
			<< "The current array count is: " << wordArray.getCount() << std::endl << std::endl
			<< "(F)ile based reading" << std::endl
			<< "(T)ype some text yourself" << std::endl
			<< "(R)esize the dynamic array" << std::endl
			<< "(P)rint the array contents and capacity" << std::endl
			<< "(Q)uit this program" << std::endl << std::endl;
		std::cout << "? ";
		currentSelection = std::cin.get();
		std::cin.get();
		switch (currentSelection)
		{
			default:
				std::cerr << "Try that again, this time with a valid selection!" << std::endl;
				break;
			case 'F':
			case 'f':
				fileMode(wordArray);
				break;
			case 'P':
			case 'p':
				printMode(wordArray);
				break;
			case 'T':
			case 't':
				stdinMode(wordArray);
				break;
			case 'R':
			case 'r':
				resizeMode(wordArray);
				break;
			case 'Q':
			case 'q':
				quitRequested = true;
				break;
		}
	} while (!quitRequested);

	return 0;
}