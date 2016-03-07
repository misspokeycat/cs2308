#include <iostream>
#include <fstream>
#include "PasswordManager.h"

using namespace std;

int main(){
    PasswordManager pm;  //An instance of PasswordManager.
    char choice = 'A';  //The choice we will use for the loop.
    string pass;
    while (choice != 'C'){
        cout << "Password Utilities:" << endl;
        cout << "A. Change Password" << endl;
        cout << "B. Validate Password" << endl;
        cout << "C. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice){
            case 'A':
            case 'a':
                cout << "Enter new pasword: ";
                cin >> pass;
                if (pm.setNewPassword(pass)){
                    cout << "Password set successfully." << endl;
                } else {
                    cout << "Password set failed: Complexity not met." << endl;
                }
                break;
            case 'B':
            case 'b':
                cout << "Enter password to check: ";
                cin >> pass;
                if (pm.validatePassword(pass)){
                    cout << "VALID" << endl;
                } else {
                    cout << "NOT VALID" << endl;
                }
                break;
            case 'C':
            case 'c':
                //Save password to disk and exit.
                ofstream fout;
                fout.open("password.txt");
                fout << pm.getEncryptedPassword();
                break;
        }
    }
}
