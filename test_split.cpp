/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>

void printList(Node* head) {
    while (head) {
        std::cout << head->value << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main(int argc, char* argv[]) {
    // Create a sorted linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> nullptr
    Node* head = new Node(1, new Node(2, new Node(3, new Node(4, new Node(5, new Node(6, nullptr))))));
    
    // Declare empty lists for odds and evens
    Node* odds = nullptr;
    Node* evens = nullptr;
    
    // Perform the split
    split(head, odds, evens);
    
    // Print the results
    std::cout << "Odds: ";
    printList(odds);
    
    std::cout << "Evens: ";
    printList(evens);
		  // Cleanup memory
    while (odds) {
        Node* temp = odds;
        odds = odds->next;
        delete temp;
    }
    while (evens) {
        Node* temp = evens;
        evens = evens->next;
        delete temp;
    }
    
    return 0;
}