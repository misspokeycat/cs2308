#makefile

password: PasswordManager.o PasswordDriver.o
	g++ PasswordManager.o PasswordDriver.o -o password

PasswordDriver.o: PasswordDriver.cpp PasswordManager.h
	g++ -c PasswordDriver.cpp

PasswordManager: PasswordManager.cpp PasswordManager.h
	g++ -c PasswordManager.cpp

clean:
	rm password PasswordManager.o PasswordDriver.o password.txt
