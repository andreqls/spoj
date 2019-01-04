// primelist[n]=value which determines immediately if n is prime, composite or untested.
// NOTE: Untested value might be replaced by a global maximum.
// Results: it is slower! Didn't expect that in a million years.

#include <iostream>

int MIN,MAX;
const int size_param=31623;
bool isPrime[size_param][size_param]; // isPrimef(x) <=> isPrime[x/size_param][x%size_param]

bool isPrimef(int candidate) {
    int i;
    if (candidate<2) return false;
    for (i=2;i*i<=candidate;i++)
        if (candidate % i == 0) return false;
    return true;
}

void updatePrimeList(int first, int last) {
    int candidate;
    for (candidate=first;candidate<=last;candidate++) {
        if (isPrimef(candidate)) isPrime[candidate/size_param][candidate%size_param]=true;
        else isPrime[candidate/size_param][candidate%size_param]=false;
    }
}

void listPrimes(int m, int n) {
    if (m<MIN) {
        updatePrimeList(m,MIN-1);
        MIN=m;
    }
    if (n>MAX) {
        updatePrimeList(MAX+1,n);
        MAX=n;
    }
}

void printPrimes(int m, int n) {
    int i;
    for (i=m;i<=n;i++)
        if (isPrime[i/size_param][i%size_param]) std::cout << i << std::endl;
    std::cout << std::endl;
}

int main(int argc, char **argv) {
    int t, n, m, i;
    bool first=true;
    for (std::cin >> t;t>0;t--) {
        std::cin >> m;
        std::cin >> n;
        if (!first) listPrimes(m,n);
        else {
            updatePrimeList(m,n);
            MIN=m;
            MAX=n;
            first=false;
        }
            printPrimes(m,n);
    }
    return 0;
}
