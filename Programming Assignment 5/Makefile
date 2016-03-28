#makefile
ProductDriver: Product.o ProductInventory.o ProductDriver.cpp
    g++ ProductInventory.o Product.o ProductDriver.cpp -o ProductDriver

TC0Driver: Product.o ProductInventory.o ProductDriver.cpp
    g++ ProductInventory.o Product.o TC0Driver.cpp -o TC0Driver

Product: Product.cpp Product.h
    g++ Product.cpp
    
ProductInventory: Product.o ProductInventory.cpp ProductInventory.h
    g++ ProductInventory.cpp Product.o
    
clean:
    rm Product.o ProductInventory.o ProductDriver.o TC0Driver.o