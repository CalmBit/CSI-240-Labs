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
#include "NodeOperations.h"

#include <iostream>

void append(ListNode *head, std::string nodeData)
{
  if (head == nullptr) std::cerr << "[ERROR] HEAD wasn't initialized! Can't append to non-existant list!" << std::endl;
  else
  {
    ListNode *next = head;
    // Make sure, for whatever reason, that the next entry isn't null - it shouldn't ever be, but we
    // need to be super safe when addressing memory!
    while (next != nullptr)
    {
      if (next->next == nullptr) break;
      next = next->next;
    }

    // This shouldn't ever be triggered - edge case in case a list becomes impossibly broken.
    if (next == nullptr) std::cerr << "[ERROR] Append operation executed on broken list!" << std::endl;
    else
    {
      ListNode *newNode = new ListNode();
      newNode->data.assign(nodeData);
      newNode->next = nullptr;
      next->next = newNode;
      std::cout << "Added \"" << nodeData << "\" to the end of the linked list." << std::endl;
     }
  }
}

size_t size(ListNode *head)
{
  size_t size = 0;
  ListNode *next = head;
  while (next->next != nullptr)
  {
      size++;
      next = next->next;
  }
  return size + 1;
}

void display(ListNode *head)
{
  ListNode *next = head;
  size_t iterator = 0;
  while(next != nullptr)
  {
    std::cout << "Node at index " << iterator << "(address " << next << (iterator == 0 ? " HEAD" : "") <<  "): " << next->data << std::endl;
    next = next->next;
    iterator++;
  }
  std::cout << "Total entries: " << iterator << std::endl;
}

void remove(ListNode *head)
{
  // If nothing is in the list, then we're gonna have trouble removing something!
  if(head == nullptr) std::cerr << "[ERROR] Can't remove anything from empty list!" << std::endl;
  // If only one element is in the list (the head element), then we can't really "remove" an element! Tell the user
  // to delete the list.
  else if(head->next == nullptr) std::cerr << "[ERROR] Can't remove HEAD element - list must be deleted instead!" << std::endl;
  //Wow, there's more than one element! Remove the last one!
  else
  {
    ListNode *next = head;
    ListNode *prev = head;
    while(next->next != nullptr)
    {
      prev = next;
      next = next->next;
    }
    std::cout << "Deleting node at end of list...";
    delete(next);
    prev->next = nullptr;
    std::cout << "done!";
  }
}

void remove(ListNode *head, size_t loc)
{
  // If nothing is in the list, then we're gonna have trouble removing something!
  if(head == nullptr) std::cerr << "[ERROR] Can't remove anything from empty list!" << std::endl;
  // If only one element is in the list (the head element), then we can't really "remove" an element! Tell the user
  // to delete the list.
  else if(head->next == nullptr) std::cerr << "[ERROR] Can't remove HEAD element - list must be deleted instead!" << std::endl;

  size_t listSize = size(head);
  // If the location refers to an invalid index, we can't delete it!
  if(loc >= listSize) std::cerr << "[ERROR] Location passed to remove() was invalid! Can't remove non-existant element!" << std::endl;
  else
  {
    ListNode *prev = head;
    ListNode *next = head;
    for(size_t i = 0;i < loc;i++)
    {
      prev = next;
      next = next->next;
    }
    std::cout << "Deleting node at index " << loc << "...";
    prev->next = next->next;
    delete(next);
    std::cout << "done!" << std::endl;
  }
}

void del(ListNode *head)
{
  // If the passed pointer is already null, we're gonna assume it's already deleted
  if(head == nullptr) std::cerr << "[ERROR] Can't delete an empty list!" << std::endl;
  // Otherwise, let's just delete the bloody thing
  else
  {
    ListNode *next = head;
    ListNode *prev = head;
    std::cout << "Deleting list...";
    while(next->next != nullptr)
    {
      prev = next;
      next = next->next;
      delete(prev);
    }
    delete(next);
    std::cout << "done!" << std::endl;
  }
}
