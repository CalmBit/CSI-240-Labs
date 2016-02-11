#ifndef FUNCTIONS_H
#define FUNCTIONS_H

/*
  Author:  Ethan Brooks
  Class:   CSI-240-02
  Assignment:  Lab 5
  Date Assigned: 2016-02-08
  Due Date:  2016-02-15, 11 AM
  Description:  Creates, sorts, and displays a variable size dynamic array of integers.
  Certification of Authenticity: 
  I certify that this is entirely my own work, except where I have given fully-documented references to the work of others. I understand the definition and consequences of plagiarism and acknowledge that the assessor of this assignment may, for the purpose of assessing this assignment:
      - Reproduce this assignment and provide a copy to another member of academic staff; and/or
      - Communicate a copy of this assignment to a plagiarism checking service (which may then retain a copy of this assignment on its database for the purpose of future plagiarism checking)
*/

/*
  promptSize()
  Prompts user for the size of their new dynamic array.
  Returns entered size
 */
size_t promptSize();

void populate(size_t size, int *ptr);

void bubble_sort(size_t size, int *ptr);

void selection_sort(size_t size, int *ptr);

void display(size_t size, int *ptr);

#endif
