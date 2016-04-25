#makefile
FileChecker : charstack.h charstack.cpp FileChecker.cpp
	g++ FileChecker.cpp charstack.cpp charstack.h -o FileChecker
StackTest : charstack.h charstack.cpp testdriver.cpp
	g++ testdriver.cpp charstack.o -o TestDriver
charstack : charstack.h charstack.cpp
	g++ charstack.h charstack.cpp -o charstack.o
clean :
	rm charstack.o TestDriver FileChecker
