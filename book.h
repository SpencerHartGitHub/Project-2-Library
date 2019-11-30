#include<iostream>
#include<string>

#ifndef BOOK_H
#define BOOK_H

using namespace std;

/* 
* Algorithm: Ctreate a class and initialize the private and public members to use in other files 
* 1. Create the class
* 2. Create the private and public members 
* 3. Make sure to include the #'s
*/

class Book // create the class Book
{
    private: // what we want to get out of this 
    
    string title;
    
    string author;
    
    public: // 
    
    Book(); // constructor
    
    Book(string title, string author); // parameterized constructor
    
    string getTitle(); // initializes the get 
    
    void setTitle(string title); // initializes the set of the title 
    
    string getAuthor(); // initializes the get 
    
    void setAuthor(string author); // initializes the set of the authors name
};

#endif
