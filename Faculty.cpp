#include "Faculty.hpp"

Faculty::Faculty() : Person()
{
  setDiscipline(Discipline::COMPUTER_SCIENCE);
}

Faculty::Faculty(std::string name, Discipline discipline) : Person(name)
{
  setDiscipline(discipline);
}
