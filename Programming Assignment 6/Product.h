// File Name: Product.h
//
// Author: Jill Seaman
// Date: 3/21/2016
// Assignment Number: 5
// CS 2308 Spring 2016
// Instructor: Jill Seaman
//
// Represents a product in the inventory of a small store
// (specification)

#include <string>
using namespace std;

class Product
{
  private:
    string productName;       // product description
    string locator;           // location of product in store
    int quantity;             // number of copies in inventory
    double price;             // selling price of the product
    
  public:
    Product();
    Product(string,int,double,string);
    
    string getLocator();
    int getQuantity();
    double getPrice();
    string getProductName();
    
    void setLocator(string);
    void setQuantity(int);
    void setPrice(double);
    void setProductName(string);
    
    bool isEqual(Product);
    bool greaterThan(Product);
};