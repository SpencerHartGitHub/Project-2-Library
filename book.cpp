#include <iostream>
#include <string>
#include "Book.h"

/*
* Algorithm: Create the cpp file that basically controls what happens to what what initialized in the .h file
* 1. Include the book.h header 
* 2. Create the default constructor and set the two "parameters" to their base values (empty strings)
* 3. Create the parameterized constructor which we assgin to the members of the private class
* 4. Now create a void setName that belongs to the Planet class and takes the planet and sets it to the memeber
* 5. Now get that name and return the private member
* 6. Do the same set for radius and same get 
* 7. Fianlly we want to get the volume so we create the equation and put the already given radius into it then return the final answer of volume
*/

Book::Book() // defualt constructor
{
    title = "";
    
    author = "";
}

Book::Book(string titles, string authors) // assigning to a member of the class ( ALSO MAKE THEM SLIGHTLY DIFFERENT FROM H FILE)
{
    title = titles;
    
    author = authors;
}

void Book::setTitle(string titles) // setting up the setters and getters
{
    title = titles;
}
        
string Book::getTitle()
{
    return title;
}
        
void Book::setAuthor(string authors)
{
    author = authors;
}
        
string Book::getAuthor()
{
    return author;
}

