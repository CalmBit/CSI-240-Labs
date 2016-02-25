#include "WordArray.h"
#include <iostream>

WordArray::WordArray(size_t capacity)
{
	this->m_count = capacity;
	this->m_arrayPtr = new std::string[capacity];
}

WordArray::~WordArray()
{
	delete[](m_arrayPtr);
}

WordArray WordArray::constructFromOldArray(const WordArray &copy, size_t newCapacity)
{
	WordArray newArray{ newCapacity };
	if (copy.m_count > newCapacity)
	{
		char selection = '\0';
		do
		{
			std::cerr << std::endl
				<< "[WARNING] You're making this new array " << std::endl
				<< "smaller than the count of the old array!" << std::endl
				<< "Data will be lost! Continue? (Y/N)";
			selection = std::cin.get();
			switch (selection)
			{
				default:
					selection = '\0';
					break;
				case 'Y':
				case 'y':
					for (size_t i = 0; i < newCapacity; i++)
						newArray.insertWordAtIndex(copy.getWordAtIndex(i), i);
					return newArray;
				case 'N':
				case 'n':
					break;
			}
		} while (selection == '\0');
	}
	newArray.setBad();
	return newArray;
}

bool WordArray::insertWordAtIndex(const std::string &str, size_t index)
{
	if (this->m_count < index || index < 0)
	{
		std::cerr << "Specified index (" << index << ") is invalid!" << std::endl;
		return false;
	}
	this->m_arrayPtr[index].assign(str);
	return true;
}

std::string WordArray::getWordAtIndex(size_t index) const
{
	if (index > this->m_capacity)
	{
		std::cerr << "Requested index was larger than the capacity array!" << std::endl;
		return "";
	}
	if (index > this->m_count) return "";
	return this->m_arrayPtr[index];
}