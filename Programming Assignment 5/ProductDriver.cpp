// File Name: ProductDriver.cpp
// 
// Author: Jill Seaman
// Date: 3/21/2016
// Assignment Number: 5
// CS 2308 Spring 2016
// Instructor: Jill Seaman
//
// A demo driver for ProductInventory.
//
//   You need to do more complete testing than this.

#include<iostream>
#include<iomanip>
using namespace std;

#include "ProductInventory.h"

int main()
{
    //testing Product
    Product product0;
    product0.setLocator("box1");
    product0.setQuantity(2);
    product0.setPrice(111.99);
    product0.setProductName("Apple iPod Touch 4th Generation 8GB");
    
    cout << setw(6) << product0.getLocator() << " " << product0.getQuantity()
         << " $" << product0.getPrice()
         << " " << product0.getProductName() << endl;

    //Note that it does not test  .isEqual or .greaterThan [HINT]
    //See the TimeListDemo for a good example

    //testing ProductInventory
    ProductInventory pi(40);
    
    Product product1("box1", 2, 105.75, "Apple iPhone 3GS");
    Product product2("box1", 3, 172.50, "Samsung Captivate SGH-I897");
    Product product3("box3", 1, 215.35, "Blackberry RIM Bold 9930");
    Product product4("box2", 1, 215.35, "Blackberry RIM Bold 9930");
    Product product5("box2", 2, 322.50, "Apple iPad 2 16GB WiFi");

    bool result = pi.addProduct(product1);
    cout << "add result = " << result << endl;
    
    pi.showInventory();
          
    result = pi.addProduct(product2);
    cout << "add result = " << result << endl;
    
    pi.showInventory();
       
    result = pi.addProduct(product3);
    cout << "add result = " << result << endl;
       
    result = pi.addProduct(product4);
    cout << "add result = " << result << endl;
       
    result = pi.addProduct(product5);
    cout << "add result = " << result << endl;
    
    pi.sortInventory();

    pi.showInventory();
    
    bool delResult;
    delResult = pi.removeProduct(product2.getProductName(),
                                 product2.getLocator());
    cout << "delete result = " << delResult << endl;
  
    delResult = pi.removeProduct(product3.getProductName(),
                                 product3.getLocator());
    cout << "delete result = " << delResult << endl;

    pi.showInventory();
    cout << "total quantity (should be 5) = " << pi.getTotalQuantity() << endl;
    
    result = pi.addProduct(product5);
    cout << "add result = " << result << endl;
    
    pi.showInventory();
    
    //Note that it does not test resize!
    
}