#include <iostream>
#include <array>

using namespace std;
array<array<long long, 2>, 91> d;

int main()
{
    int n;
    cin >> n;
    d[1][0] = 0;
    d[1][1] = 1;
    for(int i = 2; i < 91; ++i)
    {
        for(int j = 0; j < 2; ++j)
        {
            if(j == 1) d[i][j] = d[i-1][0];
            else d[i][j] = d[i-1][0] + d[i-1][1];
        }
    }
    cout << d[n][0] + d[n][1] << '\n';
    return 0;
}