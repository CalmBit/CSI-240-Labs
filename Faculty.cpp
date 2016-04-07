#include "Faculty.hpp"

#include <iostream>

Faculty::Faculty() : Person()
{
  setDiscipline(Discipline::COMPUTER_SCIENCE);
  std::cout << "Faculty object created using the default Faculty constructor" << std::endl;
}

Faculty::Faculty(std::string name, Discipline discipline) : Person(name)
{
  setDiscipline(discipline);
  std::cout << "Faculty object created using the alternate Faculty constructor" << std::endl;
}

Faculty::~Faculty()
{
  std::cout << "Faculty object destroyed!" << std::endl;
}
