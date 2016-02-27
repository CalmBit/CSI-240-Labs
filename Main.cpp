#include <iostream>
#include <string>
#include <fstream>

#include "Ship.h"
int main(int argc, char* argv[])
{
	std::ifstream file{ "ShipData.txt" };
	if (file.bad())
	{
		std::cout << "File ShipData.txt not found!" << std::endl;
		return 1;
	}
	Ship ship{};
	while (!file.eof())
	{
		int id, w, l, h;
		file >> id >> w >> l >> h;
		ship.addRoom(Room{ (RoomType)id, w, l, h });
	}
	std::cout << std::endl << ship.getDescription() << std::endl;
	std::cout << (ship.isValid() ? "This ship can fly!" : "This ship CANNOT fly!") << std::endl;
	std::cin.get();
	return 0;
}