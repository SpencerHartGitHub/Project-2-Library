#include <iostream>
#include <string>
#include <math.h>
#include "User.h"
#include "Book.h"
#include "Library.h"

Library :: Library()
{
    sizeBook = 50;
    
    sizeUser = 100;
    
    numBooks = 0;
    
    numUsers = 0;
}

int Library :: getSizeBook()
{
    return sizeBook;
}

int Library :: getSizeUser()
{
    return sizeUser;
}

int Library :: getNumBooks()
{
    return numBooks;
}

int Library :: getNumUsers()
{
    return numUsers;
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

int split(string textToBeSplit, char delimiter, string words[], int size)
{
    string storage = ""; // the temporary storage to hold the strings before delimiter hits
    int numSplit = 0;
    
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
                    words[numSplit] = storage; // moves storage to the index of j to later print
                    storage = ""; // reset storage to nothing
                    numSplit++; // make j add 1 to create new space in word
                }
            }
    }
    
    if (storage != "") // edge case 
    {
        words[numSplit] = storage; // put the last thing in storage into an index of words
        numSplit++; // for output to screen to eqaul right amount 
    }
    
    if(numSplit > size) // if the string is bigger than the size to hold it return 1 and the owrds it CAN output
    {
        return -1;
    }
    
    return numSplit;
}

int Library :: readBooks(string fileName)  //Book books[], int booksStored, int capacity)
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

void Library :: printAllBooks() //(Book books[], int numBooks)
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

void Library :: printBooksByAuthor(string authorName) // (Book books[], int numBooks)
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

int Library :: readRatings(string fileName) // (User users[], int numUsersStored, int userArraySize, int maxColumns) // previously stored number of users (0) / userArray is total size / max columns 51
{
    int tempRatings[50]; // holds 0 - 49 indexs
    
    string lines;
    
    ifstream myFile;
    
    myFile.open(fileName);
    
    if(numUsers >= sizeUser) // self explanatory 
    {
        return -2;
    }
    
    else if(!myFile.is_open()) // self explanatory
    {
       return -1; 
    }
    
    else if(numUsers < sizeUser) 
    {
        
        for(int i = numUsers; i < sizeUser; i++) 
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
                    
                numUsers++;
                
                
                for(int j = 1; j < num_words; j++) // represents the columns and if j is less than how many lines we split we continue
                {
                        
                    tempRatings[j - 1] = stoi (tempArray[j]); // put what was stored in the temp array starting after the name into ratings, but start j at 0 instead of 1
                        
                }
            }
            // this is why you have garbage value in viewRatings output, beause you happen to read only 4 ratings in you ratingFile.txt
            // the rest of tempRatings are filling witth garbage because tempRatings has not been initilised // tempRatings is initialized... at the top******?
            // User1,1,4,2
            // User2,0,5,3
            users[i] = User(username, tempRatings, num_words - 1); // call the user function and store it int the users[i]
            
        }
    }
    
    myFile.close();
    
    return numUsers;
}

int Library :: getRating(string username , string bookTitle) // (User users[] , Book books[] , int currentStoredUsers , int currentStoredBooks)
{
    lowercase(username);
    
    int userIndex; // initialize both these indexs
    
    int bookIndex;
    
    bool found = false; // set a bool to false initially 
    
    for(int i = 0; i < numUsers; i++)
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
        for(int i = 0; i < numBooks; i++)
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

int Library :: getCountReadBooks(string username) // (User users[], int currentStoredUsers, int currentStoredBooks)
{
    lowercase(username);
    
    int userIndex; // initialized
    
    int numberOfBooks = 0; // set to 0 for count
    
    bool found = false; // set bool
    
    for(int i = 0; i < numUsers; i++)
    {
        if(lowercase(username) == lowercase(users[i].getUsername())) // check to find matches for username
        {
            found = true; // if there is then change bool to true
            userIndex = i; // store found index in user index
            break;
    
        }
    }
    
    if(!found) // false
    {
        return -3;
    }
    
    if(found && numBooks > 0) // true 
    {
        for(int i = 0; i < numBooks; i++)
        {
            if(users[userIndex].getRatingAt(i) != 0) // if the user index and get rating at that i index do not equal 0 then add 1 to num books
            {
                numberOfBooks++;
            }
        }
        
        return numberOfBooks;
    }
    
    else 
    {
        return -3;
    }
    
}

void Library :: viewRatings(string username , int minRating)
{
    bool userFound = false;
    int userIndex = 0;
    
    for(int i = 0; i < numUsers; i++)
    {
        if(lowercase(users[i].getUsername()) == lowercase(username))
        {
            userIndex = i;
            userFound = true;
        }
    }
    
    if(!userFound)
    {
        cout << username << " does not exist." << endl;  
    }
    
    else
    {
        bool ratingFound = false;
        
        if(getCountReadBooks(username) != 0)
        {
            cout << "Here are the books that " << username << " rated" << endl;
        }
        // also here you might want to use numUsers that is the variable that represents the currentt number of users in the system.
        // - Punith
        for(int i = 0; i < numBooks; i++)
        {
            if(users[userIndex].getRatingAt(i) >= minRating)
            {
                ratingFound = true;
                
                cout << "Title : " << books[i].getTitle() << endl;
                cout << "Rating : " << users[userIndex].getRatingAt(i) << endl;
                cout << "-----" << endl;
                
            }
        }
    
        if(!ratingFound)
        {
            cout << username << " has not rated any books yet." << endl;
        }
    
    }
    
}

double Library :: calcAvgRating(string bookTitle)
{
    double counter = 0.0; // initialize everything
    
    double average = 0.0;
    
    double tempIndexBook = 0.0;
    
    double tempSum = 0.0;
    
    bool found = false; // set up a bool
    
    for(int i = 0; i < numBooks; i++)
    {
        if(lowercase(bookTitle) == lowercase(books[i].getTitle())) // find the title they want the ratings for 
        {
            found = true;
            tempIndexBook = i;
            break;
        }
    }
    
    if(!found) // false
    {
        return -3;
    }
    
    if(found && numUsers > 0) // true 
    {
        for(int i = 0; i < numUsers; i++)
        {
            if(users[i].getRatingAt(tempIndexBook) > 0)
            {
                tempSum = tempSum + users[i].getRatingAt(tempIndexBook); // put the ratings into the sum added up and add one to counter
                
                counter++;
            }
        }
        
        if(counter == 0)
        {
            return 0;
        }
        
        average = tempSum / counter; // gets average exluding 0's
        
        return average;
    }
    
    else
    {
        return -3;
    }
    
}

double Library :: calcAvgRatingByAuthor(string authorName)
{
    double counter = 0.0; // initialize everything
    
    double average = 0.0;
    
    double tempIndexAuthor = 0.0;
    
    double tempSum = 0.0;
    
    bool found = false; // set up a bool
    
    for(int i = 0; i < numBooks; i++)
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

int Library :: addUser(string username)
{
    if(numUsers >= sizeUser)
    {
        return -2;
    }
    
    if(numUsers < sizeUser)
    {
        for(int i = 0; i < numUsers; i++)
        {
            if(lowercase(username) == lowercase(users[i].getUsername()))
            {
                return 0;
            }
        }
    }
        users[numUsers].setUsername(username); 
                
        numUsers++;
                
        return 1;
}

int Library :: checkOutBook(string username , string bookTitle , int newRating)
{
    int userIndex;
    int bookIndex;
    
    bool found = false;
    
    if(newRating < 0 || newRating > 5)
    {
        return -4;
    }
    
    for(int i = 0; i < numUsers; i++)
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
        for(int i = 0; i < numBooks; i++)
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
    
    if(!found)
    {
        users[userIndex].setRatingAt(bookIndex, newRating);
        
        return 1;
    }
}

void Library :: getRecommendations(string username)
{
    int bestIndex;
    
    int userIndex;
    
    bool found = false;
    
    for(int i = 0; i < numUsers; i++)
    {
        if(lowercase(username) == lowercase(users[i].getUsername()) )
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
                if(i != userIndex)
                {
                // I would write this down on a piece of paper to see how the loop is changing 
                // This formula is close to being correct
                
                    if(users[userIndex].getRatingAt(j) != 0 || users[userIndex].getRatingAt(j) == 0 && users[i].getRatingAt(j) != 0)
                    {
                        SSD = SSD + pow( ( users[userIndex].getRatingAt(j) - users[i].getRatingAt(j) ) , 2 );
                    }
                    
                }
            }
            
            if(SSD != 0)
            {
                if(SSD < bestRec)
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
            
            if(users[userIndex].getRatingAt(i) == 0 && users[bestIndex].getRatingAt(i) >= 3)
            {
                recommend = true;
                
                // recommend
                
            }
        
        }
        
        if(recommend)
        {
            int booksRec = 0;
            
            cout << "Here is the list of recommendations" << endl;
            
            for(int i = 0; i < numBooks; i++)
            {
                if(booksRec < 5)
                {
                    if(users[userIndex].getRatingAt(i) == 0 && users[bestIndex].getRatingAt(i) >= 3)
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

