#include <assert.h>
#include <limits.h>

/* Determine whether arguments can be added without overflow */
int uadd_ok(unsigned x, unsigned y) {
    unsigned s = x + y;
    return s >= x;
}

int main() {
    assert(1 == uadd_ok(100, 100));
    assert(0 == uadd_ok(100, UINT_MAX));
    assert(0 == uadd_ok(UINT_MAX, 100));
    return 0;
}

