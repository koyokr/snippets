int multcnt = 0;

void multvec(int *restrict x, int *restrict y,
             int *restrict z, int n) {
    int i;

    multcnt++;

    for (i = 0; i < n; i++)
        z[i] = x[i] * y[i];
}
