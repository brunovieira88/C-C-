#include <stdio.h>
long long ncalls = 0;
long long nadds = 0;
long long delannoy(int m, int n){
    ncalls++;
    if(n == 0 || m == 0){
        return 1;
    }
    nadds +=2;
    return delannoy(m-1,n) + delannoy(m-1,n-1) + delannoy(m, n-1);
}


int main(void){
    printf("%3s %12s %12s %12s %12s\n", "i", "D(i,i)", "quoc", "ncalls", "nadds");
    long long prev = 0;
    for(int i = 0; i <= 13; i++){
        ncalls = 0;
        nadds = 0;
        long long res = delannoy(i, i);
        if(i == 0){
            printf("%3d %12lld %12s %12lld %12lld\n", i, res, "-", ncalls, nadds);
        } else {
            double q = (double)res / (double)prev;
            printf("%3d %12lld %12.6f %12lld %12lld\n", i, res, q, ncalls, nadds);
        }
        prev = res;
    }
    return 0;
}
