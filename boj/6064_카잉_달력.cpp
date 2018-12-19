//6064: 카잉 달력
#include <iostream>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;
	while(t--)
	{
		int m, n, x, y;
		std::cin >> m >> n >> x >> y;

		bool ok = false;
		for(int i=x; i<=m*n; i+=m)
		{
			if(i % n == y || (i % n == 0 && n == y))
			{
				std::cout << i << '\n';
				ok = true;
				break;
			}
		}
		if(!ok) std::cout << "-1\n";
	}
	return 0;
}
