#include <iostream>
#include <stack>
#include <queue>

int main()
{
	int n;
	std::cin >> n;
	std::queue<int> queue;
	for(int i=0; i<n; i++)
	{
		int number;
		std::cin >> number;
		queue.push(number);
	}

	int index = 1;
	std::stack<int> stack;
	std::queue<char> answer;

	while(!queue.empty())
	{
		int number = queue.front();
		queue.pop();
		while(index <= number) 
		{
			stack.push(index++);
			answer.push('+');
		}
		if(stack.top() == number)
		{
			stack.pop();
			answer.push('-');
		}
		else
		{
			break;
		}
	}

	if(answer.size() == n*2)
	{
		while(!answer.empty())
		{
			std::cout << answer.front() << '\n';
			answer.pop();
		}
	}
	else
	{
		std::cout << "NO\n";
	}
	return 0;
}
