#include <assert.h>
#include <limits.h>

/* Determine whether arguments can be added without overflow */
int tadd_ok(int x, int y) {
    int sum = x + y;
    return (sum-x == y) && (sum-y == x);
}

int main() {
    assert(0 == tadd_ok(100, INT_MAX));
    assert(1 == tadd_ok(100, -50));
    assert(1 == tadd_ok(-100, 50));
    assert(0 == tadd_ok(-100, INT_MIN));
    return 0;
}
