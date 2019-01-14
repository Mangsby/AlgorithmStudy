//10250: ACM 호텔

#include <iostream>
#include <iomanip>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while(t--)
    {
        int h, w, n;
        std::cin >> h >> w >> n;
        
        int floor;
        int number;

        floor = n % h;
        if(floor == 0) floor = h;
        number = n / h;
        if(n % h != 0) number++;

        std::cout << floor << std::setw(2) << std::setfill('0') << number << '\n';
    }
    return 0;
}


