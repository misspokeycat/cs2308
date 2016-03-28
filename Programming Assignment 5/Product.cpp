#include <string>
#include "Product.h"

using namespace std;
//Product: For each product, you should store the following info:
//product name (i.e. “Apple iPhone 3GS 8GB”, may contain spaces in it, not unique)
string name;
//locator (string with no spaces, used to physically locate product, not unique)
string locator;
//quantity (how many of this product in stock, greater than or equal to 0)
int quantity;
//price (in dollars and cents, greater than 0)
float price;

//You should implement the following operations for a Product:
//• You should implement two constructors: one that takes no arguments (quantity
//and price are 0, product name and locator are empty strings)
Product::Product(){
    
}

//and one that accepts
//a value for each of the four member variables.
Product::Product(string pname, string plocator, int qty, float pr){
    name = pname;
    locator = plocator;
    quantity = qty;
    price = pr;  
}
//• set and get all instance variables (make the instance variables private).
string Product::getName(){
    return name;
}

void Product::setName(string newval){
    name = newval;
}

string Product::getLocator(){
    return locator;
}

void Product::setLocator(string newval){
    locator = newval
}

int Product::getQuantity(){
    return quantity;
}

void Product::setQuantity(int newval){
    quantity = newval;
}

float Product::getPrice(){
    return price;
}

void Product::setPrice(float newval){
    price = newval;
}

//• bool isEqual(Product): this product is equal to another if they have the same
//product name and locator values.
bool Product::isEqual(Product pr){
    return((pr.getName() == name) && (pr.getLocator() == locator));
}

//• bool greaterThan(Product): this product is greaterThan another if its product
//name is greater than the others, OR if they have the same product names, if this
//product’s locator is greater than the other’s locator.
bool Product::greaterThan(Product pr){
    if (name == pr.getName){
        return (locator > pr.getLocator());
    } else { 
        return (name > pr.getName());
    }
}