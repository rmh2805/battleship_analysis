#include "board.h"

struct board_s {
    boardstate_t** data;
};


board_t makeBoard() {
    return NULL;
}

void delBoard(board_t board) {
    if(board == NULL)
        return;
    
    if(board->data != NULL)
        free(board->data);
    
    free(board);

}