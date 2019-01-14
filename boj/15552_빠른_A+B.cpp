//15552: 빠른 A+B
#include <iostream>

int main()
{
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    int t;
    std::cin >> t;
    while(t--)
    {
        int a, b;
        std::cin >> a >> b;
        std::cout << a+b << '\n';
    }
    return 0;
}
