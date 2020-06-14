#ifndef  _BOARD_DISP_H_
#define  _BOARD_DISP_H_

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include <curses.h>

#include "board.h"

bool startDisp(unsigned maxBoardWidth, unsigned maxBoardHeight);
void stopDisp();



#endif //_BOARD_DISP_H_