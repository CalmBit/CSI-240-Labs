/*
  Author:  Ethan Brooks
  Class:   CSI-240-02
  Assignment:  Lab 6
  Date Assigned: 2016-02-22
  Due Date:  2016-02-25, 11 AM
  Description:  Creates and copies Widget objects.
  Certification of Authenticity: 
  I certify that this is entirely my own work, except where I have given fully-documented references to the work of others. I understand the definition and consequences of plagiarism and acknowledge that the assessor of this assignment may, for the purpose of assessing this assignment:
      - Reproduce this assignment and provide a copy to another member of academic staff; and/or
      - Communicate a copy of this assignment to a plagiarism checking service (which may then retain a copy of this assignment on its database for the purpose of future plagiarism checking)
*/

#include "widget.h"

#include <sstream>

int Widget::seqID = 0;

Widget::Widget(WidgetType type)
{
  wType = type;
  wID = ++seqID;
  generateModelName();
}

Widget::Widget(const Widget& rhs)
{
  wType = rhs.wType;
  wID = ++seqID;
  generateModelName();
}

void Widget::generateModelName()
{
  std::stringstream str{};
  str << WIDGET_NAMES[wType] << " " << wID << " " << this;
  wModelName = str.str();
}
