#include "csapp.h"

static char *mem_heap;
static char *mem_brk;
static char *mem_max_addr;

static char *mem_init(void)
{
	mem_heap = Malloc(MAX_HEAP);
	mem_brk = mem_heap;
	mem_max_addr = mem_heap + MAX_HEAP;
}

void *mem_sbrk(int incr)
{
	char *old_brk = mem_brk;

	if ((incr < 0) || ((mem_brk + incr) > mem_max_addr)) {
		errno = ENOMEM;
		fprintf(stderr, "ERROR: mem_sbrk failed. Ran out of memory...\n");
		return (void *)-1;
	}
	mem_brk += incr;
	return old_brk;
}
