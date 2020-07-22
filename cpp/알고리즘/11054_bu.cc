/*
https://www.acmicpc.net/problem/11054
11054 다이나믹 문제 풀이 Bottom Up
1. u[n] : n번째 수를 선택할 경우, 증가하는 수열의 길이
   u[n] = 1
   (p[L] < p[n]) u[n] = max(u[L]+1, u[n]) (1 <= L && L < n)
2. sold(n, last) : 마지막부터 n번째까지의 수열 중에서 n번째 수를 선택할 경우, 감소하는 수열의 길이
   d[n] = 1
   (p[L] < p[n]) d[n] = max(d[i]+1, d[n]) (n < L && L <= last)
ans = u[n] + d[n] - 1
*/

#include <iostream>
#include <array>
#include <algorithm>

using namespace std;
array<int, 1001> d, u, p;

int main()
{
    int n, ans;
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> p[i];
    for(int i = 1; i <= n; ++i)
    {
        u[i] = 1;
        for(int l = 1; l < n; ++l)
        {
            if(p[i] > p[l]) u[i] = max(u[l]+1, u[i]);
        }
    }
    for(int i = n; i >= 1; --i)
    {
        d[i] = 1;
        for(int l = n; l > i; --l)
        {
            if(p[i] > p[l]) d[i] = max(d[l]+1, d[i]);
        }
    }
    ans = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(i == 1 || ans < d[i] + u[i]) ans = d[i] + u[i];
    }
    cout << ans - 1 << '\n';
    return 0;
}