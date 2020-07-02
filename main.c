// Alejandro Bustelo, 2020

#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAX_X 5
#define MAX_Y 5

char debug = 0;

// int Universe[MAX_X][MAX_Y];
int thisTurn[MAX_Y][MAX_X] = {
    {0,1,0,0,0},
    {0,0,1,0,0},
    {1,1,1,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0}
}; // a glider

int nextTurn[MAX_Y][MAX_X] = {
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0}
};

void advanceTurn();
void computeTurn();
void drawScreen();
void printDebugLog(char *log);

int main() {
    drawScreen();
    while(1) {
        sleep(2);
        computeTurn();
        drawScreen();
    }
    return 0;
}

void printDebugLog(char *log) {
    if (debug) {
        printf("%s", log);
    }
}

void advanceTurn() {
    for (int i = 0; i < MAX_Y; i++) {
        for (int j = 0; j < MAX_X; j++) {
            thisTurn[i][j] = nextTurn[i][j];
        }
    }
}

void computeTurn() {
    int liveNeighbors;
    int isAlive;
    for (int i = 0; i < MAX_Y; i++) {
        for (int j = 0; j < MAX_X; j++) {
            liveNeighbors = 0;
            isAlive = thisTurn[i][j];
            if (i > 0) { // check non-corner/edge cases first
                if (thisTurn[i-1][j]) {
                    liveNeighbors++;
                    //printf("%c", 'a');
                    printDebugLog("a");
                }
                if (j > 0) {
                    if (thisTurn[i-1][j-1]) {
                        liveNeighbors++;
                        //printf("%c", 'b');
                        printDebugLog("b");
                    }
                }
                if (j < MAX_X - 1) {
                    if (thisTurn[i-1][j+1]) {
                        liveNeighbors++;
                        //printf("%c", 'c');
                        printDebugLog("c");
                    }
                }
            }
            if (i < MAX_Y - 1) {
                if (thisTurn[i+1][j]) {
                    liveNeighbors++;
                    //printf("%c", 'd');
                    printDebugLog("d");
                }
                if (j > 0) {
                    if (thisTurn[i+1][j-1]) {
                        liveNeighbors++;
                        //printf("%c", 'e');
                        printDebugLog("e");
                    }
                }
                if (j < MAX_X - 1) {
                    if (thisTurn[i+1][j+1]) {
                        liveNeighbors++;
                        //printf("%c", 'f');
                        printDebugLog("f");
                    }
                }
            }
            if (j > 0) {
                if (thisTurn[i][j-1]) {
                    liveNeighbors++;
                    //printf("%c", 'g');
                    printDebugLog("g");
                }
            }
            if (j < MAX_X - 1) {
                if (thisTurn[i][j+1]) {
                    liveNeighbors++;
                    //printf("%c", 'h');
                    printDebugLog("h");
                }
            }
            //printf("%c", '\n');
            printDebugLog("\n");
            if (debug) {
                printf("Cell (%d,%d), isAlive value %d, neighbors %d \n", j, i, isAlive, liveNeighbors);
            }
            if ( ( liveNeighbors == 2 || liveNeighbors == 3) && isAlive ) {
                nextTurn[i][j] = isAlive;
            } else if ( liveNeighbors == 3 && isAlive == 0 ) {
                nextTurn[i][j] = 1;
            } else {
                nextTurn[i][j] = 0;
            }
        }
    }
    advanceTurn();
}

void drawScreen() {
    for (int i = 0; i < MAX_Y; i++) {
        for (int j = 0; j < MAX_X; j++) {
            printf("%d, ", thisTurn[i][j]);
        }
        printf("%c", '\n');
    }
    printf("%c", '\n');
    printf("%c", '\n');
    printf("%c", '\n');
}
