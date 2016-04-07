#ifndef FACULTY_H
#define FACULTY_H

#include "Person.hpp"

class Faculty : public Person
{
private:
  Discipline department;
public:
  void setDepartment(Discipline department) {this->department = department;}
  std::string getDepartment() {return DISCIPLINE_STRING[this->department];}
  Faculty();
  Faculty(std::string name, Discipline department);
  ~Faculty();
};
#endif
