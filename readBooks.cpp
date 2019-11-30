#include <iostream>
#include <string>
#include <fstream>
#include "Book.h"
#include "Library.h"
using namespace std;

/*
* Algorithm: Create a function that uses split to septerate given titles and authors in a txt file and stores them into seperate arrays and returns the number of books stored.
* 1. Initialize the split function to use in the future
* 2. Create a int function with all the parameters
* 3. Create a string for you lines * 5. Set up ifstream myFile
* 4. Open the fileName
* 5. Check to see if the current books stored is eqaul to the capacity and if it is return -2
* 6. Check to see if the file even opens
* 7. If it opens create a while loop that goes through each line (storage) until there isnt anything left
* 8. Now create a if statement that states if their is stuff in the lines do whats said below
* 9. Create a temp array that holds 2
* 10. Call the split function to catch and seperate at commas
* 11. Now store what is in the temp array index 0 into the authors index books stored (setAuthor)
* 12. Store what is in the temp array index 1 into the index index books stored (setTitle)
* 13. Then up the books stored counter
* 14. Now check to see if the books stored is greater than or equal to the capcity and if so then break and output up to that point
* 15. Close the file now
* 16. Return the final amount of books stored
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

int readBooks(string fileName)  //Book books[], int booksStored, int capacity)
{
    string storage;
    
    ifstream myFile;
    
    myFile.open(fileName);
    
    if (numBooks == sizeBook) 
    {
        return -2;
    }
    
    else if (!myFile.is_open())
    {
        return -1;
    }
    
    
    else 
    {
        while(getline(myFile, storage)) // goes through the file until its over essentially
        {
            if (storage.length() != 0) // if there is something in the storage
            {
                string tempArray[2]; // make a string that stores the arrays of size 2
                
                split(storage, ',', tempArray, 2); // let the split function come in and take out the commas
                
                // authors[booksStored] = tempArray[0]; // assign the temp at index 0 to authors books stored
                
                books[numBooks].setAuthor(tempArray[0]); // books[booksStored].setAuthor(tempArray[0]); // assign the setAuthor temparray at index 1 to be stored in books[booksstored]
                
                // titles[booksStored] = tempArray[1]; // assign the temp at index 1 to the titles books stored
                
                books[numBooks].setTitle(tempArray[1]); // books[booksStored].setTitle(tempArray[1]); // assign the setTitle temparray at index 1 to be stored in books[booksstored]
                
                numBooks++;
            }
            
            if (numBooks >= sizeBook)// (booksStored >= capacity)
            {
                break; // get out and return what was given to this point 
            }
        }    
    }
    
    myFile.close();
    
    return numBooks;
}
