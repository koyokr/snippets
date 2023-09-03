CC = gcc

TARGETS = intc intl intr
SOURCES = int.c mymalloc.c

all: $(TARGETS)

intc: $(SOURCES) malloc.h
	$(CC) -DCOMPILETIME -c mymalloc.c
	$(CC) -I. -o $@ int.c mymalloc.o

intl: $(SOURCES)
	$(CC) -DLINKTIME -c mymalloc.c
	$(CC) -c int.c
	$(CC) -Wl,--wrap,malloc -Wl,--wrap,free -o $@ int.o mymalloc.o

intr: $(SOURCES)
	$(CC) -DRUNTIME -shared -fpic -o mymalloc.so mymalloc.c -ldl
	$(CC) -o $@ int.c

clean:
	rm -f $(TARGETS) *.o *.so
