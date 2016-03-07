//PasswordManager Class:
#include "PasswordManager.h";
#include <string>

using namespace std;
    //The PasswordManager class should have just one member variable, which will store the
    //encrypted password (a string). Do not store the password unencrypted!
    //The PasswordManager class should have the following two internal member functions
    //(not accessible outside of the class):
    //encrypt: this takes a password (a string) and returns the encrypted form of the
    //password. Note: there is no decrypt function (there is no need to decrypt passwords).
    //We will use the following VERY simple encryption algorithm (a Caesar Cipher):
    //For every character in the input string, add 10 to the ascii value of the character.
    //The encrypted character’s ascii value must stay in the range of printable, nonwhitespace
    //characters: 33 to 126. This can be enforced using this formula:
    //ascii value of encrypted char =
    //((ascii value of ch - 33) + 10) % 94 + 33
    //1
    //Store all the resulting chars in a string to be returned as the result of the function (hint:
    //use the string.append function, or + or +=).
    string PasswordManager::encrypt(string pass){
        //Iterate through all characters in string, and perform encrypt on them
        for(int x=0; x<pass.length(); x++){
            pass[x] = ((pass[x] - 33) + 10) % 94 + 33;
        }
        //Return password.
        return pass;
    }
    //verifyPassword: this takes a string (a password) and returns true if it meets the
    //following criteria:
    //• it is at least 8 characters long
    //• it contains at least three out of the following four types of characters:
    //- Uppercase letters
    //- Lowercase letters
    //- Numbers
    //- Symbols
    //Otherwise it returns false.
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
    //The PasswordManager should have the following member functions that are accessible
    //outside of the class:
    //setEncryptedPassword: (a setter function) takes a string (an encrypted password)
    //and stores it in the member variable.
    void PasswordManager::setEncryptedPassword(string pass){
        password = pass;
        return;
    }
    //getEncryptedPassword: (a getter function) returns the value of the encrypted
    //password stored in the member variable.
    string PasswordManager::getEncryptedPassword(){
        return password;
    }
    //setNewPassword: takes a string (a proposed password). If it meets the criteria in
    //verifyPassword, it encrypts the password and stores it in the member variable and
    //returns true. Otherwise returns false.
    bool PasswordManager::setNewPassword(string pass){
        if (verifyPassword(pass)){
            setEncryptedPassword(encrypt(pass));
            return true;
        } else {
            return false;
        }
    }
    //validatePassword: takes a string (a password) and returns true if, once encrypted, it
    //matches the encrypted string stored in the the member variable. Otherwise, return false.
    bool PasswordManager::validatePassword(string pass){
        if (encrypt(pass) == password){
            return true;
        } else {
            return false;
        }
}
