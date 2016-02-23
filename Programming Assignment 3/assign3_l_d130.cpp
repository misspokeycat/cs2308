// File Name: assign3_l_d130.cpp
//
// Author: Luke D'Alfonso
// Date: 2/21/2016
// Assignment Number: 2
// CS 2308.251 Spring 2016
// Instructor: Jill Seaman
//
// Various pointer tasks.

//Imports
#include <iostream>
#include <iomanip>

using namespace std;


//***********************************************************
// median: returns median of an int array
//
// arr is array to get median from
// size is size of array
// returns: median value of array
//***********************************************************

double median(int *arr, int size){
    double ret = 0.0;  //return value
    //Determine if size is even (we will have to take the average then)
    if (size % 2 == 0){
        ret = (*(arr + (size / 2 - 1)) + *(arr + (size / 2)))/2.0;
    } else {
        ret = *(arr + (size / 2));
    }
    return ret;
}

//***********************************************************
// pizza: returns cost of pizza for a given number of people
//
// people is number of people to get pizza for
// pizzas is pointer for number of pizzas to buy
// slices is pointer for number of slices to buy
// returns: total cost of pizza
//***********************************************************
double pizza (int people, int *pizzas, int *slices) {
    int totalSlices = people*3;
    *pizzas = totalSlices/8;
    *slices = totalSlices%8;
    return *pizzas*11.95 + *slices*1.75;
}

//***********************************************************
// resize: doubles size of array, inserts -1 for ending half
//
// arr is array to increase size of
// size is size of array
// returns: pointer to int array twice the size of arr, end padded with -1s
//***********************************************************
int *resize(int arr[], int size){
    int *arrNew = new int[size*2];
    //copies arr values into new array
    for (int x=0; x < size; x++){
        *(arrNew + x) = arr[x];
    }
    //pads end with -1s
    for (int x=size; x<size*2; x++){
        *(arrNew + x) = -1;
    }
    return arrNew;
}


//***********************************************************
// shiftX: creates "shifted" array, start padded with -1s
//
// arr is array to shift
// size is size of arr
// val is amount of elements to add to front of array
// returns: pointer to array of size size + val, front padded with val -1s
//***********************************************************
int *shiftX(int arr[], int size, int val){
    //Creates a new array of size size + val
    int *arrNew = new int[size+val];

    //Populates start val elements of array with -1.
    for (int x=0; x < val; x++){
        *(arrNew + x) = -1;
    }

    //Fills end of array with values from input array
    for (int x=0; x < size; x++){
        *(arrNew + val + x) = arr[x];
    }
    return arrNew;
}

//***********************************************************
// duplicateArray: creates pointer to copy of array
//
// arr is array to copy
// size is size of arr
// returns: pointer to copy of array
//***********************************************************
int *duplicateArray (int *arr, int size) {
    int *newArray;
    if (size <= 0) //size must be positive
    return NULL; //NULL is 0, an invalid address
    newArray = new int [size]; //allocate new array
    for (int index = 0; index < size; index++)
        newArray[index] = arr[index]; //copy to new array
    return newArray;
}

//***********************************************************
// subArray: creates a partial array of original array
//
// array is array to copy
// size is size of arr
// returns: array of size start-length with elements array[start] through array[start+length]
//***********************************************************
int *subArray (int *array, int start, int length){
    int *result = duplicateArray(array + start, length);
    return result;
}

int main() {
    //median tests
    cout << "testing median:" << endl;
    cout << "test data: 1 2 3 4 5 6 7 8 9" << endl;
    int arr[] = {1,2,3,4,5,6,7,8,9};
    cout << "Expected median: 5" << endl;
    cout << "Actual median: " << median(arr, 9) << endl; //TODO: set values
    cout << "test data: 1 2 3 4 5 6 7 8" << endl;
    int arr2[] = {1,2,3,4,5,6,7,8};
    cout << "Expected median: 4.5" << endl;
    cout << "Actual median: " << median(arr2, 8) << endl;

    //pizza tests
    cout << "testing pizza for 25 people:" << endl;
    int PEOPLE = 25, p, s;
    double result = pizza(PEOPLE, &p, &s);
    cout << "Expected result: 112.80 p: 9 s: 3" << endl;
    cout << setprecision(2) << fixed; //so we can get 2 decimal places for our return value
    cout << "Actual results : " << result << " p: " << p  << " s: " << s << endl;

    //resize tests
    cout << "testing resize:" << endl;
    cout << "test data: 1 2 3 4 5 6 7 8 9 0" << endl;
    int arr3[] = {1,2,3,4,5,6,7,8,9,0};
    int *arrResized = resize(arr3, 10);
    cout << "Expected result: 1 2 3 4 5 6 7 8 9 0 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1" << endl;
    cout << "Actual result: ";
    for (int x = 0; x < 20; x++){
        cout << arrResized[x] << " ";
    }
    cout << endl;
    delete arrResized;

    //shiftX tests
    cout << "testing shiftX:" << endl;
    cout << "test data: 1 2 3 4 5 6 7 8 9 0" << endl;
    int arr4[] = {1,2,3,4,5,6,7,8,9,0};
    cout << "and 4" << endl;
    int *arrShifted = shiftX(arr4, 10, 4);
    cout << "Expected result: -1 -1 -1 -1 1 2 3 4 5 6 7 8 9 0" << endl;
    cout << "Actual result: ";
    for (int x = 0; x < 14; x++){
        cout << arrShifted[x] << " ";
    }
    cout << endl;
    delete arrShifted;

    //subArray tests
    cout << "testing subArray:" << endl;
    cout << "test data: 1 2 3 4 5 6 7 8 9 0" << endl;
    int arr5[] = {1,2,3,4,5,6,7,8,9,0};
    cout << "start: 5 length: 4" << endl;
    int *arrSub = subArray(arr5, 5, 4);
    cout << "Expected result: 6 7 8 9" << endl;
    cout << "Actual result: ";
    for (int x = 0; x < 4; x++){
        cout << arrSub[x] << " ";
    }
    delete arrSub;
}
