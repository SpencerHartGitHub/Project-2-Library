#include <iostream>
#include <string>
#include <fstream>
#include "Book.h"
#include "User.h"
#include "Library.h"
using namespace std;

/*
* Algorithm: create a function that adds a user to the already user base
* 1. check to see if the array is full or not
* 2. now check to see if the user exists already or not
* 3. Now add the user name by doing getUsername
* 4. Add 1 to numUsers array
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

int addUser(string username)
{
    if(numUsers >= sizeUser) // if full
    {
        return -2;
    }
    
    if(numUsers <= sizeUser)
    {
        for(int i = 0; i < numUsers; i++)
        {
            if(lowercase(username) == lowercase(users[i].getUsername())) // if already present
            {
                return 0;
            }
                
            else
            {
                users[i].getUsername() = users[i].getUsername() + username; // add the username to the users array 
                
                numUsers++; // increase the array
                
                return 1;
            }
        }
    }
}
