#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> array(n);
    for(int i=0; i<n; i++)
    {
        std::cin >> array[i];
    }

    for (auto i = array.end()-1; i != array.begin(); i--)
    {
        for(auto j = array.begin(); j != i; j++)
        {
            if(*j > *(j+1))
            {
                std::swap(*j, *(j+1));
            }
        }
    }

    for (const auto& it : array)
    {
        std::cout << it << '\n';
    }

    return 0;
}
