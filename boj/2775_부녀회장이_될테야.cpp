//2775: 부녀회장이 될테야
#include <iostream>

int main()
{
    int table[15][15] = {{0}};
    table[0][1] = 1;
    for(int i=2; i<=14; i++) table[0][i] = table[0][i-1] + i;
    for(int i=1; i<=14; i++)
    {
        for(int j=1; j<=14; j++)
        {
            table[i][j] = table[i][j-1] + table[i-1][j];
        }
    }

    int t;
    std::cin >> t;
    while(t--)
    {
        int k, n;
        std::cin >> k >> n;
        std::cout << table[k][n] - table[k][n-1] << '\n';
    }
    return 0;
}
