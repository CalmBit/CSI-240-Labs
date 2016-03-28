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
	  remove(head);
	  break;
	}
        case 'E':
        case 'e':
	{
	  std::cout << "What index would you like to remove? (maxmimum " << (size(head) - 1) << ") ";
	  size_t loc = 0;
	  std::cin >> loc;
	  std::cin.get();
	  remove(head, loc);
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
