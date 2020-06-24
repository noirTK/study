#include <iostream>
#include <array>

using namespace std;
const int mod = 10007;
array<array<int, 10>, 1001> d;

int sol(const int n, const int t)
{
    if(n == 1) return 1;
    if(d[n][t] != -1) return d[n][t];
    d[n][t] = 0;
    for(int j = 0; j <= t; ++j)
    {
        d[n][t] += sol(n-1,t-j);
        d[n][t] %= mod;
    }
    return d[n][t];
}
int main()
{
    for(int i = 1; i < 1001; ++i) d[i].fill(-1);
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 0; i < 10; ++i)
    {
        ans += sol(n,i);
        ans %= mod;
    }
    cout << ans << '\n';
    return 0;
}