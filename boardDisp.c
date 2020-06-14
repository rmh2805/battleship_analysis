#include "boardDisp.h"

//=========================================<Module State>=========================================//
//Screen size Definitions
static unsigned dispRows = 0;
static unsigned dispCols = 0;

//Board Space Definitions
static unsigned boardCols = 0;
static unsigned boardRows = 0;

//Cell Definitions
#define kCellWidth 3
#define kCellHeight 2

//Screenspace definitions
#define kBoardHeight (kCellHeight * boardRows + (boardRows - 1))
#define kBoardWidth (kCellWidth * boardCols + (boardCols - 1))

#define kBoardDispHeight (3 + kBoardHeight)
#define kBoardDispWidth (3 + kBoardWidth)

#define kScreenSpaceHeight kBoardDispHeight
#define kScreenSpaceWidth kBoardDispWidth



//======================================<Main Functionality>======================================//
bool startDisp(unsigned maxBoardWidth, unsigned maxBoardHeight) {
    //Save provided board dimensions to module variables
    boardCols = maxBoardWidth;
    boardRows = maxBoardHeight;

    //Start up the ncurses environment and grab window dimensions
    initscr();
    getmaxyx(stdscr, dispRows, dispCols);

    if(dispRows < kScreenSpaceHeight || dispCols < kScreenSpaceWidth) {
        stopDisp();
        fprintf(stderr, "Your terminal window is too small (%d x %d). It must be at least %d rows by %d cols\n",
            dispRows, dispCols, kScreenSpaceHeight, kScreenSpaceWidth);
        return false;
    }

    if(!has_colors()) {
        stopDisp();
        fprintf(stderr, "Your terminal window does not support color. Shutting down\n");
        return false;
    }

    addstr("foobar");
    return true;
}


void stopDisp() {
    endwin();
}