#include <iostream>
#include <array>
#include <algorithm>

using namespace std;
array<int, 10001> d, p;
int sol(const int n)
{
    if(n == 0) return 0;
    if(n == 1) return p[1];
    if(n == 2) return p[1] + p[2];
    if(d[n] != -1) return d[n];
    d[n] = max({sol(n-1), sol(n-2)+p[n], sol(n-3)+p[n-1]+p[n]});
    return d[n];
}

int main()
{
    for(int i = 1; i <= 10001; ++i) d.fill(-1);
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> p[i];
    cout << sol(n) << '\n';
    return 0;
}