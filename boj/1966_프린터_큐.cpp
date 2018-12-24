#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	
	int t;
	std::cin >> t;
	while(t--)
	{
		int n, m;
		std::cin >> n >> m;
		
		std::vector<int> printerQueue;
		for(int i=0; i<n; i++)
		{
			int input;
			std::cin >> input;
			printerQueue.push_back(input);
		}

		int head = 0;
		int answer = 1;
		int max = *std::max_element(printerQueue.begin(), printerQueue.end());

		constexpr int DELETED = -1;
		while(1)
		{
			if(printerQueue[head] != DELETED &&
			   printerQueue[head] == max)
			{
				if(head == m) break;
				printerQueue[head] = DELETED;
				answer++;
				max = *std::max_element(printerQueue.begin(), printerQueue.end());
			}
			head = (head + 1) % n;
		}

		std::cout << answer << '\n';
	}
	return 0;
}
