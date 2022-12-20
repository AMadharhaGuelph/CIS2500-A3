#include "headerA3.h"
#include "headerHelp.h"

void sortID (tweet **head) {
    // Declare variables
    int numTweets = countTweets(*head);
    tweet **h;
    int i, j, swapped = 0;

    // Check if the list is empty
    if(*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    // Bubble sort implementation to sort the linked list
    for(i = 0; i <= numTweets; i++) {
        h = head;
        swapped = 0;
        for(j = 0; j < numTweets - i - 1; j++) {
            tweet *p1 = *h;
            tweet *p2 = p1->next;
            if(p1->id > p2->id) {
                *h = swap(p1, p2);
                swapped = 1;
            }
            h = &(*h)->next;
        } 
        if(swapped == 0) {
            break;
        }
    }

    printf("Tweets sorted!\n");
}