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
