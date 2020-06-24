#include <iostream>
#include <array>

const int mod = 10007;
using namespace std;
array<array<int, 10>, 1001> d;
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < 10; ++i) d[1][i] = 1;
    for(int i = 2; i <= n; ++i)
    {
        for(int k = 0; k < 10; ++k)
        {
            for(int j = 0; j <= k; ++j)
            {
                d[i][k] += d[i-1][k-j];
                d[i][k] %= mod;
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < 10; ++i)
    {
        ans += d[n][i];
        ans %= mod;
    }
    cout << ans << '\n';
    return 0;
}