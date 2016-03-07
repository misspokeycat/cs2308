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
    private:
        string password;
        string encrypt(string pass) const;
        bool verifyPassword(string pass) const;
    public:
        void setEncryptedPassword(string pass);
        string getEncryptedPassword() const;
        bool setNewPassword(string pass);
        bool validatePassword(string pass) const;
};
#endif
