#include <stdio.h>

long long nadds = 0;

//iterativa com programacao dinamica
long long delannoy_iter(int m, int n) {
    long long D[m + 1][n + 1];  // matriz local

    //base cases
    for (int i = 0; i <= m; i++)
        D[i][0] = 1;
    for (int j = 0; j <= n; j++)
        D[0][j] = 1;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            D[i][j] = D[i-1][j] + D[i-1][j-1] + D[i][j-1];
            nadds += 2; // duas adições por elemento
        }
    }

    return D[m][n];
}

int main(void) {
    printf("%3s %20s %20s %20s\n", "i", "D(i,i)", "quoc", "nadds");
    long long prev = 0;

    for (int i = 0; i <= 25; i++) {
        nadds = 0;
        long long res = delannoy_iter(i, i);

        if (i == 0) {
            printf("%3d %20lld %20s %20lld\n", i, res, "-", nadds);
        } else {
            double q = (double)res / (double)prev;
            printf("%3d %20lld %20.6f %20lld\n", i, res, q, nadds);
        }
        prev = res;
    }

    return 0;
}
