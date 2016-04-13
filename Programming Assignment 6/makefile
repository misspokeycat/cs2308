#makefile

productTest: ProductDriver.o ProductInventory.o Product.o
	g++ -g ProductDriver.o ProductInventory.o Product.o -o productTest

tc0: ProductDriver.o ProductInventory.o Product.o
	g++ -c -g TC0Driver.cpp ProductInventory.o Product.o -o TC0
ProductDriver.o: ProductDriver.cpp ProductInventory.h Product.h
	g++ -c ProductDriver.cpp

ProductInventory.o: ProductInventory.cpp ProductInventory.h Product.h
	g++ -c ProductInventory.cpp

Product.o: Product.cpp Product.h
	g++ -c Product.cpp

clean:
	rm *.o
	rm productTest
