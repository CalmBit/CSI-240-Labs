#ifndef WORDARRY_H
#define WORDARRY_H

#include <string>

class WordArray
{
public:
	WordArray(size_t capacity);
	~WordArray();
	static WordArray constructFromOldArray(const WordArray &copy, size_t newCapacity);
	bool insertWordAtIndex(const std::string &str, size_t index);
	std::string getWordAtIndex(size_t index) const;

	//Has the WordArray been flagged as bad?
	bool getBadness() { return bad; }

	//If a WordArray has been flagged as bad, we should never allow it to be
	//flagged as good again.
	void setBad() { bad = true; }
private:
	std::string *m_arrayPtr;
	size_t m_count;
	size_t m_capacity;
	//Is this a valid wordArray?
	bool bad;
};

#endif