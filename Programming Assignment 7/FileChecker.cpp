// File Name: FileChecker.cpp
//
// Author: Luke D'Alfonso
// Date: 4/24/2016
// Assignment Number: 7
// CS 2308 Spring 2016
// Instructor: Jill Seaman
//
// A checker to ensure parentheses and brackets are balanced.
//


#include <iostream>
#include "charstack.h"
#include <fstream>

using namespace std;

//Simple helper function for my checker
char revChar(char c){
    if (c == '{') return '}';
    if (c == '(') return ')';
    if (c == '[') return ']';
    return '!'; //Shouldn't ever happen
}

int main() {
    //Prompt filename.
    cout << "Enter filename to check: ";
    string filename;
    cin >> filename;

    //Load file, or return if we can't do that.
    // declare input file stream varaible and open file
    ifstream fin;

    //For some reason, the compiler hates it if our filename is a c++ string instead of a c string
    fin.open(filename.c_str());

    if (!fin){
        cout << "ERROR - File failed to open" << endl;
        fin.close();
        return 0;
    }

    CharStack charStack; //our character stack to fill with parenthesis and brackets

    //Start reading file, char by char, looking for ()[]{}
    char nextChar; //Stores current character in file
    while (fin >> nextChar){
        char checker; //We will use this to store character we are popping
        switch (nextChar){
            //All opening braces are handled the same way - push to stack.
            case '{':
            case '[':
            case '(':
                charStack.push(nextChar);
                break;
            case '}':
                //Validate stack is not empty.  Otherwise, unmatched char.
                if (charStack.isEmpty()){
                    cout << "ERROR: unmatched }" << endl;
                    fin.close();
                    return 1;
                }
                //Validate that stack has a '{'. Otherwise, we got unexpected char.
                checker = charStack.pop();
                if (checker != '{'){
                    cout << "ERROR: expected " << revChar(checker) << " but found }" << endl;
                    fin.close();
                    return 2;
                }
                break;
            case ']':
                //Validate stack is not empty.  Otherwise, unmatched char.
                if (charStack.isEmpty()){
                    cout << "ERROR: unmatched ]" << endl;
                    fin.close();
                    return 1;
                }
                //Validate that stack has a '['. Otherwise, we got unexpected char.
                checker = charStack.pop();
                if (checker != '['){
                    cout << "ERROR: expected " << revChar(checker) << " but found ]" << endl;
                    fin.close();
                    return 2;
                }
                break;

            case ')':
                //Validate stack is not empty.  Otherwise, unmatched char.
                if (charStack.isEmpty()){
                    cout << "ERROR: unmatched )" << endl;
                    fin.close();
                    return 1;
                }
                //Validate that stack has a '('. Otherwise, we got unexpected char.
                checker = charStack.pop();
                if (checker != '('){
                    cout << "ERROR: expected " << revChar(checker) << " but found )" << endl;
                    fin.close();
                    return 2;

                }
                break;
            default:break;
        }
    }
    //Finally, check for any missing symbols (if stack still has chars, then we are missing an ender)
    if (!charStack.isEmpty()) {
        switch (charStack.pop()) {
            case '{':
                cout << "ERROR: missing }" << endl;
                fin.close();
                return 3;
            case '(':
                cout << "ERROR: missing )" << endl;
                fin.close();
                return 3;
            case '[':
                cout << "ERROR: missing ]" << endl;
                fin.close();
                return 3;
            default:
                break;
        }
    }
    // closing files
    fin.close();
    return 0;
}
