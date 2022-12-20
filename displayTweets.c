#include "headerA3.h"

void displayTweets(tweet *tweetList) {
    // Declare variable
    tweet *temp = tweetList;

    // Check if the list is empty
    if(tweetList == NULL) {
        printf("No tweets to display.\n");
        return;
    }

    // Iterate through the linked list
    while(temp != NULL) {
        // Output the current node's members
        printf("%d: Created by %s: %s\n", temp->id, temp->user, temp->text);
        temp = temp->next;
    }
}