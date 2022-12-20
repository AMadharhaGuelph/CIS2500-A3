#include "headerA3.h"
#include "headerHelp.h"

void deleteTweet(tweet **tweetList) {
    // Declare variables
    const int numTweets = countTweets(*tweetList);
    int numDelTweet = 0;

    // Check if list is empty
    if(*tweetList == NULL) {
        printf("There are no tweets to delete.\n");
        return;
    }

    // Prompt user for the tweet they would like to delete
    printf("Currently there are %d tweets.\n", numTweets);
    do {
    printf("Which tweet do you with to delete - enter a value between 1 and %d: ", numTweets);
    scanf("%d", &numDelTweet);
    } while(numDelTweet == 0 || numDelTweet > numTweets);
    // If the user wants to delete the first node, execute following
    if(numDelTweet == 1) {
        // Set temp to the current head
        tweet *temp = *tweetList;
        // Set head to the next node
        *tweetList = (*tweetList)->next;
        printf("Tweet %d deleted. There are now %d tweets left.\n", temp->id, numTweets-1);
        // Free temp, the previous head
        free(temp);
    }
    // If the user wants to delete the last node, execute following
    else if(numDelTweet == numTweets) {
        // Declare variables
        tweet *secondLastNode, *nodeToDelete;
        secondLastNode = *tweetList;
        nodeToDelete = *tweetList;

        // Iterate through the linked list
        while(nodeToDelete->next != NULL) {
            // nodeToDelete must be the last node in the list, and the secondLast Node is the second last
            secondLastNode = nodeToDelete;
            nodeToDelete = nodeToDelete->next;
        }
        // Set secondLastNode-> to NULL since this is now the last node
        secondLastNode->next = NULL;
        printf("Tweet %d deleted. There are now %d tweets left.\n", nodeToDelete->id, numTweets-1);
        // Free the last node
        free(nodeToDelete);
    }
    // If the user wants to delete a node in the middle, execute following
    else {
        // Declare variables
        tweet *curr, *prev;

        curr = *tweetList;

        // Iterate to the tweet they would like to delete
        for(int i = 0; i < numDelTweet-1; i++) {
            // Store the previous node and the current node (we are deleting current node)
            prev = curr;
            curr = curr->next;
        }
        // Link the previous node to the node after the node we are deleting
        prev->next = curr->next;
        printf("Tweet %d deleted. There are now %d tweets left.\n", curr->id, numTweets-1);
        // Free the current node
        free(curr);
    }
    

}