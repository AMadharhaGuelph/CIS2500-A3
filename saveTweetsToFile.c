#include "headerA3.h"

void saveTweetsToFile(tweet *tweetList) {
    // Declare variables
    char fileName[50];
    tweet *temp = tweetList;
    FILE *saveFile;

    // Prompt user for filename input
    printf("Enter the filename where you would like to store your tweets: ");
    scanf("%s", fileName);

    // Open file for writing
    saveFile = fopen(fileName, "w");

    // Iterate through the linked list
    while(temp != NULL) {
        // Write the current node to the file in csv format
        fprintf(saveFile, "%d, %s, %s\n", temp->id, temp->user, temp->text);
        temp = temp->next;
    }

    printf("Output successful!\n");

    // close file
    fclose(saveFile);
}