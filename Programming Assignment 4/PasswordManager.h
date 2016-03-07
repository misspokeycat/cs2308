// File Name: PasswordManager.h
// 
// Author: Luke D'Alfonso
// Date: 3/6/2016
// Assignment Number: 4
// CS 2308.251 Spring 2016
// Instructor: Jill Seaman 
// 
// Header file for password manager.

#ifndef PasswordManager_h
#define PasswordManager_h
#include <string>

using namespace std;
class PasswordManager{
    string password;
    private:
        string encrypt(string pass);
        bool verifyPassword(string pass);
    public:
        void setEncryptedPassword(string pass);
        string getEncryptedPassword();
        bool setNewPassword(string pass);
        bool validatePassword(string pass);
};
#endif
