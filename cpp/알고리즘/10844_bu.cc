/*
https://www.acmicpc.net/problem/10844
10844 다이나믹 문제풀이 Bottom Up
d[n][t] 길이가 n이고 끝의 수가 t인 경우의 계단 수의 개수
(t == 0) d[n][t] = d[n-1][1]
(t == 9) d[n][t] = d[n-1][8]
(0 < t < 9) d[n][t] = d[n-1][t-1] + d[n-1][t+1]
d[1][0] = 0 d[1][L] = 1 (0 < L <= 9)
*/

#include <iostream>
#include <array>

using namespace std;
const long long mod = 1000000000LL;
array<array<long long, 10>, 101> d;

int main()
{
    int n;
    cin >> n;
    long long ans = 0;
    for(int L = 1; L <= 9; ++L) d[1][L] = 1;
    for(int i = 2; i <= n; ++i)
    {
        for(int t = 0; t <= 9; ++t)
        {
            if(t == 0) d[i][t] = d[i-1][1];
            else if(t == 9) d[i][t] = d[i-1][8];
            else 
            {
                d[i][t] = d[i-1][t-1] + d[i-1][t+1];
                d[i][t] %= mod;
            }
        }
    }
    for(int i = 0; i <= 9; ++i)
    {
        ans += d[n][i];
        ans %= mod;
    }
    cout << ans << '\n';
    return 0;
}