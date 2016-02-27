#include "Room.h"

#include <iostream>

//Copy constructor, for the purpose of vectoring

Room::Room(RoomType type, int width, int length, int height)
{
	std::cout << "Building room - ";
	m_type = type;
	std::cout << roomNames[type] << ":";
	m_width = width;
	std::cout << " Width: " << m_width;
	m_length = length;
	std::cout << " Length: " << m_length;
	m_height = height;
	std::cout << " Height: " << m_height;
	std::cout << " SqFt: " << getSquareFootage() << std::endl;
	if (getSquareFootage() < 20) std::cerr << "WARNING: This room won't report as valid, as its area is too small!" << std::endl;
	if (m_height < 7) std::cerr << "WARNING: This room won't report as valid, as its height is too low!" << std::endl;
}

Room::Room(const Room& room)
{
	m_type = room.m_type;
	m_width = room.m_width;
	m_length = room.m_length;
	m_height = room.m_height;
}

void Room::setType(RoomType type)
{
	m_type = type;
}
void Room::setWidth(int width)
{
	if (width*m_length < 20) std::cerr << "Whoops! A width of " << width << " in this " << getName() << " will set the area below 20!" << std::endl;
	else m_width = width;
}
void Room::setLength(int length)
{
	if (length*m_width < 20) std::cerr << "Whoops! A length of " << length << " in this " << getName() << " will set the area below 20!" << std::endl;
	else m_length = length;
}
void Room::setHeight(int height)
{
	if (height < 7) std::cerr << "Whoops! A height of " << height << "in this " << getName() << " is under the limit of 7!";
	else m_height = height;
}