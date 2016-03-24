#include "NodeOperations.h"

#include <iostream>

void append(ListNode *head, std::string nodeData)
{
	if (head == nullptr) std::cerr << "HEAD wasn't initialized! Can't append to non-existant list!" << std::endl;
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

		//This shouldn't ever be triggered - edge case in case a list becomes impossibly broken.
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
	while (head->next != nullptr) size++;
	return size + 1;
}
void display(ListNode *head)
{

}
void remove(ListNode *head);
void remove(ListNode *head, size_t loc);
void del(ListNode *head);