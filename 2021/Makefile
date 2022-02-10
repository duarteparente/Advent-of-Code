CC = gcc
CFLAGS = -Wall -Wextra -g

INCLUDES = -Iinclude
LIBS = -lm

SRC = $(wildcard src/*.c)

MAIN = aoc21

all:	$(MAIN)

$(MAIN):	$(SRC)
		$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(SRC) $(LIBS)

clean:
		$(RM) $(MAIN)

run:
		./$(MAIN)

