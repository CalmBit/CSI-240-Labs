/* 
   Author: Ethan Brooks
   Class: CSI-240-02
   Assignment: Lab 7
   Date Assigned: 2016-03-24
   Due Date: 2016-03-31, 11 AM
   Description:
      Allows a user to create, append and remove elements to and from, and delete a linked list of "nodes".
   Certification of Authenticity:
   I certify that this is entirely my own work, except where I have given fully-documented references to the work of others. I understand the
definition and consequences of plagiarism and acknowledge that the assessor of this assignment may, for the purpose of assessing this assignment:
     - Reproduce this assignment and provide a copy to another member of academic staff; and/or
     - Communicate a copy of this assignment to a plagiarism checking service (which may then retain a copy of this assignment on its database for the purpose of future plagiarism checking)
*/
#include "ListNode.h"
#include "NodeOperations.h"

#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
  ListNode *head = nullptr;
  bool quitRequested = false;
  while(!quitRequested)
  {
    char selection = '\0';
    if(head == nullptr)
    {
      std::cout << "(C)reate the list" << std::endl;
      std::cout << "(Q)uit the application" << std::endl;
      std::cout << "? ";
      std::cin >> selection;
      std::cin.get();
      switch(selection)
      {
        default:
	{
	  std::cout << "Invalid selection." << std::endl;
	  break;
	}
        case 'C':
        case 'c':
	{
	  std::cout << "What data would you like the first node to contain? ";
	  std::string nodeData;
	  std::getline(std::cin, nodeData);
	  std::cout << "Creating list's HEAD node...";
	  head = new ListNode();
	  head->data.assign(nodeData);
	  std::cout << "done!" << std::endl;
	  break;
	}
        case 'Q':
        case 'q':
	{
	  quitRequested =  true;
	  break;
	}
      }
    }
    else
    {
      std::cout << "(A)ppend a value to the list" << std::endl;
      std::cout << "(R)emove a value from the end of the list" << std::endl;
      std::cout << "R(e)move a value from a specific location in the list" << std::endl;
      std::cout << "(D)elete the list" << std::endl;
      std::cout << "D(i)splay the list" << std::endl;
      std::cout << "Display the (S)ize of the list" << std::endl;
      std::cout << "(Q)uit the application" << std::endl;
      std::cout << "? ";
      std::cin >> selection;
      std::cin.get();
      switch(selection)
      {
        case 'A':
        case 'a':
	{
	  std::cout << "What value would you like to append? ";
	  std::string nodeData;
	  std::getline(std::cin, nodeData);
	  append(head,nodeData);
	  break;
	}
        case 'R':
        case 'r':
	{  
	  head = remove(head);
	  break;
	}
        case 'E':
        case 'e':
	{
	  std::cout << "What index would you like to remove? (maxmimum " << (size(head) - 1) << ") ";
	  size_t loc = 0;
	  std::cin >> loc;
	  std::cin.get();
	  head = remove(head, loc);
	  break;
	}
        case 'D':
        case 'd':
	{
	  del(head);
	  head = nullptr;
	  break;
	}
        case 'I':
        case 'i':
	{
	  display(head);
	  break;
	}
        case 'S':
        case 's':
	{
	  size_t temp = size(head);
	  std::cout << "The list has " << temp << " node" << (temp > 1 ? "s" : "") << "." << std::endl;
	  break;
	}
	case 'Q':
        case 'q':
	{
	  quitRequested =  true;
	  break;
	}
      }
    }
    std::cout << std::endl << std::endl;
  }
}
