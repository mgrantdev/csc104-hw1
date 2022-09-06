/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/
#include <cstddef>
#include<iostream>
#include "split.h"
using namespace std;

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE

  // Traverse Linked List

  // @condition Break call tree if null value found
  if(in == nullptr) {
    return;
  }
  
  // @condition If even, value add to evens list
  if(in->value % 2 == 0) {
    evens = new Node(in->value, nullptr);
    split(in->next, odds, evens->next);

  } else {

    // @condition If odd, value add to odds list
    odds = new Node(in->value, nullptr);
    split(in->next, odds->next, evens);
  }

}

/* If you needed a helper function, write it here */

// WRITE YOUR CODE HERE