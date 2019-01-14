#include <iostream>

int cache[1001][1001];

int BinomialCoefficient(int n, int k)
{
    if(k < 0 || k > n) return 0;
    if(n == 1) return 1;
    
    if(cache[n][k])
        return cache[n][k];

    return cache[n][k] = (
        BinomialCoefficient(n-1, k-1) + 
        BinomialCoefficient(n-1, k)) % 10007;
}

int main()
{
    int n, k;
    std::cin >> n >> k;
    std::cout << BinomialCoefficient(n, k) << '\n';
    return 0;
}
