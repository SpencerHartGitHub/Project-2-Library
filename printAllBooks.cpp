#include <iostream>
#include <string>
#include <fstream>
#include "Book.h"
#include "Library.h"
using namespace std;

/*
* Algorithm: Create a function that take three parameters to print if there are books sotred or not and list the books and who it is written by
* 1. Create a if statement that states if the books value is less than or equal to zero print the statement seen
* 2. Else (there is books (positive)) print the statement seen
* 3. Create a for loop that goes through the number of books given and print them by titles and who they are by
*/

void printAllBooks() //(Book books[], int numBooks)
{
    if (numBooks <= 0) // if books given is 0 or a negative 
    {
        cout << "No books are stored" << endl;
    }
    
    else
    {
        cout << "Here is a list of books" << endl;
        
        for(int i = 0; i < numBooks; i++) // go through the # of books given 
        {
            cout << books[i].getTitle() << " by " << books[i].getAuthor() << endl; // output titles first and then the authors
        }
    }
}
