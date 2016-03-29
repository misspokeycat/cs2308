#ifndef ProductInventory_h
#define ProductInventory_h

#include <iostream>
#include "Product.h"

using namespace std;

class ProductInventory{
	private:
		Product *products;
		void resize();
		int size;
		int productCount;
		//stuff
	public:
		ProductInventory(int newSize);
		bool addProduct(Product p);
		bool removeProduct(string name, string locator);
		void sortInventory();
		int getTotalQuantity();
		//stuff
};
#endif
