#include "Person.hpp"

#include <iostream>

Person::Person()
{
  setName("");
  std::cout << "Person object created using the default Person constructor." << std::endl;
}

Person::Person(std::string name)
{
  setName(name);
  std::cout << "Person object created using the alternate Person constructor." << std::endl;
}

Person::~Person()
{
  std::cout << "Person object destroyed!" << std::endl;
}
