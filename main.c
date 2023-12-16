#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>
#include <sys/errno.h>


// Constants
const int gMaxLineLength = 162;
const int gNumCardsInDeck = 52;
const int gMaxNumShuffles = 100;

// Declare file handles
FILE *gInputFile;

// Declare Structures / Arrays
int gShuffleOrders[gMaxNumShuffles][gNumCardsInDeck];

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

  int numCases = getNumCases (gInputFile); printf ("numCases = %d\n", numCases);
  removeBlankLine (gInputFile);
  int numShuffles = getNumShuffles (gInputFile); printf ("numShuffles = %d\n", numShuffles);

  printf ("\n");
  for (int i = 0; i < numShuffles; i++) {
    getShuffle (gShuffleOrders, i, gInputFile);
    printShuffle(i, gShuffleOrders);
  }



  
  
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

  shuffle[shuffleNum][0] = atoi(strtok(str, " "));
  for (int i = 1; i < gNumCardsInDeck; i++) {
    shuffle[shuffleNum][i] = atoi(strtok(NULL, " "));
  }
}
void printShuffle (int shuffleNum, int shuffle[gMaxNumShuffles][gNumCardsInDeck]) {
  printf ("shuffle[%d] =", shuffleNum);
  for (int i = 0; i < gNumCardsInDeck; i++) {
    printf (" %d", shuffle[shuffleNum][i]);
  }
  printf ("\n\n");
}