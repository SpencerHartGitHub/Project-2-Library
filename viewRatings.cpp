#include <iostream>
#include <string>
#include <fstream>
#include "Book.h"
#include "User.h"
#include "Library.h"
using namespace std;


/*
* Algorithm: A function that prints all the books a user has provided ratings for if the rating is greater than or equal to the minimum rating given.
* 1. Check to see if there is a username in the system before proceeding
* 2. If not cout a msg
* 3. if there is make sure the user has rated books and if soo cout a msg
* 4. Then go rating to rating and see if its greater than the min and cout them
* 5. if not cout a msg
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


void viewRatings(string username , int minRating)
{
    bool userFound = false;
    int userIndex = 0;
    
    for(int i = 0; i < sizeUser; i++)
    {
        if(users[i].getUsername() == username) // check to see if the user is in system
        {
            userIndex = i;
            userFound = true;
        }
    }
    
    if(!userFound) // if user not found
    {
        cout << username << "does not exist." << endl;  
    }
    
    else
    {
        bool ratingFound = false;
        
        if(getCountReadBooks(username) != 0) // make sure the number of books read is not 0
        {
            cout << "Here are the books that " << username << " rated" << endl;
        }
        
        for(int i = 0; i < sizeUser; i++)
        {
            if(users[userIndex].getRatingAt(i) >= minRating) // find specific books with the rating being over the min
            {
                ratingFound = true;
                
                cout << "Title : " << books[userIndex].getTitle(i) << endl;
                cout << "Rating : " << users[userIndex].getRatingAt(i) << endl; // print them
                cout << "-----" << endl;
                
            }
        }
    
        if(!ratingFound) // if getcountbooks came back with 0 and no books found with min rating
        {
            cout << username << "has not rated any books yet." << endl;
        }
    
    }
    
}
