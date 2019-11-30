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
