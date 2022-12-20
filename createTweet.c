#include "headerA3.h"
#include "headerHelp.h"

tweet *createTweet(tweet *tweetList) {
    // Declare variables
    int id = 0;
    tweet *newTweet = createNode();
    char tempUser[1000];
    char tempText[1000];

    // Prompt user for username input while the length of input is invalid (length)
    do {
        printf("Enter a username: ");
        fgets(tempUser, 1000, stdin);
        tempUser[strlen(tempUser) - 1] = '\0';
    } while(strlen(tempUser) <= 0 || strlen(tempUser) > 50);
    strcpy(newTweet->user, tempUser);
    
    // Prompt user for text input while the length of input is invalid (length)
    do {
        printf("Enter the user's tweet: ");
        fgets(tempText, 1000, stdin);
        tempText[strlen(tempText) - 1] = '\0';
    } while(strlen(tempText) <= 0 || strlen(tempText) > 140);
    strcpy(newTweet->text, tempText);

    // Iterate through newTweet->user characters
    for(int i = 0; i < strlen(newTweet->user); i++)
        // Continually add the ASCII value of current character
        id += (int)(newTweet->user[i]);
    // Add the length of the text to the id
    id += strlen(newTweet->text);

    // Iterate while the current id is found in the linked list
    while(searchForId(tweetList, id) == true) {
        // Add a random number between (0-999) to the id
        srand(time(NULL));
        id += rand() % 1000;
    }
    newTweet->id = id;
    printf("Your computer generated userid is %d.\n", newTweet->id);
    
    return newTweet;
}