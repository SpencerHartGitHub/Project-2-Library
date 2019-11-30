#include<iostream>
#include<string>
#include<fstream>
#include "User.h"
#include "Book.h"
using namespace std;

#ifndef LIBRARY_H
#define LIBRARY_H

class Library
{
    
    private:
    //
    int sizeBook;
    
    int sizeUser;
    
    Book books[50];
    
    User users[100];
    
    int numBooks;
    
    int numUsers;
    //
    public:
    //
    Library();
    
    int getSizeBook();
    
    int getSizeUser();
    
    int getNumBooks();
    
    int getNumUsers();
    
    int readBooks(string); // DONE
    
    void printAllBooks(); //DONE
    
    void printBooksByAuthor(string authorName); // DONE
    
    int readRatings(string fileName); // DONE
    
    int getRating(string username , string bookTitle); // DONE
    
    int getCountReadBooks(string username); // DONE
    
    void viewRatings(string username , int minRating); // DONE
    
    double calcAvgRating(string bookTitle); // DONE
    
    double calcAvgRatingByAuthor(string authorName); // DONE
    
    int addUser(string username); // DONE
    
    int checkOutBook(string username , string bookTitle , int newRating);
    
    void getRecommendations(string username); // DONE
};


#endif

