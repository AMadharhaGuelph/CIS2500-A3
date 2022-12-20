#include "headerA3.h"
#include "headerHelp.h"

void loadTweetsFromFile(tweet **tweetList) {
    // Declare variables
    FILE* loadFile;
    char fileName[50];
    char str[250];
    char id[20];
    char *ptr;

    // Prompt user for filename input
    printf("Enter a filename to load from: ");
    scanf("%s", fileName);

    // Open file for reading
    loadFile = fopen(fileName, "r");

    // Check if there was an error opening the file
    if(loadFile == NULL) {
        printf("Error opening file in loadTweetsFromFile.\n");
        return;
    }

    // Iterate through the file, storing the current line in str
    while(fgets(str, 250, loadFile)) {
        // Remove \n by fgets
        str[strlen(str)-1] = '\0';
        // Create a new node and store data into its memebers
        tweet *newNode = createNode();
        sscanf(str, "%[^,],%[^,],%[^'\n']", id, newNode->user, newNode->text);
        // Replace last comma due to csv file
        ptr = strrchr(newNode->text, ',');
        if(ptr != NULL) {
            *ptr = '\0';
        }
        newNode->id = atoi(id);
        // add the node to the list
        addNodeToList(tweetList, newNode);
    }

    // Close file
    fclose(loadFile);

    printf("Tweets imported!\n");
}