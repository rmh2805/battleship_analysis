#include "board.h"

struct board_s {
    cellState_t** data;
    unsigned nRows;
    unsigned nCols;
    int shipTiles;
};

board_t makeBoard(unsigned nRows, unsigned nCols) {
    // Ensure that parameters are legal
    if (nRows == 0 || nCols == 0) {
        return NULL;
    }
    
    // Allocate the board array, exit on failure
    board_t board = malloc(sizeof(struct board_s));
    if (board == NULL) {
        return NULL;
    }
    
    // Set the static members of the board array
    board->nRows = nRows;
    board->nCols = nCols;
    board->shipTiles = 0;

    // Allocate the row array, exit on failure
    board->data = calloc(nRows, sizeof(cellState_t*));
    if (board->data == NULL) {
        delBoard(board);
        return NULL;
    }

    // Allocate an array for each row, exit on failure
    for (unsigned i = 0; i < nRows; i++) {
        board->data[i] = calloc(nCols, sizeof(cellState_t));
        if (board->data[i] == NULL) {
            delBoard(board);
            return NULL;
        }
    }

    // If the struct was initialized properly, set all spaces to empty
    for(unsigned row = 0; row < nRows; row++) {
        for(unsigned col = 0; col < nCols; col++) {
            board->data[row][col] = empty;
        }
    }

    // Return the initialized board
    return board;
}

void delBoard(board_t board) {
    if (board == NULL) {
        return;
    }
    
    if (board->data != NULL) {
        for(unsigned row = 0; row < board->nRows; row++) {
            if(board->data[row] != NULL)
                free(board->data);
        }

        free(board->data);
    }
    
    free(board);
}

cellState_t getCell(board_t board, unsigned row, unsigned col) {
    if(board == NULL) {
        return empty;
    }
    if(row >= board->nRows || col >= board->nCols) {
        return empty;
    }

    return board->data[row][col];
}

unsigned getBoardRows(board_t board) {
    if(board == NULL)
        return 0;
    return board->nRows;
}

unsigned getBoardCols(board_t board) {
    if(board == NULL)
        return 0;
    return board->nCols;
}

int shipCells(board_t board) {
    if(board == NULL)
        return 0;
    return board->shipTiles;
}

void putShip(board_t board, unsigned shipLength, bool isHorizontal, unsigned topRow, unsigned leftCol) {
    if(board == NULL) {
        return;
    }
    if((isHorizontal && leftCol + shipLength > board->nCols) || (!isHorizontal && topRow + shipLength > board->nRows)) {
        return;
    }

    unsigned dRow = 0;
    unsigned dCol = 0;
    for (unsigned i = 0; i < shipLength; i++) {
        if(isHorizontal) {
            dCol = i;
        } else {
            dRow = i;
        }
        unsigned row = topRow + dRow;
        unsigned col = leftCol + dCol; 
        if(board->data[row][col] != empty) {
            return;
        }
    }

    for (unsigned i = 0; i < shipLength; i++) {
        if(isHorizontal) {
            dCol = i;
        } else {
            dRow = i;
        }
        unsigned row = topRow + dRow;
        unsigned col = leftCol + dCol; 
        board->data[row][col] = ship;
        board->shipTiles += 1;
    }
}

bool hitCell(board_t board, unsigned row, unsigned col) {
    if(board == NULL) {
        return false;
    }
    if(row >= board->nRows || col >= board->nCols) {
        return false;
    }

    bool wasHit = false;
    if(board->data[row][col] == ship) {
        wasHit = true;
        board->data[row][col] = hit;
        board->shipTiles -= 1;
    } else {
        board->data[row][col] = miss;
    }

    return wasHit;
}

void markHit(board_t board, unsigned row, unsigned col) {
    if(board == NULL) {
        return;
    }
    if(row >= board->nRows || col >= board->nCols) {
        return;
    }
    board->data[row][col] = hit;
}