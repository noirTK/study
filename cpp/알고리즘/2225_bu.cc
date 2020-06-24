#include <iostream>
#include <array>

const long long mod = 1000000000LL;
using namespace std;
array<array<long long, 201>, 201> d;
int main()
{
    int n, k;
    cin >> n >> k;
    d[0][0] = 1LL;
    for(int i = 0; i <= n; ++i)
    {
        for(int l = 1; l <= k; ++l)
        {
            for(int j = 0; j <= i; ++j)
            {
                d[i][l] += d[i-j][l-1];
            }
            d[i][l] %= mod;
        }
    }
    cout << d[n][k] << '\n';
    return 0;
}