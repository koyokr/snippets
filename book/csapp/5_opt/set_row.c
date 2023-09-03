void set_row(double *a, double *b, long n) {
    long i, j;

    for (i = 0; i < n; i++) {
        long ni = n * i;
        for (j = 0; j < n; j++)
            a[ni+j] = b[j];
    }
}

