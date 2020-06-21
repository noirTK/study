#include <iostream>
#include <array>

using namespace std;
array<array<long long, 4>, 100001> d;
const long long mod = 1000000009LL;

long long sol(const int n, const int t)
{
    if(d[n][t] != -1) return d[n][t];
    if(n >= 1 && t == 1)
    {
        if(n == 1) d[n][1] = 1;
        else d[n][1] = sol(n-1, 2) + sol(n-1, 3);
        return d[n][t] %= mod;
    }
    if(n >= 2 && t == 2)
    {
        if(n == 2) d[n][t] = 1;
        else d[n][2] = sol(n-2, 1) + sol(n-2, 3);
        return d[n][t] %= mod;
    }
    if(n >= 3 && t == 3)
    {
        if(n == 3) d[n][t] = 1;
        else d[n][3] = sol(n-3, 1) + sol(n-3, 2);
        return d[n][t] %= mod;
    }
    d[n][t] = 0;
    return d[n][t];
}

int main()
{
    for(int i = 1; i < 100001; ++i) d[i].fill(-1);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        cout << (sol(n, 1) + sol(n, 2) + sol(n, 3)) % mod << '\n';
    }
    return 0;
}