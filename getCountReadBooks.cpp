#include <iostream>
#include <string>
#include <fstream>
#include "Book.h"
#include "User.h"
#include "Library.h"
using namespace std;


// string lowercase(string word)
// {
//     for(int i = 0; i < word.length(); i++)
//     {
        
//         if(word[i] >= 'A' && word[i] <= 'Z')
//         {
            
//             word[i] = word[i] + 32;
            
//         }
//     }
//     return word;
// }


/*
* Algorithm: Write a function that counts how many times a book has been rated by a user
* 1. Apply the lowercase functions for later use
* 2. create a function with 4 parameters 
* 3. initialize everything that needs it
* 4. Create a bool to decide the return at the end.
*/


int getCountReadBooks(string username, User users[], int currentStoredUsers, int currentStoredBooks)
{
    lowercase(username);
    
    int userIndex; // initialized
    
    int numberOfBooks = 0; // set to 0 for count
    
    bool found = false; // set bool
    
    for(int i = 0; i < currentStoredUsers; i++)
    {
        if(lowercase(username) == lowercase(users[i].getUsername())) // check to find matches for username
        {
            found = true; // if there is then change bool to true
            userIndex = i; // store found index in user index
            break;
    
        }
    }
    
    if(!found) // false
    {
        return -3;
    }
    
    if(found && currentStoredBooks > 0) // true 
    {
        for(int i = 0; i < currentStoredBooks; i++)
        {
            if(users[userIndex].getRatingAt(i) != 0) // if the user index and get rating at that i index do not equal 0 then add 1 to num books
            {
                numberOfBooks++;
            }
        }
        
        return numberOfBooks;
    }
    
    else 
    {
        return -3;
    }
    
}
