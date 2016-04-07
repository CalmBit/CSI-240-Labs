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


int main()
{
   
   Faculty prof("Narine Hall", COMPUTER_SCIENCE);
   Student stu("Ethan Brooks", YOUR_MAJOR);

   cout << endl << "I, " << stu.getName() << ", am majoring in " << stu.getMajor() << "." << endl;
   cout << "I am taking CSI 240 with Prof. " << prof.getName() << ", who teaches "
        << prof.getDepartment() << " courses." << endl << endl;
   
   return 0;
}

