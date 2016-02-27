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

#include <iostream>

WordArray::WordArray(size_t capacity)
{
	this->m_capacity = capacity;
	this->m_arrayPtr = new std::string[capacity];
	for (int i = 0; i < capacity; i++)
		m_arrayPtr[i] = std::string{};
}

WordArray::WordArray(const WordArray &rhs)
{
	this->m_capacity = rhs.getCapacity();
	this->m_count = rhs.getCount();
	this->m_arrayPtr = rhs.getArrayPtr();
}

WordArray::~WordArray()
{
	delete[](m_arrayPtr);
}

bool WordArray::resizeArray(size_t newCapacity)
{
	std::string *temp = new std::string[newCapacity];
	if (this->m_count > newCapacity)
	{
		char selection = '\0';
		do
		{
			std::cerr << std::endl
				<< "[WARNING] You're making this new array " << std::endl
				<< "smaller than the count of the old array!" << std::endl
				<< "Data will be lost! Continue? (Y/N)";
			selection = std::cin.get();
			std::cin.get();
			switch (selection)
			{
				default:
					selection = '\0';
					break;
				case 'Y':
				case 'y':
					for (size_t i = 0; i < newCapacity; i++)
						temp[i].assign(this->m_arrayPtr[i]);
					this->m_count = newCapacity;
					break;
				case 'N':
				case 'n':
					delete[] temp;
					return false;
			}
		} while (selection == '\0');
	}
	else
	{
		for (size_t i = 0; i < this->m_count; i++)
			temp[i].assign(this->m_arrayPtr[i]);
	}
	delete[] this->m_arrayPtr;
	this->m_arrayPtr = temp;
	this->m_capacity = newCapacity;
	return true;
}

bool WordArray::insertWordAtIndex(const std::string &str, size_t index)
{
	if (this->m_capacity <= index || index < 0)
	{
		std::cerr << "Specified index (" << index << ") is invalid!" << std::endl;
		return false;
	}
	this->m_arrayPtr[index].assign(str);
	this->m_count++;
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