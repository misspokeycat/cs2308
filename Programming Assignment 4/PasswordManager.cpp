// File Name: PasswordManager.cpp
// 
// Author: Luke D'Alfonso
// Date: 3/6/2016
// Assignment Number: 4
// CS 2308.251 Spring 2016
// Instructor: Jill Seaman 
// 
// Implementation of a simple password manager.

#include "PasswordManager.h"
#include <string>

using namespace std;

//***********************************************************
// encrypt: performs a ROT10 "encryption" on pass
// returns: the encrypted password
// pass - the password to encrypt
//***********************************************************
string PasswordManager::encrypt(string pass){
    //Iterate through all characters in string, and perform encrypt on them
    for(int x=0; x<pass.length(); x++){
        pass[x] = ((pass[x] - 33) + 10) % 94 + 33;
    }
    //Return password.
    return pass;
}

//***********************************************************
// verifyPassword: checks to see if a password meets minimum complexity requirements
// a password must have at least 3 of the 4 - numbers, upper letters, lower letters, symbols
// returns true if complexity requirements mets, false otherwise
// pass - the password (unencrypted) to check
//***********************************************************
bool PasswordManager::verifyPassword(string pass){
    //Verify Length
    if (pass.length() < 8){
        return false;
    } else {
        int score = 0;
        //string.find_first_of finds the first index of a charater in a given string in another string.
        //checks for an uppercase letter
        if (pass.find_first_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ") != -1) score++;
        //lowercase
        if (pass.find_first_of("abcdefghijklmnopqrstuvwxyz") != -1) score++;
        //digit
        if (pass.find_first_of("0123456789") != -1) score++;
        //everthing else
        if (pass.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789") != -1) score++;
        //verify we have at least 3 of these things
        if (score >= 3){
            return true;
        } else {
            return false;
        }
    }
}

//***********************************************************
// setEncryptedPassword: setter for our password
// pass - the encrypted password to set as new password
//***********************************************************
void PasswordManager::setEncryptedPassword(string pass){
    password = pass;
    return;
}

//***********************************************************
// getEncryptedPassword: getter for our password
// returns: the encrypted password
//***********************************************************
string PasswordManager::getEncryptedPassword(){
    return password;
}

//***********************************************************
// setNewPassword: sets password if pass meets complexity requirements
// returns true if password meets complexity requirements (and was therefore set), false otherwise
// pass - unencrypted password to set as new password
//***********************************************************
bool PasswordManager::setNewPassword(string pass){
    if (verifyPassword(pass)){
        setEncryptedPassword(encrypt(pass));
        return true;
    } else {
        return false;
    }
}

//***********************************************************
// validatePassword: checks a password to see if, once encrypted,
// it matches the password stored in member var password
// returns: true if encrypted pass is same as stored pass, false otherwise
// pass - the password (unencrypted) to test against the stored password
//***********************************************************
bool PasswordManager::validatePassword(string pass){
    if (encrypt(pass) == password){
        return true;
    } else {
        return false;
    }
}