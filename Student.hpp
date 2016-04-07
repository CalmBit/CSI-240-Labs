#ifndef STUDENT_H
#define STUDENT_H

#include "Person.hpp"

class Student : public Person
{
private:
  Discipline major;
public:
  void setMajor(Discipline major) {this->major = major;}
  std::string getMajor() {return DISCIPLINE_STRINGS[this->major];}
  Student();
  Student(std::string name, Discipline major);
  ~Student();
};
#endif
