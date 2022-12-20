#include "headerA3.h"
#include "headerHelp.h"

int searchTweetsByKeyword(tweet *tweetList) {
    // Declare variables
    tweet *temp = tweetList;
    char keyword[141];
    char *keywordUpper;
    char *textUpper;
    int found = 0;

    // Prompt user for keyword
    printf("Enter a keyword to search: ");
    fgets(keyword, 140, stdin);
    keyword[strlen(keyword) - 1] = '\0';

    // Convert the keyword to uppercase for case insensitivity
    keywordUpper = calloc(strlen(keyword)+1, sizeof(char));
    strcpy(keywordUpper, keyword);
    keywordUpper = toUpperCase(keywordUpper);
    
    textUpper = calloc(1, sizeof(char));
    while(temp != NULL) {
        // Conver the text to uppercase for case insensitivity
        textUpper = realloc(textUpper, (strlen(temp->text)+1) * sizeof(char));
        strcpy(textUpper, temp->text);
        textUpper = toUpperCase(textUpper);
        // If the keyword is found in the text, output match found. Update found.
        if(strstr(textUpper, keywordUpper) != NULL) {
            printf("Match found for '%s': %s wrote: \"%s\"\n", keyword, temp->user, temp->text);
            found = 1;
        }
        temp = temp->next;
    }

    // Free variables
    free(keywordUpper);
    free(textUpper);

    // If the keyword was not found, output message to user
    if(found == 0) {
        printf("No Tweets containing \"%s\" were found.\n", keyword);
    }

    return found;
}