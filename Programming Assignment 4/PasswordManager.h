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
