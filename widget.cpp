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
