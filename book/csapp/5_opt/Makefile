CC = gcc
CFLAGS = -W -Wall -mavx2 -S
TARGETS = lower.s set_row.s simd.s sum.s sum_rows.s vec.s


all: $(TARGETS)


lower.s: lower.c
	$(CC) $(CFLAGS) -O1 $<

set_row.s: set_row.c
	$(CC) $(CFLAGS) -O1 $<

simd.s: simd.c vec.h
	$(CC) $(CFLAGS) -O3 $<

sum.s: sum.c
	$(CC) $(CFLAGS) -O1 $<

sum_rows.s: sum_rows.c
	$(CC) $(CFLAGS) -O1 $<

vec.s: vec.c vec.h
	$(CC) $(CFLAGS) -O1 $<


clean:
	rm -f $(TARGETS)
