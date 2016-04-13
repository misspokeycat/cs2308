// File Name: ProductInventory.cpp
//
// Author: Luke D'Alfonso
// Date: 4/13/2016
// Assignment Number: 6
// CS 2308 Spring 2016
// Instructor: Jill Seaman
//
// Represents the inventory of a small store (specification).
// Supports adding and removing products, displaying and sorting inventory,
// and computing total number of products in inventory.

#include "ProductInventory.h"
#include <iostream>
using namespace std;

//**************************
//ProductInventory
//The constructor.  Sets productList to null.
//**************************
ProductInventory::ProductInventory(){
	productList = NULL;
}

//**************************
//~ProductInventory
//The destructor.  Deletes all nodes in the list.
//**************************
ProductInventory::~ProductInventory(){
	ProductNode *p = productList;
	if (p){
        while (p -> next){
            ProductNode *temp = p -> next;
            delete p;
            p = temp;
        }
	}
}

//**************************
//addProduct
//
//Adds a product to the end of the list.
//Returns: true if the add succeded, false if the product already exists in the list
//**************************
bool ProductInventory::addProduct(Product p){
    //Check to see if the product already exists in the list.
    if (productList != NULL){
        ProductNode *last = productList;
        while (last){
            if (last -> data.isEqual(p)){
                return false;
            }
            last = last -> next;
        }
    }
	//Create the productNode
    ProductNode *newProduct = new ProductNode;
    newProduct -> data = p;
    newProduct -> next = NULL;
    //Get the last node in the list
	ProductNode *last = productList;
	if (productList != NULL){
		while (last -> next){
			last = last -> next;
		}
        //Append the node to the list
        last -> next = newProduct;
	} else {
	    //Or set it to the start of the list
        productList = newProduct;
	}
	return true;
}

//**************************
//removeProduct
//
//Removes a product from the list.
//Returns: true if the node to delete was found & deleted, false otherwise
//**************************
bool ProductInventory::removeProduct(string name, string locator){
	//Traverse the list until we find a match, or we hit the end.
	ProductNode *current = productList;
	ProductNode *prev = NULL;
	do{
		if (current-> data.getProductName() == name && current -> data.getLocator() == locator){
            break;  //Match found, break
		}
		//Increase current and previous values
		prev = current;
		current = current -> next;
	} while (current != NULL);
	if (current == NULL){ //couldn't find it
		return false;
	} else {
		if (prev != NULL){//if it is, we are at the start of the list
            prev -> next = current -> next; //set the previous node's link to the node to be deleted's link
            delete current; //delete the target node
		} else {
		    productList = current -> next; //set the start of the list to the second node in the list
		    delete current;
		}
		return true;
	}
}

//**************************
//showInventory
//
//Displays all the products in the list
//**************************
void ProductInventory::showInventory(){
	ProductNode *p = productList; //Holds our current item in the list.
	while (p != NULL){
		//Prints out the current product, followed by a newline.
		//Locator, Qty, Price, Name
		cout << p -> data.getLocator() << "\t" <<
			p -> data.getQuantity() << "\t" <<
			p -> data.getPrice() << "\t" <<
			p -> data.getProductName() << "\t" << endl;
		//Move the pointer to the next object.
		p = p -> next;
	}
}

//****************************
//getTotalQuantity
//
//Gets the sum of the quantities of all the products in the list
//Returns the sum.
//****************************
int ProductInventory::getTotalQuantity(){
	ProductNode *p = productList; //Holds our current item in the list.
	int totalQty = 0; //Holds the total number of items
	while (p) {
		totalQty += p -> data.getQuantity();
		p = p -> next;
	}
	return totalQty;
}

//****************************
//findMinimum
//
//Gets the smallest product in the list.
//Returns: a product with the data of the smallest element in the list
//****************************
Product ProductInventory::findMinimum(){
	ProductNode *p = productList; //Holds our current item in the list.
	Product *least = &(p -> data); //Holds pointer to the least item in the list.
	while (p){
		if (!(p -> data.greaterThan(*least))){
			least = &(p -> data);
		}
		p = p -> next;
	}
	return *least;
}

//****************************
//sortInventory
//
//Sorts the inventory, descending.
//This was really, really hard to write.
//****************************
void ProductInventory::sortInventory(){
	ProductNode *tempList; //A temporary list to become the new list
	tempList = NULL;
	while (productList != NULL){ //Keep looping till we delete all nodes from original list
		Product m = findMinimum(); //Get the minimum value of the current list
		ProductNode *p = new ProductNode;
		p -> data = m;
		p -> next = NULL;
		ProductNode *last = tempList; //An element we are using to iterate over to the last list
        if (tempList != NULL){ //If tempList is null, we are inserting the first element in the list
            while (last -> next){
                last = last -> next;
            }
            //Append the node to the list
            last -> next = p;
        } else {  //Otherwise, set the first of the list to temp.
            tempList = p;
        }
        removeProduct(m.getProductName(), m.getLocator()); //Finally, delete the product from the list.
	}
	productList = tempList; //Once all items are deleted, set the old list to equal the new (sorted) list.
}
