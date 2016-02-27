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
private:
	std::string *m_arrayPtr;
	size_t m_count;
	size_t m_capacity;
};

#endif
