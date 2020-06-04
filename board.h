#ifndef  _BOARD_H_
#define  _BOARD_H_

#include <stdlib.h>
#include <stdbool.h>

enum cellState_e {empty=0, ship=1, hit=2, miss=3};
typedef enum cellState_e cellState_t;

typedef struct board_s * board_t;

board_t makeBoard(unsigned nRows, unsigned nCols);
void delBoard(board_t board);

cellState_t getCell(board_t board, unsigned row, unsigned col);
unsigned getBoardRows(board_t board);
unsigned getBoardCols(board_t board);
int shipCells(board_t board);

void putShip(board_t board, unsigned shipLength, bool isHorizontal, unsigned topRow, unsigned leftCol);
bool hitCell(board_t board, unsigned row, unsigned col);
void markHit(board_t board, unsigned row, unsigned col);

#endif //_BOARD_H_