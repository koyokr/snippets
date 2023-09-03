#include <stdlib.h>

float dotprod(float x[8], float y[8]) {
    float sum = 0.f;
    int i;

    for (i = 0; i < 8; i++) {
        sum += x[i] * y[i];
    }
    return sum;
}

int main(int argc, char *argv[]) {
    int N;
    long count;

    if (argc & 2) {    
        N = atoi(argv[1]);
        count = argc == 3 ? atol(argv[2]) : 100000000;
    }
    else {
        return 1;
    }

    float x[N], y[N];
    while (count--) {
        dotprod(x, y);
    }

    return 0;
}
