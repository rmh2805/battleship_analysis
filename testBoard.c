#include <stdio.h>
#include <stdlib.h>

#include "board.h"

#define kEmptyChar ' '
#define kHitChar '*'
#define kMissChar '\''
#define kShipChar '#'

void printBoard(board_t board) {
    if(board == NULL) {
        return;
    }
    
    unsigned nRows = getBoardRows(board);
    unsigned nCols = getBoardCols(board);

    printf("\t\t+");
    for (unsigned col = 0; col < nCols; col++) {
        printf("-");
    }
    printf("+\n");

    for(unsigned row = 0; row < nRows; row++) {
        printf("\t\t|");
        for(unsigned col = 0; col < nCols; col++) {
            cellState_t cell = getCell(board, row, col);
            char toPrint = kEmptyChar;
            
            switch (cell){
            case hit:
                toPrint = kHitChar;
                break;
            case miss:
                toPrint = kMissChar;
                break;
            case ship:
                toPrint = kShipChar;
                break;
            default:
                break;
            }

            printf("%c", toPrint);
        }
        printf("|\n");
    }

    printf("\t\t+");
    for (unsigned col = 0; col < nCols; col++) {
        printf("-");
    }
    printf("+\n");
}

int main() {
    board_t board = makeBoard(10, 10);
    if(board == NULL) {
        fprintf(stderr, "Failed to allocate board. Exiting");
        return EXIT_FAILURE;
    }

    putShip(board, 5, true, 0, 0);
    bool firstHit = hitCell(board, 0, 0);
    bool secondHit = hitCell(board, 1, 0);
    printBoard(board);
    if(firstHit) {
        printf("First hit successful\n");
    }
    if(secondHit) {
        printf("Second hit successful\n");
    }

    return EXIT_SUCCESS;
}