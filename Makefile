#
#               Commands
#

# Compilers
CC=gcc

# Misc
ECHO=@echo

#
#               Misc Variables
#

# C Flags
CLIBS=-lm -lncurses
CFLAGS=-Wall -std=c99 -Wextra -pedantic
CDEBUGFLAGS=-ggdb

#
#               Main Targets
#

# Testing Files
testBoard: testBoard.o board.o
	$(CC) $(CFLAGS) $(CDEBUGFLAGS) -o testBoard $^ $(CLIBS)
	$(ECHO)

#
#				Object Files
#
testBoard.o: testBoard.c
	$(CC) $(CFLAGS) $(CDEBUGFLAGS) -c -o testBoard.o testBoard.c

board.o: board.c
	$(CC) $(CFLAGS) $(CDEBUGFLAGS) -c -o board.o board.c
