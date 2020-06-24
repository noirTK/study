#include <iostream>
#include <array>
#include <algorithm>
using namespace std;
array<array<int, 3>, 1001> d, p;

int sol(const int n, const int t)
{
    if(n == 1) return p[1][t];
    if(d[n][t] != -1) return d[n][t];
    if(t == 0) d[n][t] = min({sol(n-1, 1), sol(n-1, 2)}) + p[n][t];
    if(t == 1) d[n][t] = min({sol(n-1, 0), sol(n-1, 2)}) + p[n][t];
    if(t == 2) d[n][t] = min({sol(n-1, 1), sol(n-1, 0)}) + p[n][t];
    return d[n][t];
}

int main()
{
    for(int i = 1; i < 1001; ++i) d[i].fill(-1);
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> p[i][0] >> p[i][1] >> p[i][2];
    cout << min({sol(n, 0), sol(n, 1), sol(n, 2)}) << '\n';
    return 0;
}