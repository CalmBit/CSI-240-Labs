#include "Student.hpp"

#include <iostream>

Student::Student() : Person()
{
  setDiscipline(COMPUTER_SCIENCE);
  std::cout << "Student object created using the default Student constructor" << std::endl;
}

Student::Student(std::string name, Discipline major) : Person(name)
{
  setDiscipline(major);
  std::cout << "Student object created using the alternate Student constructor" << std::endl;
}

Student::~Student()
{
  std::cout << "Student object destroyed!" << std::endl;
}
