CC = gcc
CFLAGS = -W -Wall -Og
SOURCES = $(shell echo *.c)
TARGETS = $(SOURCES:.c=)

all: $(SOURCES)
	for target in $(TARGETS); do \
	$(CC) $(CFLAGS) -o $$target `echo $$target`.c; \
	done

clean:
	rm $(TARGETS)
