/*
https://www.acmicpc.net/problem/13398
13398 다이나믹 문제풀이 Bottom Up
1. u[n] : n번째 수를 선택할 경우의 연속합의 최댓값
   u[n] = max(u[n-1]+p[n], p[n])
2. d[n] : last에서 1로 1씩 감소할 때 n번째 수를 선택할 경우의 연속합의 최댓값
   d[n] = max(d[n+1]+p[n],p[n])
ans = max(u[L], ans) (L >= 1 && L <= n)
   특정 수를 제외하지 않는 경우를 포함해야 하므로, 제외하지 않는 경우의 최댓값을 정한다.
ans = max(d[L+1], ans) (L == 1)
ans = max(u[L-1]+d[L+1], ans) (L > 1 && L < n)
   이후 L번째 수를 제외하는 경우의 최댓값을 정한다.
   L이 n일 때, ans와 u[L-1]를 비교해야하는데, 
   이는 이미 특정 수를 제외하지 않는 경우에서 계산했으므로 의도적으로 제외했다.
*/

#include <iostream>
#include <array>
#include <algorithm>

using namespace std;
array<int, 100001> p, d, u;

int main()
{
    int n, ans;
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> p[i];
    u[1] = p[1];
    for(int i = 2; i <= n; ++i) 
    {
        u[i] = max(u[i-1]+p[i], p[i]);
    }
    d[n] = p[n];
    for(int i = n-1; i >= 1; --i)
    {
        d[i] = max(d[i+1]+p[i], p[i]);
    }
    ans = *max_element(u.cbegin()+1, u.cbegin()+n+1);
    for(int i = 1; i < n; ++i)
    {
        if(i == 1 && d[i+1] > ans) ans = d[i];
        if(u[i-1] + d[i+1] > ans) ans = u[i-1] + d[i+1];
    }
    cout << ans << '\n';
    return 0;
}