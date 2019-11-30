#include <iostream>
#include <string>
#include <fstream>
#include "Book.h"
#include "User.h"
#include "Library.h"
using namespace std;

/*
* Algorithm: create a function that when given the author find the average rating of the books they have written
* 1. find the author
* 2. get the ratings for each book and add them then divideby the amounnt to get average.
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

double calcAverageRating(string authorName)
{
    double counter = 0.0; // initialize everything
    
    double average = 0.0;
    
    double tempIndexAuthor = 0.0;
    
    double tempSum = 0.0;
    
    bool found = false; // set up a bool
    
    for(int i = 0; i < numBooks; i++) // everyhting is in for loop to get all the books by the author
    {
        if(lowercase(authorName) == lowercase(books[i].getAuthor())) // find the title they want the ratings for 
        {
            found = true;
            tempIndexAuthor = i;
        
        
            if(found && numUsers > 0) // true 
            {
                for(int i = 0; i < numUsers; i++)
                {
                    if(users[i].getRatingAt(tempIndexAuthor) > 0)
                    {
                        tempSum = tempSum + users[i].getRatingAt(tempIndexAuthor); // put the ratings into the sum added up and add one to counter
                        
                        counter++;
                    }
                }
            }
            
            if(counter == 0)
            {
                return 0;
            }
                
            average = tempSum / counter; // gets average exluding 0's
            
        }
    }
    
    if(!found) // false
    {
        return -3;
    }
    
    return average;
}

