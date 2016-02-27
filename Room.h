#ifndef ROOM_H
#define ROOM_H

#include <string>

enum RoomType
{
	NILL = -1,
	BAY,
	LATRINE,
	BRIDGE,
	CABIN
};

const std::string roomNames[] =
{
	"Bay",
	"Latrine",
	"Bridge",
	"Cabin"
};

class Room
{
	private:
		RoomType m_type;
		int m_width, m_length, m_height;
	public:
		Room() {};
		~Room() {};
		Room(RoomType, int, int, int);
		Room(const Room& room);
		RoomType getRoomType() { return m_type; }
		int getSquareFootage() { return m_width*m_length; }
		int getWidth() { return m_width; }
		int getLength() { return m_length; }
		int getHeight() { return m_height; }
		std::string getName() { return roomNames[m_type]; }
		void setType(RoomType type);
		void setWidth(int width);
		void setLength(int length);
		void setHeight(int height);
		bool roomValid() { return getSquareFootage() >= 20 && getHeight() >= 7; }
};

#endif