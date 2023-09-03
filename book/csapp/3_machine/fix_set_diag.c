#define N 32
typedef int fix_matrix[N][N];

void fix_set_diag(fix_matrix A, int val) {
    for (long i = 0; i < N; i++)
        A[i][i] = val;
}
