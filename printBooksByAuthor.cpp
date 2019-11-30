#include <iostream>
#include <string>
#include <fstream>
#include "Book.h"
#include "Library.h"
using namespace std;

/*
* Algorithm: Create a function with four parameters that takes the books give and sees if there are multiple books to one author
* 1. Check if the books entered is a negative or 0 and print the statement seen below
* 2. Else create a bool and make it found and set it to false initially
* 3. Now create a for loop that goes through the number of books and see if the authors name mathches the authors at that current index
* 4. If they match change the found to now true
* 5. The next statement check if the found is true and if so print the satement below
* 6. Then create the same for loop as above to go through and print out the ones the match 
* 7. Create a else (found was false) and print there are no books by that author
*/

void printBooksByAuthor(Book books[], int numBooks, string authorName)
{
    if (numBooks <= 0) // if the # of books given is 0 or a negative
    {
        
        cout << "No books are stored" << endl;
        
    }
    
    else // books are given
    {
        bool found = false; // initially set to false
        
        for(int i = 0; i < numBooks; i++) // go through the number of books
        {
            
            if(authorName == books[i].getAuthor()) // if they match 
            {
                
                found = true; // change found to true ^
                
            }  
            
        }
        
        if(found) // if true from above
        {
            
            cout << "Here is a list of books by " << authorName << endl; // output this
            
            for(int i = 0; i < numBooks; i++) // again do the same for loop but...
            {
                
                if(authorName == books[i].getAuthor())
                {
                    
                    cout << books[i].getTitle() << endl; // output the books now
                    
                }    
            }
        }
        
        else // not true (false)
        {
            
            cout << "There are no books by " << authorName << endl; 
            
        }
    }
}

