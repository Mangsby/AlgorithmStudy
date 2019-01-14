#include <iostream>

long long cache[3000][3000];

long long BinomialCoefficient(int n, int k)
{
	if(k < 0 || k > n) return 0;
	if(n == 1) return 1;
	
	if(cache[n][k])
		return cache[n][k];

	return cache[n][k] = 
		BinomialCoefficient(n-1, k-1) + 
		BinomialCoefficient(n-1, k);
}

int main()
{
	while(1)
	{
	int n, k;
	std::cin >> n >> k;
	if(n == 0 && k == 0) break;
	std::cout << BinomialCoefficient(n, k) << '\n';
	}
	return 0;
}
