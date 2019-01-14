#include <iostream>

int BinomialCoefficient(int n, int k)
{
	if(k < 0 || k > n) return 0;
	if(n == 1) return 1;

	return 
		BinomialCoefficient(n-1, k-1) + 
		BinomialCoefficient(n-1, k);
}

int main()
{
	int n, k;
	std::cin >> n >> k;
	std::cout << BinomialCoefficient(n, k) << '\n';
	return 0;
}
