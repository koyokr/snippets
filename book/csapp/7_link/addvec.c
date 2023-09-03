int addcnt = 0;

void addvec(int *restrict x, int *restrict y,
            int *restrict z, int n) {
    int i;

    addcnt++;

    for (i = 0; i < n; i++)
        z[i] = x[i] + y[i];
}
