#include <stdio.h>
long long ncalls = 0;
long long nadds = 0;
long long memo[100][100];


long long delannoy(int m, int n){
    ncalls++;
    if(n == 0 || m == 0){
        return 1;
    }
    if (memo[m][n] != -1){
        return memo[m][n];
    }

    nadds +=2;
    memo[m][n] = delannoy(m-1,n) + delannoy(m-1,n-1) + delannoy(m, n-1);
    return memo[m][n];
}


int main(void) {
    printf("%3s %20s %20s %20s %20s\n", "i", "D(i,i)", "quoc", "ncalls", "nadds");

    for (int i = 0; i <= 25; i++) {
        //inicialize array globais
        for (int a = 0; a <= i; a++)
            for (int b = 0; b <= i; b++)
                memo[a][b] = -1;

        nadds = 0;
        ncalls = 0;

        long long res = delannoy(i, i);

        if (i == 0) {
            printf("%3d %20lld %20s %20lld %20lld\n", i, res, "-", ncalls, nadds);
        } else {
            static long long prev = 1;
            double q = (double)res / (double)prev;
            printf("%3d %20lld %20.6f %20lld %20lld\n", i, res, q, ncalls, nadds);
            prev = res;
        }
    }

    return 0;
}
