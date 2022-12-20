#include "headerA3.h"
#include "headerHelp.h"

int main() {
    // Declare variables
    int menuSelection;
    tweet *tweetList = NULL;

    // Output menu functions while user does not input 9
    do {
        // Output menu
        printf("1. Create a new tweet\n");
        printf("2. Display tweets\n");
        printf("3. Search a tweet (by keyword)\n");
        printf("4. Find how many words are \"stop words\"\n");
        printf("5. Delete the nth tweet\n");
        printf("6. Save tweets to a file\n");
        printf("7. Load tweets from a file\n");
        printf("8. Sort the given linked list on userid\n");
        printf("9. Exit\n");

        // Prompt user for menu selection
        printf("Select an option from the menu (1-9): ");
        scanf("%d", &menuSelection);

        // Flush input buffer
        int c;
        while ((c = getchar()) != '\n' && c != EOF) { }

        printf("\n");
        // Depending on menu selection, call specific function
        switch(menuSelection) {
            case 1:
                addNodeToList(&tweetList, createTweet(tweetList));
                break;
            case 2:
                displayTweets(tweetList);
                break;
            case 3:
                searchTweetsByKeyword(tweetList);
                break;
            case 4:
                countStopWords(tweetList);
                break;
            case 5:
                deleteTweet(&tweetList);
                break;
            case 6:
                saveTweetsToFile(tweetList);
                break;
            case 7:
                loadTweetsFromFile(&tweetList);
                break;
            case 8:
                sortID(&tweetList);
                break;
        }
        printf("\n");

    } while(menuSelection != 9);

    // Free the linked list containing the tweets
    freeTweets(tweetList);

    printf("Exited\n");

    return 0;
}