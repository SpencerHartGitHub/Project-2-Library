#include <iostream>
#include <string>
#include "User.h"

/* 
*  Algorithm: Create the cpp file that basically controls what happens to what what initialized in the .h file
* 1. Include the User.h header 
* 2. Create the default constructor and set the four "parameters" to their base values (empty strings / 0's)
* 3. Create the parameterized constructor which we assgin to the members of the private class
* 4. Create getters and setters for each specified in .h file
* 5. Now get that name and return the private members
*/

User :: User() // default constructor
{
    username = "";
    
    numRatings = 0;
    
    size = 50;

    for(int i = 0; i < size; i++)
    {
         ratings[i] = 0;
    }
}

User :: User(string username_ , int ratings_[], int numRatings_) // parameterized constructor
{
    username = username_;
    
    numRatings = numRatings_;
    
    size = 50;
    
    for(int i = 0; i < numRatings_; i++)
    {
        ratings[i] = ratings_[i]; // filling with up to numRating
    }
    
    for(int i = numRatings_; i < size; i++)
    {
        ratings[i] = 0; // fills rest up with 0's till size cap
    }
}

void User :: setUsername(string username_)
{
    username = username_;
}

string User :: getUsername()
{
    return username;
}

bool User :: setRatingAt(int index , int value)
{
    
    if(index < size && index >= 0 && value >=0 && value <= 5)
    {
        ratings[index] = value;
        return true;
    }
    
    if(index < 0 || index >= size || value < 0 || value > 5)
    {
        return false;
    }
}

int User :: getRatingAt(int index)
{
   if(index < 50 && index >= 0)
   {
       return ratings[index];
   }
   
   else
   {
       return -1;
   }
    
}

void User :: setNumRatings(int numRatings_)
{
    numRatings = numRatings_;
}

int User :: getNumRatings()
{
    return numRatings;
}

int User :: getSize()
{
    return size;
}

