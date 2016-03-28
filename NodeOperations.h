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
#ifndef NODEOPERATIONS_H
#define NODEOPERATIONS_H

#include "ListNode.h"

#include <string>

void append(ListNode *head, std::string data);
size_t size(ListNode *head);
void display(ListNode *head);
void remove(ListNode *head);
void remove(ListNode *head, size_t loc);
void del(ListNode *head);

#endif
