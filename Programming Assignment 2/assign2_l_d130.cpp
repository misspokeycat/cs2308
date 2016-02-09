// File Name: assign2_l_d130.cpp
//
// Author: Luke D'Alfonso
// Date: 2/8/2016
// Assignment Number: 2
// CS 2308.251 Spring 2016
// Instructor: Jill Seaman
//
// Simple inventory management app.

//Imports
#include <iostream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

//Print the menu.
void printMenu () {
cout << "Manage Inventory Menu" << endl;
cout << endl;
cout << "1. Add product" << endl;
cout << "2. Remove product" << endl;
cout << "3. Adjust quantity of a product" << endl;
cout << "4. Display a product" << endl;
cout << "5. Display inventory sorted by product name" << endl;
cout << "6. Quit the Program" << endl;
cout << endl;
cout << "Enter your choice: ";
}

//Representation of a product.
struct product {
    string name = "NO NAME";
    string locationID = "000000";
    int qty = 0;
    float price = 0;
};

//Simple bubble sort for inventory.
void sortProductsByName (product inv[], int size){
    for (int x=1; x < size; x++){
        int pos = x;
        while (pos != 0 && inv[pos].name < inv[pos-1].name){
            swap(inv[pos], inv[pos-1]);
            pos--;
        }
    }
}

//Gets the array index of a product by name.
int getProdIndex (product inv[], int size, string target){
    //Binary search algorithm.
    int first = 0, last = size - 1, mid, value = -1;
    while (value == -1 && first <= last){
        mid = (first + last) / 2;
        if(inv[mid].name == target){
            value = mid;
        } else if (inv[mid].name > target){
            last = mid - 1;
        } else {
            first = mid + 1;
        }
    }
    return value;
}

//Add product.
void addProduct(product inv[], int &products){
    //Input data.
    product newProd;
    cout << "Enter the new product name:" << endl;
    cin >> ws;
    getline(cin, newProd.name);
    cout << "Enter the locator (no spaces):" << endl;
    cin >> newProd.locationID;
    cout << "Enter the quantity (0 or more):" << endl;
    cin >> newProd.qty;
    cout << "Enter the price (greater than 0):" << endl;
    cin >> newProd.price;

    //Add product to the array.
    inv[products] = newProd;

    //Increment total number of products.
    products++;

    //Sort inventory.
    sortProductsByName(inv, products);
    return;
}

//Remove product.
void removeProduct(product inv[], int &products){
    //Input search term.
    string src;
    cout << "Enter product name:" << endl;
    cin >> ws;
    getline(cin, src);

    //Search for our product, and get the index.
    int index = getProdIndex(inv, products, src);

    //Return if we can't find a product.
    if (index == -1){
        cout << "Product not found!" << endl;
        return;
    }

    //Shift all other values to the front.
    for (int x = index; x < products; x++){
        swap(inv[x], inv[x+1]);
    }

    //Decrease product count.
    products--;
}

//Adjust quantity of a product.
void adjustQuantity(product inv[], int products) {
    //Input search term.
    string src;
    cout << "Enter product name:" << endl;
    cin >> ws;
    getline(cin, src);

    //Search for our product, and get the index.
    int index = getProdIndex(inv, products, src);

    //Return if we can't find a product.
    if (index == -1){
        cout << "Product not found!" << endl;
        return;
    }

    cout << "Enter new quantity:" << endl;
    cin >> inv[index].qty;
}

//Display a product
void displayProduct(product inv[], int products){
    //Input search term.
    string src;
    cout << "Enter product name:" << endl;
    cin >> ws;
    getline(cin, src);

    //Search for our product, and get the index.
    int index = getProdIndex(inv, products, src);

    //Return if we can't find a product.
    if (index == -1){
        cout << "Product not found!" << endl;
        return;
    }

    //Return product data at that index.
    cout << inv[index].locationID << "\t" << inv[index].qty << "\t" << inv[index].price << "\t" << inv[index].name << endl << endl;
}

//Display sorted inventory.
void displayInventory(product inv[], int products){
    for (int x = 0; x < products; x++){
        cout << inv[x].locationID << "\t" << inv[x].qty << "\t" << inv[x].price << "\t" << inv[x].name << endl;
    }
    cout << endl;
}

//Main function
int main(){
    cout << setprecision(2) << fixed;
    product inventory[100] = {};
    int products = 0;
    int choice = 0;
    while (choice != 6){
        printMenu();
        cin >> choice;
        switch (choice){
        case 1:
            addProduct(inventory, products);
            break;
        case 2:
            removeProduct(inventory, products);
            break;
        case 3:
            adjustQuantity(inventory, products);
            break;
        case 4:
            displayProduct(inventory, products);
            break;
        case 5:
            displayInventory(inventory, products);
            break;
        case 6:
            cout << "Exiting the program.";
            break;
        default:
            cout << "Invalid choice." << endl << endl;
            break;
        }
    }
}
