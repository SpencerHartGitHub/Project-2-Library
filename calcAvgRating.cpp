#include <iostream>
#include <string>
#include <fstream>
#include "Book.h"
#include "User.h"
#include "Library.h"
using namespace std;

/*
* Algorithm: create a function that return the average rating for a particular book
* 1. Create a function wihh 5 parameters
* 2. initialize everything
* 3. create a bool to decide what gets returned in some cases
* 4. return the average once you get all the ratings for the book
*/

string lowercase(string word)
{
    for(int i = 0; i < word.length(); i++)
    {
        
        if(word[i] >= 'A' && word[i] <= 'Z')
        {
            
            word[i] = word[i] + 32;
            
        }
    }
    return word;
}

double calcAverageRating(string bookTitle) // (User users[], Book books[], int currentStoredUsers, int currentStoredBooks)
{
    double counter = 0.0; // initialize everything
    
    double average = 0.0;
    
    double tempIndexBook = 0.0;
    
    double tempSum = 0.0;
    
    bool found = false; // set up a bool
    
    for(int i = 0; i < numBooks; i++)
    {
        if(lowercase(bookTitle) == lowercase(books[i].getTitle())) // find the title they want the ratings for 
        {
            found = true;
            tempIndexBook = i;
            break;
        }
    }
    
    if(!found) // false
    {
        return -3;
    }
    
    if(found && numUsers > 0) // true 
    {
        for(int i = 0; i < numUsers; i++)
        {
            if(users[i].getRatingAt(tempIndexBook) > 0)
            {
                tempSum = tempSum + users[i].getRatingAt(tempIndexBook); // put the ratings into the sum added up and add one to counter
                
                counter++;
            }
        }
        
        if(counter == 0)
        {
            return 0;
        }
        
        average = tempSum / counter; // gets average exluding 0's
        
        return average;
    }
    
    else
    {
        return -3;
    }
    
}
