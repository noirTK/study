/*
https://www.acmicpc.net/problem/13398
13398 다이나믹 문제풀이 Top Down
1. solu(n) : n번째 수를 선택할 경우의 연속합의 최댓값
   solu(n) = max(solu(n-1)+p[n], p[n])
2. sold(n, last) : last에서 1로 1씩 감소할 때 n번째 수를 선택할 경우의 연속합의 최댓값
   sold(n,last) = max(sold(n+1,last)+p[n], p[n])
ans = max(solu(L), ans) (L >= 1 && L <= n)
   특정 수를 제외하지 않는 경우를 포함해야 하므로, 제외하지 않는 경우의 최댓값을 정한다.
ans = max(sold(L+1,n), ans) (L == 1)
ans = max(solu(L-1)+sold(L+1,n), ans) (L > 1 && L < n)
   이후 L번째 수를 제외하는 경우의 최댓값을 정한다.
   L이 n일 때, ans와 solu(L-1)를 비교해야하는데, 
   이는 이미 특정 수를 제외하지 않는 경우에서 계산했으므로 의도적으로 제외했다.
*/

#include <iostream>
#include <array>
#include <algorithm>

using namespace std;
array<int, 100001> d, u, p;

int solu(const int n)
{
    if(n == 1) u[n] = p[n];
    if(u[n] != -1001) return u[n];
    u[n] = max(solu(n-1)+p[n], p[n]);
    return u[n];
}

int sold(const int n, const int last)
{
    if(n == last) d[n] = p[n];
    if(d[n] != -1001) return d[n];
    d[n] = max(sold(n+1, last)+p[n], p[n]);
    return d[n];
}

int main()
{
    int n, ans;
    cin >> n;
    d.fill(-1001);
    u.fill(-1001);
    for(int i = 1; i <= n; ++i) cin >> p[i];
    solu(n);
    sold(1,n);
    ans = *max_element(u.cbegin()+1, u.cbegin()+n+1);
    for(int i = 1; i < n; ++i)
    {
        if(i == 1 && solu(i) > ans) ans = solu(i);
        if(solu(i-1)+sold(i+1,n) > ans) ans = solu(i-1)+sold(i+1,n);
    }
    cout << ans << '\n';
    return 0;
}