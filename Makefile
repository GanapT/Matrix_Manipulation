CC = gcc
CFLAGS = -Wall -Wextra

all: matrix

matrix: project2.c matrix.c
	$(CC) $(CFLAGS) -o matrix project2.c matrix.c

clean:
	rm -f matrix
