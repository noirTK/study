/*
https://www.acmicpc.net/problem/11054
11054 다이나믹 문제 풀이 Top Down
1. solu(n) : n번째 수를 선택할 경우, 증가하는 수열의 길이
   u[n] = 1
   (p[L] < p[n]) solu(n) = max(sol(L)+1, u[n]) (1 <= L && L < n)
2. sold(n, last) : 마지막부터 n번째까지의 수열 중에서 n번째 수를 선택할 경우, 감소하는 수열의 길이
   d[n] = 1
   (p[L] < p[n]) sold(n, last) = max(sold(i, last)+1, d[n]) (n < L && L <= last)
ans = solu(n) + sold(n, last) - 1
*/

#include <iostream>
#include <array>

using namespace std;
array<int, 1001> d, u, p;

int solu(const int n)
{
    if(u[n] != -1) return u[n];
    u[n] = 1;
    for(int i = 1; i < n; ++i)
    {
        if(p[i] < p[n]) u[n] = max(solu(i)+1, u[n]);
    }
    return u[n];
}

int sold(const int n, const int last)
{
    if(d[n] != -1) return d[n];
    d[n] = 1;
    for(int i = last; i > n; --i)
    {
        if(p[i] < p[n]) d[n] = max(sold(i, last)+1, d[n]);
    }
    return d[n];
}

int main()
{
    int n, ans;
    cin >> n;
    d.fill(-1);
    u.fill(-1);
    for(int i = 1; i <= n; ++i) cin >> p[i];
    for(int i = 1; i <= n; ++i) solu(i);
    for(int i = 1; i <= n; ++i) sold(i, n);
    ans = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(i == 1 || ans < d[i]+u[i]) ans = d[i]+u[i];
    }
    cout << ans-1 << '\n';
    return 0;
}