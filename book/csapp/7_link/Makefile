CC = gcc
AR = ar
CFLAGS = -W -Wall -O2

TARGETS = prog prog2c prog2l prog2r foobar3 foobar4 foobar5 foobar6

VECTOR_LIBRARY = libvector
VECTOR_SOURCES = addvec.c multvec.c
VECTOR_OBJECTS = addvec.o multvec.o


all: $(TARGETS)


prog: main.c sum.c
	$(CC) $(CFLAGS) -o $@ $^

prog2c: main2.c vector.h $(VECTOR_LIBRARY).a
	$(CC) $(CFLAGS) -static -o $@ main2.c -L. -lvector

prog2l: main2.c vector.h $(VECTOR_LIBRARY).so
	$(CC) $(CFLAGS) -o $@ main2.c ./$(VECTOR_LIBRARY).so
	
prog2r: dll.c
	$(CC) $(CFLAGS) -rdynamic -o $@ $^ -ldl


foobar3: foo3.c bar3.c
	$(CC) $(CFLAGS) -o $@ $^

foobar4: foo4.c bar4.c
	$(CC) $(CFLAGS) -o $@ $^

foobar5: foo5.c bar5.c
	$(CC) $(CFLAGS) -o $@ $^

foobar6: foo6.c bar6.c
	$(CC) $(CFLAGS) -o $@ $^


$(VECTOR_LIBRARY).a: $(VECTOR_OBJECTS)
	$(AR) rcs $@ $^

$(VECTOR_LIBRARY).so: $(VECTOR_SOURCES)
	$(CC) $(CFLAGS) -shared -fpic -o $@ $^

$(VECTOR_OBJECTS): $(VECTOR_SOURCES)
	$(CC) $(CFLAGS) -c $?


clean:
	rm -f $(TARGETS) *.o *.a *.so
