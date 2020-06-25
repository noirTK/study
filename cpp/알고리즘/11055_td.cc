#include <iostream>
#include <array>
#include <algorithm>
using namespace std;
array<int, 1001> p, d;

int sol(const int n)
{
    if(n == 1) return p[n];
    if(d[n] != -1) return d[n];
    d[n] = p[n];
    for(int i = 1; i < n; ++i) if(p[n] > p[i]) d[n] = max({sol(i) + p[n], d[n]});
    return d[n];
}

int main()
{
    for(int i = 1; i < 1001; ++i) d.fill(-1);
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> p[i];
    int ans;
    for(int i = 1; i <= n; ++i) 
    if(i == 1 || ans < sol(i)) ans = sol(i);
    cout << ans << '\n';
    return 0;
}