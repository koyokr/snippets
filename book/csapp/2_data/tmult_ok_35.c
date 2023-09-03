#include <assert.h>
#include <limits.h>

/* Determine whether arguments can be multiplied without overflow */
int tmult_ok(int x, int y) {
    int p = x*y;

    /* Either x is zero, or dividing p by x gives y */
    return !x || p/x == y;
}

int main() {
    assert(0 == tmult_ok(100, INT_MAX));
    assert(1 == tmult_ok(100, 100));
    assert(1 == tmult_ok(100, -100));
    assert(0 == tmult_ok(100, INT_MIN));

    assert(1 == tmult_ok(0, 100));
    assert(1 == tmult_ok(100, 0));
    return 0;
}
