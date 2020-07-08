/*
https://www.acmicpc.net/problem/10844
10844 다이나믹 문제풀이 Top Down
sol(n,t) 길이가 n이고 끝의 수가 t인 경우의 계단 수의 개수
(t == 0) sol(n,t) = sol(n-1,1)
(t == 9) sol(n,t) = sol(n-1,8)
(0 < t < 9) sol(n,t) = sol(n-1,t-1) + sol(n-1,t+1)
sol(1,0) = 0 sol(1, L) = 1 (0 < L <= 9)
*/

#include <iostream>
#include <array>

using namespace std;
const long long mod = 1000000000LL;
array<array<long long, 10>, 101> d;

long long sol(const int n, const int t)
{
    if(n == 1) return t == 0 ? 0 : 1;
    if(d[n][t] != -1) return d[n][t];
    if(t == 0) d[n][t] = sol(n-1,1);
    else if(t == 9) d[n][t] = sol(n-1,8);
    else 
    {
        d[n][t] = sol(n-1,t-1) + sol(n-1, t+1);
        d[n][t] %= mod;
    }
    return d[n][t];
}

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) d[i].fill(-1);
    long long ans = 0;
    for(int i = 0; i <= 9; ++i)
    {
        ans += sol(n,i);
        ans %= mod;
    }
    cout << ans << '\n';
    return 0;
}