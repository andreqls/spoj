// A simple "Sieve of Erathostenes" implementation of PRIME1 from SPOJ.

#include <iostream>

int T,N;
int primelist[10][100000];

bool isPrime(int candidate) {
    int i;
    if (candidate<2) return false;
    for (i=2;i*i<=candidate;i++)
        if (candidate % i == 0) return false;
    return true;
}

int main(int argc, char **argv) {
    int t, n, m, i;
    std::cin >> t;
    for (T=0;t>0;T++) {
        std::cin >> m;
        std::cin >> n;
        N=0;
        for (;m<=n;m++)
            if (isPrime(m)) primelist[T][N++]=m;
        for (i=0;i<N;i++)
            std::cout << primelist[T][i] << std::endl;
        t--;
        std::cout << std::endl;
    }
    return 0;
}