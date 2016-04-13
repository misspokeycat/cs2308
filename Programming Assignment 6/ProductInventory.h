// File Name: ProductInventory.h
//
// Author: Jill Seaman
// Date: 11/2/2013
// Assignment Number: 6
// CS 2308 Spring 2016
// Instructor: Jill Seaman
//
// Represents the inventory of a small store (specification).
// Supports adding and removing products, displaying and sorting inventory,
// and computing total number of products in inventory.

#include "Product.h"

class ProductInventory
{
  private:
    struct ProductNode          // the Nodes of the linked list
    {
        Product data;           // data is a product
        ProductNode *next;      // points to next node in list
    };
    
    ProductNode *productList;  // the head pointer
    
  public:
    ProductInventory();
    ~ProductInventory();
    
    bool addProduct(Product);
    bool removeProduct(string,string);
    void showInventory();
    int getTotalQuantity();
    Product findMinimum();     // should be private, but public for testing
    void sortInventory();
    
    
};