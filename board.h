#ifndef  _BOARD_H_
#define  _BOARD_H_

#include <stdlib.h>
#include <stdbool.h>

enum boardState_e {empty=0, ship=1, hit=2, miss=3};
typedef enum boardState_e boardstate_t;

typedef struct board_s * board_t;

board_t makeBoard();
void delBoard(board_t board);


#endif //_BOARD_H_