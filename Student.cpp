#include "Student.hpp"

#include <iostream>

Student::Student() : Person()
{
  setDiscipline(COMPUTER_SCIENCE);
}

Student::Student(std::string name, Discipline major) : Person(name)
{
  setDiscipline(major);
}

Student::~Student()
{
  std::cout << "Student object destroyed!" << std::endl;
}
