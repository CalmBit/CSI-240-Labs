#ifndef WORDARRY_H
#define WORDARRY_H

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

#include <string>
#include <iostream>

class WordArray
{
public:
	WordArray(size_t capacity);
	~WordArray();
	WordArray(const WordArray &rhs);
	bool resizeArray(size_t newCapacity);
	bool insertWordAtIndex(const std::string &str, size_t index);
	std::string getWordAtIndex(size_t index) const;
	size_t getCount() const { return m_count; }
	size_t getCapacity() const { return m_capacity; }
	std::string *getArrayPtr() const { return m_arrayPtr; }

	WordArray &operator=(const WordArray &rhs);
	WordArray operator+(const WordArray &rhs) const;
	WordArray operator+(const std::string &rhs) const;
	WordArray operator-(const std::string &rhs) const;
	bool operator==(const WordArray &rhs) const;
	friend std::istream &operator>>(std::istream &strm, WordArray &rhs)
	{
		strm >> rhs.m_capacity >> rhs.m_count;
		if (rhs.m_count > rhs.m_capacity)
		{
			std::cerr << "[ERROR] Count is larger than the capacity of the array!" << std::endl;
		}
		else
		{
			if(rhs.m_arrayPtr != nullptr) delete[] rhs.m_arrayPtr;
			rhs.m_arrayPtr = new std::string[rhs.m_capacity];
			for (size_t i = 0; i < rhs.m_count; i++)
			{
				strm >> rhs.m_arrayPtr[i];
			}
		}
		return strm;
	}
	friend std::ostream &operator<<(std::ostream &strm, WordArray &rhs)
	{
		strm << "Array Capacity: " << rhs.getCapacity() << std::endl
			<< "Array Count: " << rhs.getCount() << std::endl
			<< "Array Contents: " << std::endl;
		for (size_t i = 0; i < rhs.getCount(); i++)
		{
			strm << "Word at Index " << i << ": " << rhs.getWordAtIndex(i) << std::endl;
		}
		return strm;
	}
private:
	std::string *m_arrayPtr;
	size_t m_count;
	size_t m_capacity;
};

#endif
