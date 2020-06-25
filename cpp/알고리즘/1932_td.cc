#include <iostream>
#include <array>
#include <algorithm>
using namespace std;
array<array<int, 501>, 501> d, p;

int sol(const int n, const int t)
{
    if(n == 1) return p[1][1];
    if(d[n][t] != -1) return d[n][t];
    if(t == 1) d[n][t] = sol(n-1, 1) + p[n][1];
    if(t == n) d[n][t] = sol(n-1, n-1) + p[n][n];
    else d[n][t] = max({sol(n-1, t-1), sol(n-1, t)}) + p[n][t];
    return d[n][t];
}

int main()
{
    for(int i = 1; i < 501; ++i) d[i].fill(-1);
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= i; ++j) cin >> p[i][j];
    }
    int ans;
    for(int i = 1; i <= n; ++i) if(i == 1 || ans < sol(n, i)) ans = sol(n, i);
    cout << ans << '\n';
    return 0;
}