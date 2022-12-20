NAME: Ankush Madharha
USERNAME: amadharh
ASSIGNMENT: Tweet Manager (A3)
COURSE CODE: CIS2500
DATE OF LAST REVISION: April 3, 2022

Command to Compile:
make
Command to Run:
./output

COMPLETED MENU FUNCTIONS:
Prototypes in file: headerA3.h
    createTweet:
        The first menu function allows the user to create a new tweet by inputting their username and text. The function then calculates the id and adds the tweet to the end of the tweet list.
    displayTweets:
        The second menu function allows the user to display all the current tweets in the list.
    searchTweetsByKeyword:
        The third menu function allows the user to search all the current tweets in the list for a inputted keyword.
    countStopWords:
        The fourth menu function allows the user to count all the stop words that exist in the current tweet list.
    deleteTweet:
        The fifth menu function allows the user to delete a tweet from the current tweets in the list.
    saveTweetsToFile:
        The sixth menu function allows the user to save all the current tweets in the list to an inputted file.
    loadTweetsFromFile:
        The seventh menu function allows the user to import tweets into the tweet list from an inputted file.
    sortID:
        The eighth menu function allows the user to sort the current tweets in the list by their id value.
HELPER FUNCTIONS:
Prototypes in file: headerHelp.h
    createNode:
        This function malloc's a new node, sets the next member to NULL, and returns the newly created node (or tweet).
    searchForId:
        This function iterates through the passed list and searches for if the passed id exists within the list. Returns true if the id is found, returns false if the id is not found.
    freeTweets:
        This functions frees all the nodes in the passed list.
    toUpperCase:
        This function converts the passed string to uppercase.
    countTweets:
        This function counts all the tweets in the passed list and returns the number of tweets
    swap:
        This function swaps the two nodes that are passed.
    addNodeToList:
        This function adds the passed node to the end of the list that is passed.

LIMITATIONS:
An inefficiency exists in the countStopWords function. In the loop comparing the current word to all the stop words, once a stop word is found the comparisons should stop because it cannot be any other stop word. However, my program continues to make the comparisons even though a specific stop word has already been verified. This could be solved with a break statement, but I couldn't get this to work for whatever reason and it made the program behave in odd ways.
Other than that, all features and edge cases should be accounted for.

FUTURE IMPROVEMENTS:
In the current program, it manually converts strings to uppercase for case insensitivity. This can be improved by using strcasestr, and other such functions.

MESSAGE TO THE TA:
This has been a great semester! Thanks for working hard throughout the semester marking all our stuff, we know its not easy balancing marking and your own work. Thanks for the great semster and have an amazing summer!