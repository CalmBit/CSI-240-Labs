#include "Ship.h"

#include <sstream>

Ship::Ship()
{
	m_rooms = std::vector<Room>{};
	m_name = "U.S.S. Blahblahblah";
}

bool Ship::addRoom(Room &room)
{
	if (!room.roomValid()) return false;
	m_rooms.push_back(room);
	return true;
	
}

int Ship::getNumOfType(RoomType type)
{
	int count = 0;
	for (std::vector<Room>::iterator i = m_rooms.begin(); i != m_rooms.end(); i++) if (i->getRoomType() == type) count++;
	return count;
}

int Ship::getSquareFootage()
{
	int footage = 0;
	for (std::vector<Room>::iterator i = m_rooms.begin(); i != m_rooms.end(); i++) footage += i->getSquareFootage();
	return footage;
}

bool Ship::isValid()
{
	int numBays, numLats, numBrgs, numCabs;
	numBays = getNumOfType(RoomType::BAY);
	numLats = getNumOfType(RoomType::LATRINE);
	numBrgs = getNumOfType(RoomType::BRIDGE);
	numCabs = getNumOfType(RoomType::CABIN);
	bool minReq = numBays >= MIN_NUM_BAYS &&
				  numLats >= MIN_NUM_LATS &&
				  numBrgs >= MIN_NUM_BRGS &&
				  numCabs >= MIN_NUM_CABS;
	bool maxReq = numBays <= MAX_NUM_BAYS &&
				  numLats <= MAX_NUM_LATS &&
				  numBrgs <= MAX_NUM_BRGS &&
				  numCabs <= MAX_NUM_CABS;
	return minReq && maxReq;
}

std::string Ship::getDescription()
{
	std::stringstream strm{};
	strm << "The ship " << m_name << " has the following rooms: " << std::endl;
	for (int i = 0; i < 4; i++)
	{
		strm << getNumOfType((RoomType)i) << " " << roomNames[i] << "s" << std::endl;
	}
	strm << "The ship's area is approximately " << getSquareFootage() << " sq. ft." << std::endl;
	return strm.str();
}