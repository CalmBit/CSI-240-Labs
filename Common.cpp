#include "Common.h"

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

#include <iostream>

void holdForInput()
{
	std::cout << std::endl << "Press any key to continue..." << std::endl;
	std::cin.get();
}

void dirtyClear()
{
	//Literally the ugliest hack.
	for (int i = 0; i < TERMINAL_SIZE; i++)
	{
		std::cout << std::endl;
	}
}