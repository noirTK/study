#include <iostream>
#include <array>
#include <algorithm>
using namespace std;
array<array<int, 3>, 10001> d;
array<int, 10001> p;

int sol(const int n, const int t)
{
    if(n == 1) return (t == 1 ? p[1] : 0);
    if(d[n][t] != -1) return d[n][t];
    if(t == 0) d[n][t] = max({sol(n-1, 0), sol(n-1, 1), sol(n-1, 2)});
    if(t == 1) d[n][t] = sol(n-1, 0) + p[n];
    if(t == 2) d[n][t] = sol(n-1, 1) + p[n];
    return d[n][t];
}

int main()
{
    for(int i = 1; i < 10001; ++i) d[i].fill(-1);
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> p[i];
    cout << max({sol(n,2), sol(n,1), sol(n,0)}) << '\n';
    return 0;
}