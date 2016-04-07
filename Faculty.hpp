#ifndef FACULTY_H
#define FACULTY_H

#include "Person.hpp"

class Faculty : public Person
{
private:
  Discpline discipline;
public:
  void setDiscipline(Discipline discipline) {this->discipline = discipline};
  Discipline getDiscipline() {return this->discipline};
  Faculty();
  Faculty(std::string name, Discipline discipline);
  ~Faculty();
};
#endif
