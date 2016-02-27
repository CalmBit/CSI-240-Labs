#include "WordArray.h"

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

#include <iostream>
#include <sstream>
#include <fstream>

const size_t DYNAMIC_ARRAY_INIT_VAL = 10;

void fileMode(WordArray &wordArray);
void stdinMode(WordArray &wordArray);
void resizeMode(WordArray &wordArray);

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

void fileMode(WordArray &wordArray)
{
	dirtyClear();
	std::string filename;
	std::cout << "What file are you looking to load? ";
	std::getline(std::cin, filename);
	std::ifstream fileStream{filename};
	if(fileStream.bad())
	{
	  std::cerr << "Couldn't find file named " << filename << "!" << std::endl;
	}
	else
	{
	  while(!fileStream.eof() && wordArray.getCount() < wordArray.getCapacity())
	  {
	    std::string str;
		std::getline(fileStream, str);
		if (str.length() == 0) continue;
		if (wordArray.insertWordAtIndex(str, wordArray.getCount()))
		{
			std::cout << "Word added: " << str << std::endl;
		}
		else
		{
			std::cerr << "Word add failed..." << std::endl;
		}
	  }
	  if(wordArray.getCount() == wordArray.getCapacity())
	  {
	    std::cerr << "[WARNING] Array is at maximum capacity." << std::endl
	              << "Data may have been truncated, and further data won't be added." << std::endl;
	  }
	}
	holdForInput();
}

void stdinMode(WordArray &wordArray)
{
	dirtyClear();
	std::cout << "Type in a word, and press the return key." << std::endl 
			  << "Press the return key on an empty line to finish." << std::endl;
	bool quitRequested = false;
	std::string buffer{};
	while (!quitRequested)
	{
		std::getline(std::cin, buffer);
		if (buffer == "") quitRequested = true;
		else
		{
			if (wordArray.insertWordAtIndex(buffer, wordArray.getCount()))
			{
				std::cout << "Inserted word: " << buffer << std::endl;
			}
			else
			{
				std::cout << "[WARNING] Word not inserted. Your array might be full!" << std::endl;
			}
		}
	}
	holdForInput();
}

void resizeMode(WordArray &wordArray)
{
	dirtyClear();
	size_t newSize = 0;
	std::cout << "The current array size is " << wordArray.getCapacity() << " with " << wordArray.getCount() << " entries." << std::endl
		<< "How large should the new array be? (zero to cancel) ";
	std::cin >> newSize;
	std::cin.get();
	if (newSize == 0)
	{
		holdForInput();
		return;
	}
	wordArray.resizeArray(newSize);
	holdForInput();
}
