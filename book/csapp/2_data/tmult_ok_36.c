#include <assert.h>
#include <stdint.h>
#include <limits.h>

int tmult_ok(int x, int y) {
    int64_t p = (int64_t)x * y;
    return p <= INT_MAX && p >= INT_MIN;
    // return p == (int)p;
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
