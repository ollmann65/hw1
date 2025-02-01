#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"
using namespace std;
// Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{


    ULListStr list;
    
    list.push_back("A");//to the back
    list.push_back("B");
    list.push_front("C"); // front

    cout << "List after push_back and push_front:" <<endl;
    cout << "Front: " << list.front() <<endl;  // show front
    cout << "Back: " << list.back() <<endl;   //show back
    cout << "Size: " << list.size() <<endl;   //shwo size

    cout << "First element: " << list.get(0) <<endl; 
    cout << "Second element: " << list.get(1) <<endl; 
    cout << "Third element: " << list.get(2) <<endl; 

    list.pop_back();
    cout << "List after pop_back:" <<endl;
    cout << "Back: " << list.back() <<endl; 
    cout << "Size: " << list.size() <<endl; 

    list.pop_front();
    cout << "List after pop_front:" <<endl;
    cout << "Front: " << list.front() <<endl; // new back
    cout << "Size: " << list.size() <<endl; // and new size

    list.set(0, "D");
    cout << "List after set:" <<endl;
    cout << "Front: " << list.front() <<endl; 

    list.clear(); // clear the whole list
    cout << "List after clear:" <<endl;
    cout << "Is list empty? " << (list.empty() ? "Yes" : "No") <<endl; 

    return 0;
}
