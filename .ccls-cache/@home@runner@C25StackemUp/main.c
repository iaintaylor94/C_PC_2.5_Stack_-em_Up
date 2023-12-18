#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>
#include <sys/errno.h>


// Constants
const int gMaxLineLength = 162;
const int gNumCardsInDeck = 52;
const int gNumCardsPerSuit = 13;
const int gMaxNumShuffles = 100;

enum suit { CLUBS, DIAMONDS, HEARTS, SPADES };
enum value { TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE };

// Declare file handles
FILE *gInputFile;

// Declare Structures / Arrays
int gShuffleOrders[gMaxNumShuffles][gNumCardsInDeck];
int gCards[gNumCardsInDeck];


// Declare Functions
// File Handling
void usage (char *);

// Input Functions
int getNum (FILE*);
int getNumCases (FILE*);
void removeBlankLine (FILE*);
int getNumShuffles (FILE*);
void getShuffle (int [gMaxNumShuffles][gNumCardsInDeck], int, FILE*);
void printShuffle (int, int[gMaxNumShuffles][gNumCardsInDeck]);
int getShuffleNum (FILE*);

// Initialise and Shuffle Deck
void initDeck (int [gNumCardsInDeck]);
void shuffleDeck (int, int[gMaxNumShuffles][gNumCardsInDeck], int[gNumCardsInDeck]);

// Card Translations
enum value getCardValue (int);
enum suit getCardSuit (int);

// Print Cards
void printValue(enum value);
void printSuit(enum suit);
void printCard (int);
void printDeck (int [gNumCardsInDeck]);


int main(int argc, char *argv[]) {
  /*-------------------------------FILE INITIALIZATION START-----------------------------*/
  if (argc != 2) usage (argv[0]);

  if (NULL == (gInputFile = fopen(argv[1], "r"))) {
    fprintf (stderr, "inputFile: %s: %s\n", argv[1], strerror(errno));
    exit (EXIT_FAILURE);
  }
  else {
    fprintf (stderr, "%s opened for reading.\n\n" , argv[1]);
  }
  /*-------------------------------FILE INITIALIZATION END--------------------------------*/
  /*--------------------------------MAIN PROGRAM START------------------------------------*/

  // Initialise deck
  initDeck(gCards);

  // Get input
  int numCases = getNumCases (gInputFile);
  removeBlankLine (gInputFile);
  int numShuffles = getNumShuffles (gInputFile);
  printf ("\n");

  for (int i = 0; i < numShuffles; i++) {
    getShuffle (gShuffleOrders, i, gInputFile);
  }

  int deckNum = getShuffleNum(gInputFile);
  while (deckNum != -1) {
    shuffleDeck (deckNum, gShuffleOrders, gCards);
    deckNum = getShuffleNum(gInputFile);
  }
  
  printDeck (gCards);
  
  
  /*--------------------------------MAIN PROGRAM END--------------------------------------*/
  /*--------------------------------FILE CLEANUP START------------------------------------*/
  fclose (gInputFile);
  /*--------------------------------FILE CLEANUP END--------------------------------------*/
  
  return 0;
}

// Define Functions
// File Handling
void usage (char *cmd) {
  fprintf (stderr, "usage: %s inputFileName\n", cmd);
  exit (EXIT_SUCCESS);
}

// Input Functions
int getNum (FILE *fp) {
  int num = 0;
  char str[gMaxLineLength] = { 0 };
  fgets (str, gMaxLineLength, fp);
  sscanf (str, "%d", &num);
  return num;
}
int getNumCases (FILE *fp) {
  return (getNum(fp));
}
void removeBlankLine (FILE *fp) {
  char str[gMaxLineLength] = { 0 };
  fgets (str, gMaxLineLength, fp);
}
int getNumShuffles (FILE* fp) {
  return (getNum(fp));
}
void getShuffle (int shuffle[gMaxNumShuffles][gNumCardsInDeck], int shuffleNum, FILE* fp) {
  char str[gMaxLineLength] = { 0 };
  fgets (str, gMaxLineLength, fp);
  str[strlen(str) + 1] = '/0';

  shuffle[shuffleNum][0] = atoi(strtok(str, " ")) - 1;
  for (int i = 1; i < gNumCardsInDeck; i++) {
    shuffle[shuffleNum][i] = atoi(strtok(NULL, " ")) - 1;
  }
}
void printShuffle (int shuffleNum, int shuffle[gMaxNumShuffles][gNumCardsInDeck]) {
  printf ("shuffle[%d] =", shuffleNum);
  for (int i = 0; i < gNumCardsInDeck; i++) {
    printf (" %d", shuffle[shuffleNum][i]);
  }
  printf ("\n\n");
}
int getShuffleNum (FILE* fp) {
  char str[gMaxLineLength] = { 0 };
  if (fgets(str, gMaxLineLength, fp) == NULL) {
    return (-1);
  }
  else {
    return (atoi(str) - 1);
  }
}

// Initialise and Shuffle Deck
void initDeck (int deck [gNumCardsInDeck]) {
  for (int i = 0; i < gNumCardsInDeck; i++) {
    deck[i] = i;
  }
}
void shuffleDeck (int shuffleNum, int shuffles[gMaxNumShuffles][gNumCardsInDeck], int deck[gNumCardsInDeck]) {
  int tempDeck[gNumCardsInDeck] = { 0 };
  for (int i = 0; i < gNumCardsInDeck; i++) {
    tempDeck[i] = deck[shuffles[shuffleNum][i]];
  }
  for (int i = 0; i < gNumCardsInDeck; i++) {
    deck[i] = tempDeck[i];
  }
}

// Card Translations
enum value getCardValue (int card) {
  return (card % gNumCardsPerSuit);
}
enum suit getCardSuit (int card) {
  if (card < gNumCardsPerSuit) {
    return (CLUBS);
  }
  else if (card < (gNumCardsPerSuit * 2)) {
    return (DIAMONDS);
  }
  else if (card < (gNumCardsPerSuit * 3)) {
    return (HEARTS);
  }
  else {
    return (SPADES);
  }
}

// Print Cards
void printValue (enum value value) {
  switch (value) {
    case TWO:
      printf ("Two");
      break;
    case THREE:
      printf ("Three");
      break;
    case FOUR:
      printf ("Four");
      break;
    case FIVE:
      printf ("Five");
      break;
    case SIX:
      printf ("Six");
      break;
    case SEVEN:
      printf ("Seven");
      break;
    case EIGHT:
      printf ("Eight");
      break;
    case NINE:
      printf ("Nine");
      break;
    case TEN:
      printf ("Ten");
      break;
    case JACK:
      printf ("Jack");
      break;
    case QUEEN:
      printf ("Queen");
      break;
    case KING:
      printf ("King");
      break;
    case ACE:
      printf ("Ace");
      break;
    default:
      printf ("Invalid Value [%d]", value);
      break;
  }
}
void printSuit (enum suit suit) {
  switch (suit) {
    case CLUBS:
      printf ("Clubs");
      break;
    case DIAMONDS:
      printf ("Diamonds");
      break;
    case HEARTS:
      printf ("Hearts");
      break;
    case SPADES:
      printf ("Spades");
      break;
    default:
      printf ("Invalid Suit");
      break;
  }
}
void printCard (int card) {
  printValue(getCardValue(card));
  printf (" of ");
  printSuit(getCardSuit(card));
  printf ("\n");
}
void printDeck (int deck [gNumCardsInDeck]) {
  for (int i = 0; i < gNumCardsInDeck; i++) {
    printCard (deck[i]);
  }
}