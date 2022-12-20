CC=gcc 
CFLAGS=-Wall -std=c99

output: createTweet.o displayTweets.o searchTweetsByKeyword.o countStopWords.o deleteTweet.o saveTweetsToFile.o loadTweetsFromFile.o sortID.o helper.o mainA3.o
	$(CC) $(CFLAGS) createTweet.o displayTweets.o searchTweetsByKeyword.o countStopWords.o deleteTweet.o saveTweetsToFile.o loadTweetsFromFile.o sortID.o helper.o mainA3.o -o output
createTweet.o: createTweet.c headerA3.h headerHelp.h
	$(CC) $(CFLAGS) -c createTweet.c
displayTweets.o: displayTweets.c headerA3.h
	$(CC) $(CFLAGS) -c displayTweets.c
searchTweetsByKeyword.o: searchTweetsByKeyword.c headerA3.h headerHelp.h
	$(CC) $(CFLAGS) -c searchTweetsByKeyword.c
countStopWords.o: countStopWords.c headerA3.h headerHelp.h
	$(CC) $(CFLAGS) -c countStopWords.c
deleteTweet.o: deleteTweet.c headerA3.h headerHelp.h
	$(CC) $(CFLAGS) -c deleteTweet.c
saveTweetsToFile.o: saveTweetsToFile.c headerA3.h
	$(CC) $(CFLAGS) -c saveTweetsToFile.c
loadTweetsFromFile.o: loadTweetsFromFile.c headerA3.h headerHelp.h
	$(CC) $(CFLAGS) -c loadTweetsFromFile.c
sortID.o: sortID.c headerA3.h headerHelp.h
	$(CC) $(CFLAGS) -c sortID.c
helper.o: helper.c headerA3.h headerHelp.h
	$(CC) $(CFLAGS) -c helper.c
mainA3.o: mainA3.c headerA3.h headerHelp.h
	$(CC) $(CFLAGS) -c mainA3.c
clean:
	rm *.o output