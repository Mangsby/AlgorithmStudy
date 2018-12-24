#include <iostream>
#include <stack>
#include <string>
#include <cctype>

int tokenize(char c)
{
	switch(c)
	{
	case '(': return -1;
	case ')': return -11;
	case '[': return -2;
	case ']': return -12;
	}
	return 0;
}

int main()
{
	std::string input;
	std::cin >> input;

	std::stack<int> stack;
	for(const auto& it : input)
	{
		int score = 0;
		switch(it)
		{
		case ')':
			score = 2;
			break;
		case ']':
			score = 3;
			break;
		default:
			stack.push(tokenize(it));
			break;
		}

		if(score != 0)
		{
			int sum = 0;
			char part = (it == ')' ? '(' : '[');
			while(!stack.empty())
			{
				if(stack.top() > 0)
				{
					sum += stack.top();
					stack.pop();
				}
				else if(stack.top() == tokenize(part))
				{
					if(sum == 0)
					{
						stack.pop();
						stack.push(score);
					}
					else
					{
						stack.pop();
						stack.push(score*sum);
					}
					break;
				}
				else
				{
					std::cout << "0\n";
					return 0;
				}
			}
			if(stack.empty())
			{
				std::cout << "0\n";
				return 0;
			}

		}
			
	}
	int answer = 0;
	while(!stack.empty())
	{
		if(stack.top() < 0)
		{
			std::cout << "0\n";
			return 0;
		}
		answer += stack.top();
		stack.pop();
	}
	std::cout << answer << '\n';
	return 0;
}
