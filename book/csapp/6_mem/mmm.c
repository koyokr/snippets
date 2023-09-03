void mmm(int n,
         double a[restrict][n],
         double b[restrict][n],
         double c[restrict][n])
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                c[i][j] += a[i][k] * b[k][j];
}

void mmm2(int n,
          double a[restrict][n],
          double b[restrict][n],
          double c[restrict][n])
{
    int B = 16;
    for (int i = 0; i < n; i += B)
        for (int j = 0; j < n; j += B)
            for (int k = 0; k < n; k += B)
                for (int x = i; x < i + B; x++)
                    for (int y = j; y < j + B; y++)
                        for (int z = k; z < k + B; z++)
                            c[x][y] += a[x][z] * b[z][y];
}

#define CACHE_SIZE      32 * 1024
#define CACHE_LINE_SIZE 64

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN 1024
typedef double matrix[LEN][LEN], (*pmatrix)[LEN];


double test(void (f)(int n,
                     double [][n],
                     double [][n],
                     double [][n]))
{
    int n = LEN;
    pmatrix a = aligned_alloc(CACHE_LINE_SIZE, sizeof(matrix));
    pmatrix b = aligned_alloc(CACHE_LINE_SIZE, sizeof(matrix));
    pmatrix c = aligned_alloc(CACHE_LINE_SIZE, sizeof(matrix));

    struct timespec start, end;
    time_t sec;
    long int nsec;

    clock_gettime(CLOCK_MONOTONIC, &start);
    f(n, a, b, c);
    clock_gettime(CLOCK_MONOTONIC, &end);

    sec = end.tv_sec - start.tv_sec;
    nsec = end.tv_nsec - start.tv_nsec;
    if (nsec < 0) nsec += 1000000000;
    printf("%ld.%09ld\n", sec, nsec);
    
    free(a);
    free(b);
    free(c);
    return sec + nsec / 1000000000.0;
}

int main(void)
{
    int count = 10;
    double sum_s;

    printf("mmm2\n");
    sum_s = 0.0;
    for (int i = 0; i < count; i++)
        sum_s += test(mmm2);
    printf("average: %.9lf\n", sum_s / count);

    printf("mmm\n");
    sum_s = 0.0;
    for (int i = 0; i < count; i++)
        sum_s += test(mmm);
    printf("average: %.9lf\n", sum_s / count);

    return 0;
}

