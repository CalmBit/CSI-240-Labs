//
//  lab7.cpp
//  inheritance
//

#include <iostream>
#include <string>

using namespace std;

enum Discipline {
   COMPUTER_SCIENCE, COMPUTER_SCIENCE_AND_INNOVATION
};

const string DISCIPLINE_STRINGS[2] = { "Computer Science",
   "Computer Science and Innovation",
};

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

class Faculty : public Person
{
private:
  Discipline department;
public:
  void setDepartment(Discipline department) {this->department = department;}
  std::string getDepartment() {return DISCIPLINE_STRINGS[this->department];}
  Faculty();
  Faculty(std::string name, Discipline department);
  ~Faculty();
};

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

Faculty::Faculty() : Person()
{
  setDepartment(COMPUTER_SCIENCE);
  std::cout << "Faculty object created using the default Faculty constructor" << std::endl;
}

Faculty::Faculty(std::string name, Discipline discipline) : Person(name)
{
  setDepartment(discipline);
  std::cout << "Faculty object created using the alternate Faculty constructor" << std::endl;
}

Faculty::~Faculty()
{
  std::cout << "Faculty object destroyed!" << std::endl;
}

Student::Student() : Person()
{
  setMajor(COMPUTER_SCIENCE);
  std::cout << "Student object created using the default Student constructor" << std::endl;
}

Student::Student(std::string name, Discipline major) : Person(name)
{
  setMajor(major);
  std::cout << "Student object created using the alternate Student constructor" << std::endl;
}

Student::~Student()
{
  std::cout << "Student object destroyed!" << std::endl;
}

int main()
{
   
   Faculty prof("Narine Hall", COMPUTER_SCIENCE);
   Student stu("Ethan Brooks", COMPUTER_SCIENCE_AND_INNOVATION);

   cout << endl << "I, " << stu.getName() << ", am majoring in " << stu.getMajor() << "." << endl;
   cout << "I am taking CSI 240 with Prof. " << prof.getName() << ", who teaches "
        << prof.getDepartment() << " courses." << endl << endl;
   
   return 0;
}

