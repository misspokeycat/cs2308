#include "Product.h"
#include "ProductInventory.h"
#include <iostream>

using namespace std;

//private:
Product *products;	//Our array of products
int size;	//Size of our array
int productCount = 0;	//Number of products in our array

void ProductInventory::resize(){
	//Creates new array to hold our products.
	Product *newProducts = new Product[size*2];
	//Copies over data from old array to new array.
	for (int i=0; i < size; i++){
		newProducts[i] = products[i];
	}
	//Set array to be new array.
	products = newProducts;
	//Sets new size.
	size *= 2;
}	

ProductInventory::ProductInventory(int newSize){
	//Initialize products and size.
	products = new Product[size];
	size = newSize;
}

bool ProductInventory::addProduct(Product p){
	//check for a duplicate
	bool isUnique = true;
	int i = 0;
	do {
		if (p.isEqual(products[i]){
			isUnique = false;
		}
		i++;
	} while (i < productCount);
	
	if (isUnique){
		//Resizes array if needed.
		if (productCount == size) resize();
		//Adds product to array.
		products[productCount] = p;
		//increases our product count
		productCount++;
	}
	return isUnique;
}

bool ProductInventory::removeProduct(string name, string locator){
	//Get index of our product (linear search cuz we dont care)
	int i = 0;
	do {
		if (products[i].getName() == name && products[i].getLocator() == locator){
			//we got it, now replace it
			products[i] = products[productCount];
			//and delete it
			productCount--;
			//and say that we did it
			return true;
		}
		i++;
	} while (i < productCount);
	//we couldn't find it -_-
	return false;
}

void ProductInventory::sortInventory(){
	
}

int ProductInventory::getTotalQuantity(){
	return -1;
}
