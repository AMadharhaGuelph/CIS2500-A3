#include "headerA3.h"
#include "headerHelp.h"

void countStopWords(tweet *tweetList) {
    // Declare vairables
    int numTweets = countTweets(tweetList);
    int numStopWords = 0;
    char *tempText;
    char *tempToken;
    char *tokens;
    tweet *temp;
    
    // Declare 2D array containing the stop words
    char stopWords[AMOUNT_STOP_WORDS][MAX_STOP_WORD_LENGTH] = {
        "A",
        "AN",
        "AND",
        "ARE",
        "AS",
        "AT",
        "BE",
        "BY",
        "FOR",
        "FROM",
        "HAS",
        "HE",
        "IN",
        "IS",
        "IT",
        "ITS",
        "OF",
        "ON",
        "THAT",
        "THE",
        "TO",
        "WAS",
        "WERE",
        "WILL",
        "WITH",
    };  

    // Check if list is empty
    if(tweetList == NULL) {
        printf("Across 0 tweets, 0 stop words were found.\n");
        return;
    }

    // Initialize vairables
    temp = tweetList;
    tempText = calloc(1, sizeof(char));
    tempToken = calloc(1, sizeof(char));
    // Iterate through the linked list
    while(temp != NULL) {
        // Split the current node's text to tokens
        tempText = realloc(tempText, (strlen(temp->text)+1) * sizeof(char));
        strcpy(tempText, temp->text);
        tokens = strtok(tempText, " ");
        // Iterate through the individual tokens
        while(tokens != NULL) {
            // Convert current token to uppercase for case insensitivity
            tempToken = realloc(tempToken, (strlen(tokens)+1) * sizeof(char));
            strcpy(tempToken, tokens);
            tempToken = toUpperCase(tempToken);
            // Iterate through the stop words
            for (int i = 0; i < AMOUNT_STOP_WORDS; i++) {
                // If the current token is a stopword, increment numStopWords
                if(strcmp(tempToken, stopWords[i]) == 0) {
                    numStopWords += 1; 
                }
            }
            tokens = strtok(NULL, " ");
        }
        temp = temp->next;
    }

    // Output amount of stop words found among n tweets
    printf("Across %d tweets, %d stop words were found.\n", numTweets, numStopWords);

    // Free variables
    free(tempText);
    free(tempToken);
}