#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "board.h"
#include "boardDisp.h"

int main () {
    board_t board = makeBoard(10, 10);
    if(board == NULL) {
        fprintf(stderr, "Failed to allocate a board. Sigining off.");
        return EXIT_FAILURE;
    }

    putShip(board, 5, false, 0, 0);
    putShip(board, 4, false, 0, 1);
    putShip(board, 3, false, 0, 2);
    putShip(board, 3, true, 0, 3);
    putShip(board, 2, true, 1, 3);

    if(!startDisp(10, 20)) {
        return EXIT_FAILURE;
    }
    

    stopDisp();
    return EXIT_SUCCESS;
}
