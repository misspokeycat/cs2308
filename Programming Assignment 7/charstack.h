// Specification file for the CharStack class
// Replace with your header.

#include <string>
using namespace std;

class CharStack
{
private:
    string stackString;  //contains the stack of characters
    
public:
    // Constructor
    CharStack();
    
    // Stack operations
    void push(char);
    char pop();
    bool isFull() const;
    bool isEmpty() const;
}; 

