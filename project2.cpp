#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
using namespace std;
#include "Book.h"
#include "Book.cpp"
#include "User.h"
#include "User.cpp"
#include "Library.h"
#include "Library.cpp"

int main()
{
    Library project;
    
    int input = 1; // initialize EVERYTHINGGGGG
    
    string fileName;
    string authorName;
    string bookTitle;
    string username;
    int numBooks = 0;
    int numUsers = 0;
    Book books[50];
    User users[100];
    int sizeBook = 50;
    int sizeUser = 100;
    int userIndex = 0;
    int bookIndex = 0;
    int bestIndex = 0;
    int bestRec = 10000000;
    int SSD = 0;
    int booksRec = 0;
    int minRating = 0;
    int newRating = 0;
    
    while(input == 1 || input == 2 || input == 3 || input == 4 || input == 5 || input == 6 || input == 7 || input == 8 || input == 9 || input == 10 || input == 11 || input == 12 || input == 13 )
    {    
        cout << "Select a numerical option:" << endl;
        cout << "======Main Menu=====" << endl;
        cout << "1. Read books" << endl;
        cout << "2. Read ratings" << endl;
        cout << "3. Print all books" << endl;
        cout << "4. Print books by author" << endl;
        cout << "5. Get rating" << endl;
        cout << "6. Find number of books user rated" << endl;
        cout << "7. View ratings" << endl;
        cout << "8. Get average rating" << endl;
        cout << "9. Get average rating by author" << endl;
        cout << "10. Add a user" << endl;
        cout << "11. Checkout a book" << endl;
        cout << "12. Get recommendations" << endl;
        cout << "13. Quit" << endl;
        
        cin >> input;
        
        if (input < 1 || input > 13)
        {
            cout << "Invalid input." << endl;
            
            cout << endl;
            
            return main(); //returns to menu
        }
        
        else if(input == 1) // readBooks
        {
            
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
            
            cout << "Enter a book file name:" << endl;
            
            cin >> fileName;
            
            int value = project.readBooks(fileName);
            
            if(value == -1)
            {
                
                cout << "No books saved to the database." << endl;
                
                cout << endl;
                
            }
            
            else if(value == -2)
            {
                
                cout << "Database is already full. No books were added." << endl;
                
                cout << endl;
                
            }
            
            else if(value == sizeBook)
            {
                
                cout << "Database is full. Some books may have not been added." << endl;
                
                cout << endl;
                
                numBooks = value;
                
            }
            
            else
            {
                
                cout << "Total books in the database: " << value << endl;
                
                cout << endl;
                
                numBooks = value;
                
            }
            
            
        }
        
        else if(input == 2) // readRatings
        {
            
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

            cout << "Enter a user file name:" << endl;
            
            cin >> fileName;
            
            int value = project.readRatings(fileName);
            
            if(value == -1)
            {
                
                cout << "No users saved to the database." << endl;
                
                cout << endl;
                
            }
            
            else if(value == -2) 
            {
                
                cout << "Database is already full. No users were added." << endl;
                
                cout << endl;
                
            }
            
            else if(value == sizeUser)
            {
                
                cout << "Database is full. Some users may have not been added." << endl;
                
                cout << endl;
                
                numUsers = value;
                
            }
            
            else
            {
                
                cout << "Total users in the database: " << value << endl;
                
                cout << endl;
                
                numUsers = value;
                
            }
            
        }
        
        else if(input == 3) //printBooks
        {
            
            /*
            * Algorithm: Create a function that take three parameters to print if there are books sotred or not and list the books and who it is written by
            * 1. Create a if statement that states if the books value is less than or equal to zero print the statement seen
            * 2. Else (there is books (positive)) print the statement seen
            * 3. Create a for loop that goes through the number of books given and print them by titles and who they are by
            */
            
            if(numBooks == 0 && numUsers == 0)
            {
                
                cout << "Database has not been fully initialized." << endl;
                
                cout << endl;
                
            }
            
            else
            {
                
                project.printAllBooks();
                
                cout << endl;
                
            }
            
        }
        
        else if(input == 4) // printBooksByAuthor
        {
            
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
            
            if(numBooks == 0 && numUsers == 0)
            {
                
                cout << "Database has not been fully initialized." << endl;
                
                cout << endl;
                
            }
            
            else
            {
                
                cout << "Enter an author name:" << endl;
                
                cin.ignore();
                
                getline(cin, authorName);
                
                project.printBooksByAuthor(authorName);
                
                cout << endl;
                
            }
            
        }
        
        else if(input == 5) // getRating
        {
            
            /*
            * Algorithm: Write a function that when given a user name and book title we want to return the rating the user gave that specific book.
            * 1. Apply the split and lowercase functions for later use
            * 2. create a function with 6 parameters 
            * 3. initialize everything that needs it
            * 4. Create a bool to decide the return at the end.
            */
            
            if(numUsers == 0 && numBooks == 0)
            {
                
                cout << "Datbase has not been fully initialized." << endl;
                
                cout << endl;
                
            }
            
            else
            {
                
                cout << "Enter a user name:" << endl;
                
                cin.ignore();
                
                getline(cin, username);
                
                cout << "Enter a book title:" << endl;
                
                getline(cin, bookTitle);
                
                int value = project.getRating(username, bookTitle);
                
                if(value == 0)
                {
                    
                    cout << username << " has not rated " << bookTitle << endl;
                    
                    cout << endl;
                    
                }
                
                else if(value == -3)
                {
                    
                    cout << username << " or " << bookTitle << " does not exist." << endl;
                    
                    cout << endl;
                    
                }
                
                else 
                {
                    
                    cout << username << " rated " << bookTitle << " with " << value << endl;
                    
                    cout << endl;
                    
                    value = users[userIndex].getRatingAt(bookIndex);
                    
                }
                
            }
            
        }
        
        else if(input == 6) // getCountReadBooks
        {
            
            /*
            * Algorithm: Write a function that counts how many times a book has been rated by a user
            * 1. Apply the lowercase functions for later use
            * 2. create a function with 4 parameters 
            * 3. initialize everything that needs it
            * 4. Create a bool to decide the return at the end.
            */
            
            if(numBooks == 0 && numUsers == 0)
            {
                
                cout << "Database has not been fully initialized." << endl;
                
                cout << endl;
                
            }
            
            else
            {
                
                cout << "Enter a user name:" << endl;
                
                cin.ignore();
                
                getline(cin, username);
                
                int value = project.getCountReadBooks(username);
                
                if(value == 0)
                {
                    
                    cout << username << " has not rated any books." << endl;
                    
                    cout << endl;
                    
                }
                
                else if(value == -3)
                {
                    
                    cout << username << " does not exist." << endl;
                    
                    cout << endl;
                    
                }
                
                else
                {
                    
                    cout << username << " rated " << value << " books." << endl;
                    
                    cout << endl;
                    
                }
                
            }
            
        }
        
        else if(input == 7) // viewRatings
        {
            
            /*
            * Algorithm: A function that prints all the books a user has provided ratings for if the rating is greater than or equal to the minimum rating given.
            * 1. Check to see if there is a username in the system before proceeding
            * 2. If not cout a msg
            * 3. if there is make sure the user has rated books and if soo cout a msg
            * 4. Then go rating to rating and see if its greater than the min and cout them
            * 5. if not cout a msg
            */
            
            if(numBooks == 0 && numUsers == 0)
            {
                
                cout << "Database has not been fully initialized." << endl;
                
                cout << endl;
                
            }
            
            else
            {
                
                cout << "Enter a user name:" << endl;
                
                cin.ignore();
                
                getline(cin, username);
                
                cout << "Enter a minimum rating:" << endl;
                
                cin >> minRating;
                
                project.viewRatings(username, minRating);
                
                cout << endl;
                
            }
            
        }
        
        else if(input == 8) // calcAverageRating
        {
            
            /*
            * Algorithm: create a function that return the average rating for a particular book
            * 1. Create a function wihh 1 parameters
            * 2. initialize everything
            * 3. create a bool to decide what gets returned in some cases
            * 4. return the average once you get all the ratings for the book
            */
            
            if(numBooks == 0 && numUsers == 0)
            {
                
                cout << "Database has not been fully initialized." << endl;
                
                cout << endl;
                
            }
            
            else
            {
                
                cout << "Enter a book title:" << endl;
                
                cin.ignore();
                
                getline(cin, bookTitle);
                
                double value = project.calcAvgRating(bookTitle);
                
                if(value == -3)
                {
                    
                    cout << bookTitle << " does not exist." << endl;
                    
                    cout << endl;
                    
                }
                
                else 
                {
                    
                    cout << "The average rating for " << bookTitle << " is " << value << endl;
                    
                    cout << endl;
                    
                }
                
            }
            
        }
        
        else if(input == 9) // calcAverageRatingByAuthor
        {
            
            /*
            * Algorithm: create a function that when given the author find the average rating of the books they have written
            * 1. find the author
            * 2. get the ratings for each book and add them then divideby the amounnt to get average.
            */
            
            if(numBooks == 0 && numUsers == 0)
            {
                
                cout << "Database has not been fully initialized." << endl;
                
                cout << endl;
                
            }
            
            else
            {
                
                cout << "Enter an author name:" << endl;
                
                cin.ignore();
                
                getline(cin, authorName);
                
                double value = project.calcAvgRatingByAuthor(authorName);
                
                if(value == -3)
                {
                    
                    cout << authorName << " does not exist." << endl;
                    
                    cout << endl;
                    
                }
                
                else 
                {
                    
                    cout << "The average rating by " << authorName << " is " << value << endl;
                    
                    cout << endl;
                    
                }
                
            }
            
        }
        
        else if(input == 10) // addUser
        {
            
            /*
            * Algorithm: create a function that adds a user to the already user base
            * 1. check to see if the array is full or not
            * 2. now check to see if the user exists already or not
            * 3. Now add the user name by doing getUsername
            * 4. Add 1 to numUsers array
            */
            
            cout << "Enter a user name:" << endl;
            
            cin.ignore();
            
            getline(cin, username);
            
            int value = project.addUser(username);
            
            if(value == 0)
            {
                
                cout << username << " already exists in the database." << endl;
                
                cout << endl;
                
            }
            
            else if(value == -2)
            {
                
                cout << "Database is already full. " << username << " was not added." << endl;
                
                cout << endl;
                
            }
            
            else if(value == 1)
            {
                
                cout << "Welcome to the library " << username << endl;
                
                cout << endl;
                
            }
        }
        
        else if(input == 11) // checkOutBook
        {
            
            /*
            * Algorithm: A functions that will update the current rating for a book with a new one
            * 1. set parimeters 
            * 2. find and store the username of the user that you want to replace the rating for
            * 3. Now find a store the book titles index 
            * 4. now replace the rating witht the new one
            */
            
            if(numBooks == 0 && numUsers == 0)
            {
                
                cout << "Database has not been fully initialized." << endl;
                
                cout << endl;
                
            }
            
            else
            {
                
                cout << "Enter a user name:" << endl;
                
                cin.ignore();
                
                getline(cin, username);
                
                cout << "Enter a book title:" << endl;
                
                getline(cin, bookTitle);
                
                cout << "Enter a new rating:" << endl;
                
                cin >> newRating;
                
                
                int value = project.checkOutBook(username, bookTitle, newRating);
                
                if(value == -4)
                {
                    
                    cout << newRating << " is not valid." << endl; 
                    
                    cout << endl;
                    
                }
                
                else if(value == -3)
                {
                    
                    cout << username << " or " << bookTitle << " does not exist." << endl;
                    
                    cout << endl;
                    
                }
                
                else if(value == 1)
                {
                    
                    cout << "We hope you enjoyed your book. The rating has been updated." << endl;
                    
                    cout << endl;
                    
                }
                
            }
            
        }
        
        else if(input == 12) // getRecommendations
        {
            
            /*
            * Algorithm: a fundtion tha recommends book titles that a user might like based on ratings
            * 1. find and store the usernames index
            * 2. Set up SSD to collects the users scoers squared
            * 3. Update the lowest SSD score
            * 4. If the ratingsfor both users meet the requirements of recommendation then recommend the book if not cout a msg
            */
            
            if(numBooks == 0 && numUsers == 0)
            {
                
                cout << "Database has not been fully initialized." << endl;
                
                cout << endl;
                
            }
            
            else
            {
                
                cout << "Enter a user name:" << endl;
                
                cin.ignore();
                
                getline(cin, username);
                
                project.getRecommendations(username);
                
                cout << endl;
                
            }
            
        }
        
        else if(input == 13) // EXIT
        {
            
            cout << "Good bye!" << endl;
                break;
            
        }
    }
    
    return 0;
}
