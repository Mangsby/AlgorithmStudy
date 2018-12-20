#include <iostream>
#include <vector>
#include <tuple>

std::tuple<int, int> Goldbach(const std::vector<bool>& isPrime, int n)
{
	int a, b;
	a = b = n/2;
	while(!isPrime[a] || !isPrime[b])
	{
		a--;
		b++;
	}
	
	return std::make_tuple(a, b);
}

int main()
{
	std::vector<bool> isPrime(10001, true);
	isPrime[0] = isPrime[1] = false;
			
	for(int i=2; i<=100; i++)
	{
		for(int j=i*2; j<=10000; j+=i)
		{
			isPrime[j] = false;
		}
	}
	
	int t;
	std::cin >> t;
	while(t--)
	{
		int n;
		std::cin >> n;
		int a, b;
		std::tie(a, b) = Goldbach(isPrime, n);
		std::cout << a << ' ' << b << '\n';
	}
	return 0;
}
