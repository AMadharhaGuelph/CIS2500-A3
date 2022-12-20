#include "headerA3.h"
#include "headerHelp.h"

tweet *createNode() {
    // Allocate memory to node
    tweet *newNode = malloc(sizeof(tweet));
    // Error check
    if(newNode == NULL) {
        printf("Error: malloc failed in createNode.\n");
        exit(0);
    }
    // Set next to null
    newNode->next = NULL;
    // Return new node
    return newNode;
}

bool searchForId(tweet *tweetList, int id) {
    // Declare variable
    tweet *temp = tweetList;
    // Iterate through the linked list
    while(temp != NULL) {
        // If the id is found return true
        if(temp->id == id) 
            return true;
        temp = temp->next;
    }

    // If the id is not found return false
    return false;
}

void freeTweets(tweet *tweetList) {
    // Declare variable
    tweet *temp = tweetList;

    // Iterate through the linked list
    while(tweetList != NULL) {
        // Free each node
        temp = tweetList;
        tweetList = tweetList->next;
        free(temp);
    }
}

char *toUpperCase(char *str) {
    // Iterate through the passed string, converting each to uppercase
    for(int i = 0; i < strlen(str); i++) {
        str[i] = toupper(str[i]);
    }
    // Return the converted uppercase string
    return str;
}

int countTweets(tweet *tweetList) {
    // Declare variables
    int count = 0;
    tweet *temp = tweetList;

    // Iterate through the linked list
    while(temp != NULL) {
        // Increment count
        count++;
        temp = temp->next;
    }

    // Return the amount of tweets in the list
    return count;
}

tweet *swap(tweet *p1, tweet *p2) {
    // Swap two nodes using a temp variable
    tweet *temp = p2->next;
    p2->next = p1;
    p1->next = temp;
    return p2;
}

void addNodeToList(tweet **tweetList, tweet *node) {
    // Declare variable
    tweet *lastNode = *tweetList;

    // If list is empty, set the head to the node passed as its the first node
    if(*tweetList == NULL) 
        *tweetList = node;
    else {
        // Iterate to the last node
        while(lastNode->next != NULL) 
            lastNode = lastNode->next;
        // Set the last node to the node passed
        lastNode->next = node;
    }
    
}
