#include <assert.h>
#include <limits.h>

/* Determine whether arguments can be added without overflow */
int tadd_ok(int x, int y) {
    int s = x + y;
    return (x <= 0 || y <= 0 || s > 0) &&
           (x >= 0 || y >= 0 || s < 0);
}

int main() {
    assert(0 == tadd_ok(INT_MAX, INT_MAX));
    assert(0 == tadd_ok(100, INT_MAX));
    assert(1 == tadd_ok(100, -50));
    assert(1 == tadd_ok(-100, 50));
    assert(0 == tadd_ok(-100, INT_MIN));
    assert(0 == tadd_ok(INT_MIN, INT_MIN));
    return 0;
}
