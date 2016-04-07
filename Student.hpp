#ifndef STUDENT_H
#define STUDENT_H

class Student : public Person
{
private:
  Discipline major;
public:
  void setMajor(Discipline major) {this->major = major;}
  Discipline getMajor() {return this->major;}
  Student();
  Student(std::string name, Discipline major);
  ~Student();
};
#endif
