#include <iostream>
#include <string>
#include <fstream>
#include "Book.h"
#include "User.h"
#include "Library.h"
using namespace std;

/*
* Algorithm: A functions that will update the current rating for a book with a new one
* 1. set parimeters 
* 2. find and store the username of the user that you want to replace the rating for
* 3. Now find a store the book titles index 
* 4. now replace the rating witht the new one
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

int checkOutBook(string username , string bookTitle , int newRating)
{
    int userIndex;
    int bookIndex;
    
    bool found = false;
    
    if(newRating < 0 || newRating > 5)
    {
        return -4;
    }
    
    for(int i = 0; i < numUsers; i++)
    {
        if(lowercase(username) == lowercase(users[i].getUsername())) // serch to see if the given username (in all lowercase) matches any of the users names in the array of them
        {
            found = true; // if so change the bool to true 
            userIndex = i; // store where we found the match into the user index for later
            break;
        }
    }
    
    if(!found) // remains false
    {
        return -3;
    }
    
    if(found) // if turned true 
    {
        for(int i = 0; i < numBooks; i++)
        {
            if( lowercase(bookTitle) == lowercase(books[i].getTitle()) ) // do the same as above but for book titles this time 
            {
                found = false; // now if you find it change the bool back to false
                bookIndex = i; // store the index where you found the book into bookindex
                break;
            }
        }
    }
    
    if(found == true) // if no books was found
    {
        return -3;
    }
    
    if(!found)
    {
        users[userIndex].setRatingAt(bookIndex, newRating); // at those specific indexs replace the rating with the new one
        
        return -1;
    }
}
