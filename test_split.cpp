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
    while (head != NULL) {
        std::cout << head->value << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

void deleteList(Node* head) {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;  // Delete each node
    }
}

int main(int argc, char* argv[]) {
    Node* in = new Node{1, nullptr};
    in->next = new Node{2, nullptr};
    in->next->next = new Node{3, nullptr};
    in->next->next->next = new Node{4, nullptr};

    Node* odds = nullptr;
    Node* evens = nullptr;

    split(in, odds, evens);

    std::cout << "Test case 1 - Odds: ";
    printList(odds);

    std::cout << "Test case 1 - Evens: ";
    printList(evens);

    Node* emptyList = nullptr;
    Node* emptyOdds = nullptr;
    Node* emptyEvens = nullptr;

    split(emptyList, emptyOdds, emptyEvens);
    
    std::cout << "Test case 2 - Odds: ";
    printList(emptyOdds);

    std::cout << "Test case 2 - Evens: ";
    printList(emptyEvens);

    Node* oddList = new Node{1, nullptr};
    oddList->next = new Node{3, nullptr};
    oddList->next->next = new Node{5, nullptr};

    Node* oddOdds = nullptr;
    Node* oddEvens = nullptr;

    split(oddList, oddOdds, oddEvens);
    
    std::cout << "Test case 3 - Odds: ";
    printList(oddOdds);

    std::cout << "Test case 3 - Evens: ";
    printList(oddEvens);

    Node* evenList = new Node{2, nullptr};
    evenList->next = new Node{4, nullptr};
    evenList->next->next = new Node{6, nullptr};

    Node* evenOdds = nullptr;
    Node* evenEvens = nullptr;

    split(evenList, evenOdds, evenEvens);

    std::cout << "Test case 4 - Odds: ";
    printList(evenOdds);

    std::cout << "Test case 4 - Evens: ";
    printList(evenEvens);

    deleteList(odds);  // Properly delete the odds list
    deleteList(evens); // Properly delete the evens list
    deleteList(emptyOdds);  // Properly delete empty lists
    deleteList(emptyEvens);
    deleteList(oddOdds);
    deleteList(oddEvens);
    deleteList(evenOdds);
    deleteList(evenEvens);

    return 0;
}
