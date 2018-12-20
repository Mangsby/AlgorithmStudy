#include <iostream>
#include <vector>
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::vector<int> array(10001,0);
	int n;
	std::cin >> n;
	
	for(int i=0; i<n; i++)
	{
		int number;
		std::cin >> number;
		array[number]++;
	}

	for(int i=1; i<=10000; i++)
	{
		for(int j=0; j<array[i]; j++)
		{
			std::cout << i << '\n';
		}
	}
	return 0;
}
