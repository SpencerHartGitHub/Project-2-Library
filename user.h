
#include<iostream>
#include<string>
using namespace std;

#ifndef USER_H
#define USER_H

/* 
*Algorithm: Create a class User that has private data members and public members. This function serves to take a array of users and their ratings of a specific book from book.h/book.cpp
* 1. Create the class
* 2. Create the private and public members 
* 3. Make sure to include the #'s
*/

class User
{
    private:
    
    
    string username;
    
    int size; // the capacity of the ratings array (50). constant
    
    int ratings[50]; // number of elements should be size
    
    int numRatings; // number of books in the database
    
    
    public:
    
    
    User(); // default constructor
    
    User(string username, int ratings[], int numRatings); // parameterized constructor
    
    string getUsername(); // returns username as a string
    
    void setUsername(string username); // (void) Assigns username the value of the input string
    
    int getRatingAt(int index); // parameter: int index. returns the ratings stored at the specific index
    
    bool setRatingAt(int index, int value); // parameters: int index, int value. Sets the rating to value at the specific index
    
    int getNumRatings(); // returns numRatings as an int
    
    void setNumRatings(int value); // (void) assigns numRatings the value of the input int
    
    int getSize(); // returns size as an integer
    
};

#endif
