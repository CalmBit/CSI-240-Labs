#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person
{
protected:
  std::string name;
public:
  void setName(std::string name) {this->name = name;}
  std::string getName() {return this->name;}
  Person();
  Person(std::string name);
  ~Person();
};
#endif
