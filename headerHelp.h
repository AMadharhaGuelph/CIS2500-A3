// Includes
#include <stdbool.h>
#include <time.h>
#include <ctype.h>

// Macros
#define AMOUNT_STOP_WORDS 25
#define MAX_STOP_WORD_LENGTH 5

// Function Declarations
tweet *createNode();

bool searchForId(tweet *tweetList, int id);

void freeTweets(tweet *tweetList);

char *toUpperCase(char *str);

tweet *swap(tweet *p1, tweet *p2);

int countTweets(tweet *tweetList);