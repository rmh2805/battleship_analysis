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

testDisp: testDisp.o board.o
	$(CC) $(CFLAGS) $(CDEBUGFLAGS) -o $@ $^ $(CLIBS)
	$(ECHO)

#
#				Object Files
#
%.o: %.c
	$(CC) $(CFLAGS) $(CDEBUGFLAGS) -c -o $@ $^

#
#				Misc Commands
#
clean:
	-rm *.o

realclean: clean
	-rm testBoard