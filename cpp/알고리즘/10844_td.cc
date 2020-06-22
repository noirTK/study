#include <iostream>
#include <array>

using namespace std;
const long long mod = 1000000000LL;
array<array<long long, 10>, 101> d;

long long sol(const int n, const int t)
{
    if(n == 0) 
    {
        for(int i = 0; i < 10; ++i) d[0][i] = 0;
        return d[n][t];
    }
    if(n == 1)
    {
        d[1][0] = 0;
        for(int i = 1; i < 10; ++i) d[1][i] = 1;
        return d[n][t];
    }
    if(d[n][t] != -1) return d[n][t];

    if(t == 0) d[n][t] = sol(n-1, t+1);
    else if(t == 9) d[n][t] = sol(n-1, t-1);
    else d[n][t] = sol(n-1, t+1) + sol(n-1, t-1);

    d[n][t] %= mod;

    return d[n][t];
}
int main()
{
    long long ans = 0;
    for(int i = 1; i < 101; ++i) d[i].fill(-1);
    int n;
    cin >> n;
    for(int i = 0; i < 10; ++i)
    {
        ans += sol(n, i);
        ans %= mod;
    }
    cout << ans % mod << '\n';
    return 0;
}