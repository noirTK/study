#include <iostream>
#include <array>

using namespace std;
array<array<long long, 10>, 101> d;
const long long mod = 1000000000LL;

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < 10; ++i) 
    {
        d[0][i] = 0;
        d[1][i] = (i == 0 ? 0 : 1);
    }
    for(int i = 2; i <= n; ++i)
    {
        for(int j = 0; j < 10; ++j)
        {
            d[i][j] = 0;
            if(j - 1 >= 0) d[i][j] += d[i-1][j-1];
            if(j + 1 <= 9) d[i][j] += d[i-1][j+1];
            d[i][j] %= mod;
        }
    }
    long long ans = 0;
    for(int i = 0; i < 10; ++i) ans += d[n][i];
    cout << ans % mod << '\n';
    return 0;
}