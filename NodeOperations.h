#ifndef NODEOPERATIONS_H
#define NODEOPERATIONS_H

#include "ListNode.h"

void append(ListNode *head);
size_t size(ListNode *head);
void display(ListNode *head);
void remove(ListNode *head);
void remove(ListNode *head, size_t loc);
void del(ListNode *head);

#endif