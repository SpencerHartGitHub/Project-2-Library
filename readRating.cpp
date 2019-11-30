#include <iostream>
#include <string>
#include <fstream>
#include "User.h"
#include "Library.h"
using namespace std;

/*
* Algorithm: Create a function that has 6 parameters and returns the number of users after all the code. 
* 1. Create a string for the lines 
* 2. create the ifstream myfile
* 3. open the file 
* 4. Check to see if the number of users is equal to max rows at the get go and if so return -2
* 5. Else if check if the file opens 
* 4. if it does open check if the number of user is less than the max number of rows
* 5. Create a for loop that starts at the number of user and goes up until the max rows is reached
* 6. inside that loop check if there are now lines and if there isnt anything in the lines break (get out of loop)
* 7. If there are lines to get create a temp array that can store 51 for the rater and the ratings 
* 8. create an int for num_users and set the split function to that to see how many times it was split and put it in num_users
* 9. Now store what was in the temp array at in 0 only into the users for the index of i
* 10. now make a if to see if there is nothing left in the line and if so subtract 1 from i
* 11. Now check if there are more line
* 12. If there are more lines add one to numUsers
* 13. create another for loop that is initialized at 1 and goes up until the num_users that we initialized earlier
* 14. Now take what was stored in the temp at j (starts at 1) and put it into ratings at idex i and j (j-1) because we want the columns to be 0 again
* 15. After everything close the file and return the final numUsers collected
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


int readRatings(string fileName, User users[], int numUsersStored, int userArraySize, int maxColumns) // previously stored number of users (0) / userArray is total size / max columns 51
{
    int tempRatings[50]; // holds 0 - 49 indexs
    
    string lines;
    
    ifstream myFile;
    
    myFile.open(fileName);
    
    if(numUsersStored >= userArraySize) // self explanatory 
    {
        return -2;
    }
    
    else if(!myFile.is_open()) // self explanatory
    {
      return -1; 
    }
    
    else if(numUsersStored < userArraySize) 
    {
        
        for(int i = numUsersStored; i < userArraySize; i++) 
        {
            
            if(!getline(myFile, lines)) // if there are no lines to get then get out of this loop
            {
                break;
            }
            
            string tempArray[51]; // sets a temp array of 51 spaces(to hold the 50 digits and + 1 for the name)
                
            int num_words = split(lines, ',', tempArray, 51); // initializes num_words and assigns the split that goes through each line 
                
            string username = tempArray[0]; // stores whats in index 0 ( the name ) into users i ( each row )
            
            if(lines == "") // if there is nothing in the line make it subtract 1 i to get there to be no spaces in the output
            {
                i--; // subtract 1 from I and continue instead of putting nothing in the users[i]
                continue;
            }
            
            if(lines.length() != 0) // not empty so add 1 to num users
            {
                    
                numUsersStored++;
                
                
                for(int j = 1; j < num_words; j++) // represents the columns and if j is less than how many lines we split we continue
                {
                        
                    tempRatings[j - 1] = stoi (tempArray[j]); // put what was stored in the temp array starting after the name into ratings, but start j at 0 instead of 1
                        
                }
            }
            
            users[i] = User(username, tempRatings, maxColumns); // call the user function and store it int the users[i]
            
        }
    }
    
    myFile.close();
    
    return numUsersStored;
}
