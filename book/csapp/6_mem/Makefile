CC = gcc
CFLAGS = -W -Wall -mavx2 -O2
TARGETS = dotprod mmm productarray3d.s sumarray.s


all: $(TARGETS)


dotprod: dotprod.s
	$(CC) -o $@ $^

mmm: mmm.s
	$(CC) -o $@ $^


dotprod.s: dotprod.c
	$(CC) $(CFLAGS) -S $^

mmm.s: mmm.c
	$(CC) $(CFLAGS) -S $^

productarray3d.s: productarray3d.c
	$(CC) $(CFLAGS) -S $^

sumarray.s: sumarray.c
	$(CC) $(CFLAGS) -S $^


clean:
	rm -f $(TARGETS) *.s
