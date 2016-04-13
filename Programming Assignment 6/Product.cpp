// File Name: Product.cpp
//
// Author: Jill Seaman
// Date: 3/21/2016
// Assignment Number: 5
// CS 2308 Spring 2016
// Instructor: Jill Seaman
//
// Represents a Product in the inventory of a small store
// (implementation)

#include "Product.h"

//***********************************************************
// Product: constructs a Product with default values.
//***********************************************************

Product::Product()
{
    locator = "";
    quantity = 0;
    price = 0;
    productName = "";
}

//***********************************************************
// Product: constructs a Product from a locator, quantity, price,
//          and ProductName.
//***********************************************************

Product::Product(string newLocator, int newQuantity, double newPrice,
                 string newProductName)
{
    locator = newLocator;
    quantity = newQuantity;
    price = newPrice;
    productName = newProductName;
}

// setLocator: mutator function to set the locator
void Product::setLocator(string newLocator)
{
    locator = newLocator;
}
// setQuantity: mutator function to set the quantity
void Product::setQuantity(int newQuantity)
{
    quantity = newQuantity;
}
// setPrice: mutator function to set the price
void Product::setPrice(double newPrice)
{
    price = newPrice;
}
// setProductName: mutator function to set the productName
void Product::setProductName(string newProductName)
{
    productName = newProductName;
}

// getLocator: accessor function to return the locator
string Product::getLocator()
{
    return locator;
}
// getQuantity: accessor function to return the quantity
int Product::getQuantity()
{
    return quantity;
}
// getPrice: accessor function to return the price
double Product::getPrice()
{
    return price;
}
// getProductName: accessor function to return the productName
string Product::getProductName()
{
    return productName;
}

//***********************************************************
// isEqual: compares this Product to another
//   Products are equal if locators and productNames are equal
// other: the Product being compared to this one
// returns true if they are equal, otherwise false.
//***********************************************************
bool Product::isEqual(Product other)
{
    if (locator != other.locator)
        return false;
    if (productName != other.productName)
        return false;
    return true;
}

//*********************************************************************
// greaterThan: compares this Product to another
//   compares productNames, then locators if productNames are equal
// other: the Product being compared to this one
// returns true if this one is greater than the other, otherwise false.
//*********************************************************************
bool Product::greaterThan (Product other)
{
    if (productName == other.productName)
        return (locator > other.locator);
    return productName > other.productName;
}

