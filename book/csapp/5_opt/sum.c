long sum(long val[], long n, long j, long i) {
    long sum, up, down, left, right;

    long inj = i*n + j;
    up    = val[inj - n];
    down  = val[inj + n];
    left  = val[inj - 1];
    right = val[inj + 1];

    sum = up + down + left + right;
    return sum;
}
