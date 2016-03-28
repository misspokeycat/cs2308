// File Name: TC0Driver.cpp
// 
// Author: Jill Seaman
// Date: 3/21/2016
// Assignment Number: 5
// CS 2308 Spring 2016
// Instructor: Jill Seaman
//
// A demo driver for ProductInventory.
// This is Test case 0.  Your code must compile with this driver, and
//   produce the expected output

#include<iostream>
#include<iomanip>
using namespace std;

#include "ProductInventory.h"

int main()
{
    ProductInventory pi(40);
    
    Product product1("box1", 2, 105.75, "Apple iPhone 3GS");
    Product product2("box2", 3, 172.50, "Samsung Captivate SGH-I897");

    bool result = pi.addProduct(product1);
    cout << "add result = " << result << endl;
    result = pi.addProduct(product2);
    cout << "add result = " << result << endl;
    
    pi.showInventory();
          
}

//Expected output:
// add result = 1
// add result = 1
// box1  2  $105.75  Apple iPhone 3GS
// box2  3  $172.50  Samsung Captivate SGH-I897
