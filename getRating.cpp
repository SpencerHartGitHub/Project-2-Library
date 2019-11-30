
#include <iostream>
#include <string>
#include <fstream>
#include "Book.h"
#include "User.h"
#include "Library.h"
using namespace std;

/*
* Algorithm: Write a function that when given a user name and book title we want to return the rating the user gave that specific book.
* 1. Apply the split and lowercase functions for later use
* 2. create a function with 6 parameters 
* 3. initialize everything that needs it
* 4. Create a bool to decide the return at the end.
*/

int split(string textToBeSplit, char delimiter, string words[], int size)
{
    string storage = ""; // the temporary storage to hold the strings before delimiter hits
    int j = 0;
    
    for(int i = 0; i < textToBeSplit.length(); i++) // goes through length of the given string
    {
    
        if(textToBeSplit[i] != delimiter) // if the index of the given string doesnt equal the delimiter then we want to,
        {
            storage += textToBeSplit[i]; // put that index into storage with the intial storage then repeat
        }
        
            else // does equal delimiter 
            {
                if (storage != "") 
                {
                    words[j] = storage; // moves storage to the index of j to later print
                    storage = ""; // reset storage to nothing
                    j++; // make j add 1 to create new space in word
                }
            }
    }
    
    if (storage != "") // edge case 
    {
        words[j] = storage; // put the last thing in storage into an index of words
        j++; // for output to screen to eqaul right amount 
    }
    
    if(j > size) // if the string is bigger than the size to hold it return 1 and the owrds it CAN output
    {
        return -1;
    }
    
    return j;
}

string lowercase(string word) // to convert capitals to lowercase for the whole word
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

int getRating(string username , string bookTitle , User users[] , Book books[] , int currentStoredUsers , int currentStoredBooks)
{
    lowercase(username);
    
    int userIndex; // initialize both these indexs
    
    int bookIndex;
    
    bool found = false; // set a bool to false initially 
    
    for(int i = 0; i < currentStoredUsers; i++)
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
        for(int i = 0; i < currentStoredBooks; i++)
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
    
    if(!found)//  stayed false
    {
      return users[userIndex].getRatingAt(bookIndex); // returns the score by using the index from the users array and the book array
    }
    
}
