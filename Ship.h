#ifndef SHIP_H
#define SHIP_H

#include "Room.h"

#include <vector>
#include <sstream>

#define MIN_NUM_BAYS 1
#define MIN_NUM_BRGS 1
#define MIN_NUM_LATS 1
#define MIN_NUM_CABS 1

#define MAX_NUM_BAYS 4
#define MAX_NUM_BRGS 1
#define MAX_NUM_LATS 10
#define MAX_NUM_CABS 10

class Ship
{
	private:
		std::vector<Room> m_rooms;
		std::string m_name;
	public:
		Ship();
		~Ship() {};
		std::string getName() { return m_name; }
		bool addRoom(Room &room);
		int getNumOfType(RoomType type);
		int getSquareFootage();
		bool isValid();
		std::string getDescription();
};
#endif