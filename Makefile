CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -I.
LDLIBS = -lcsfml-graphics -lcsfml-window -lcsfml-system -lm

all: testLine fractalTree levy

testLine: turtlec.c examples/testLine.c turtlec.h
	$(CC) $(CFLAGS) turtlec.c examples/testLine.c -o testLine $(LDLIBS)

fractalTree: turtlec.c examples/fractalTree.c turtlec.h
	$(CC) $(CFLAGS) turtlec.c examples/fractalTree.c -o fractalTree $(LDLIBS)
	
levy: turtlec.c examples/levy.c turtlec.h
	$(CC) $(CFLAGS) turtlec.c examples/levy.c -o levy $(LDLIBS)

clean:
	rm -f testLine fractalTree levy
