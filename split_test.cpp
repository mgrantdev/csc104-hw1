#include "split.h"
#include<iostream>

using namespace std;

int main() {

    Node* head = nullptr;
    Node* second = nullptr;
    Node* third = nullptr;

    Node* odds = nullptr;
    Node* evens = nullptr;
 
    // allocate 3 nodes in the heap
    third = new Node(15, nullptr);
    second = new Node(10, third);
    head = new Node(5, second);

    split(head, odds, evens);

    // clean up
    delete third;
    delete second;
    delete head;
    while(odds != 0) {
        Node* cursor = odds->next;
        delete odds;
        odds = cursor;
    }
    while(evens != 0) {
        Node* cursor = evens->next;
        delete evens;
        evens = cursor;
    }

    return 0;


}