#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include "Book.h"
#include "User.h"
#include "Library.h"
using namespace std;

/*
* Algorithm: a fundtion tha recommends book titles that a user might like based on ratings
* 1. find and store the usernames index
* 2. Set up SSD to collects the users scoers squared
* 3. Update the lowest SSD score
* 4. If the ratingsfor both users meet the requirements of recommendation then recommend the book if not cout a msg
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


void getRecommendations(string username)
{
    int bestIndex;
    
    int userIndex;
    
    bool found = false;
    
    for(int i = 0; i < numUsers; i++)
    {
        if(lowercase(username) == lowercase(users[i].getUsername()) ) // find user and store its index
        {
            found = true;
            
            userIndex = i;
            
            break;
        }
    }
    
    if(!found)
    {
        cout << username << " does not exist." << endl;
    }
            
    else
    {
        int SSD = 0; //unitilised, will have undefined variables. 
        int bestRec = 10000000;
                
        for(int i = 0; i < numUsers; i++)
        {
            SSD = 0;
            
            for(int j = 0; j < numBooks; j++)
            {
                if(i != userIndex) // dont compare the given user with itself
                {
                // I would write this down on a piece of paper to see how the loop is changing 
                // This formula is close to being correct
                
                    if(users[userIndex].getRatingAt(j) != 0 || users[userIndex].getRatingAt(j) == 0 && users[i].getRatingAt(j) != 0) // so you cant compare two 0's but can compare 0 witha # > 0
                    {
                        SSD = SSD + pow( ( users[userIndex].getRatingAt(j) - users[i].getRatingAt(j) ) , 2 ); // goes through this for each rating of the 2 users
                    }
                    
                }
            }
            
            if(SSD != 0)
            {
                if(SSD < bestRec) // imidiatly stores and updates the best score
                {
                    
                    bestRec = SSD;
                    bestIndex = i;
                    
                }
            }
            
        }
                // this idea seems good, if you work on the top part
                // I would print out your entire SSD array to check if it has correct values.
                
                
        bool recommend = false;
        
        for(int i = 0; i < numBooks; i++)
        {
            
            if(users[userIndex].getRatingAt(i) == 0 && users[bestIndex].getRatingAt(i) >= 3) // if at least one book is able to pass this test change bool
            {
                recommend = true;
                
                // recommend
                
            }
        
        }
        
        if(recommend) // if true
        {
            int booksRec = 0;
            
            cout << "Here is the list of recommendations" << endl;
            
            for(int i = 0; i < numBooks; i++)
            {
                if(booksRec < 5)
                {
                    if(users[userIndex].getRatingAt(i) == 0 && users[bestIndex].getRatingAt(i) >= 3) // gets the ratings at those indexs 
                    {
                        cout << books[i].getTitle() << " by " << books[i].getAuthor() << endl;
                        booksRec++; // This gets the best recs out of the numBooks (50)
                    }
                }
            }
            
        }
        
        if(!recommend)
            {
                
                cout << "There are no recommendations for " << username << " at present." << endl;
                
            }
    }
}
