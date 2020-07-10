/*
https://www.acmicpc.net/problem/11057
11057 다이나믹 문제풀이 TopDown
sol(n,t) 길이가 n이고 마지막 수가 t일 때의 오르막 수의 개수
sol(n,L) = Σ sol(n-1,S) (0 <= S <= L)
sol(1,L) = 1 (0 <= L <= 9)
ans = Σ sol(n,L) (0 <= L <= 9)
*/
#include <iostream>
#include <array>

using namespace std;
const int mod = 10007;
array<array<int, 10>, 1001> d;

int sol(const int n, const int t)
{
    if(n == 1) return 1;
    if(d[n][t] != -1) return d[n][t];
    d[n][t] = 0;
    for(int i = 0; i <= t; ++i)
    {
        d[n][t] += sol(n-1,i);
        d[n][t] %= mod;
    }
    return d[n][t];
}

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) d[i].fill(-1);
    int ans = 0;
    for(int i = 0; i <= 9; ++i)
    {
        ans += sol(n,i);
        ans %= mod;
    }
    cout << ans << '\n';
    return 0;
}