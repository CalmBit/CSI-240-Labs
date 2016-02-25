#include "WordArray.h"
#include "Common.h"

#include <iostream>
#include <sstream>
#include <fstream>

const size_t DYNAMIC_ARRAY_INIT_VAL = 10;
const int NUMBER_OF_LINES = 6;

void fileMode(WordArray &array);
void stdinMode();
void resizeMode();

int main(int argc, char* argv[])
{
	WordArray wordArray{DYNAMIC_ARRAY_INIT_VAL};
	bool quitRequested = false;
	char currentSelection = '\0';
	do
	{
		dirtyClear();
		std::cout << "The magical word machine!" << std::endl << std::endl
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
				stdinMode();
				break;
			case 'R':
			case 'r':
				resizeMode();
				break;
			case 'Q':
			case 'q':
				quitRequested = true;
				break;
		}
	} while (!quitRequested);

	return 0;
}

void holdForInput()
{
	std::cout << std::endl << "Press any key to continue..." << std::endl;
	std::cin.get();
}

void dirtyClear()
{ 
	//Literally the ugliest hack.
	std::cout << std::string(TERMINAL_SIZE, '\n');
}

void fileMode(WordArray &array)
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
	  while(!fileStream.eof() && array.getCount() < array.getCapacity())
	  {
	    std::string str;
	    std::getline(std::cin, str);
	    array.insertWordAtIndex(str, array.getCount());
	  }
	  if(array.getCount() == array.getCapacity())
	  {
	    std::cerr << "[WARNING] Array is at maximum capacity." << std::endl
	              << "Data may have been truncated, and further data won't be added." << std::endl;
	  }
	}
	holdForInput();
}

void stdinMode()
{

}

void resizeMode()
{

}
