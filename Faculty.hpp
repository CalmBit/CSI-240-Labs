#ifndef FACULTY_H
#define FACULTY_H

#include "Person.hpp"

class Faculty : public Person
{
private:
  Discpline department;
public:
  void setDepartment(Discipline department) {this->department = department;}
  Discipline getDepartment() {return this->department;}
  Faculty();
  Faculty(std::string name, Discipline department);
  ~Faculty();
};
#endif
