CC = gcc
CFLAGS = -W -Wall -mavx2 -Og -S
SOURCES = *.c

all: $(SOURCES)
	$(CC) $(CFLAGS) $?

clean:
	rm *.s
