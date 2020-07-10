/*
https://www.acmicpc.net/problem/11057
11057 다이나믹 문제풀이 Bottom Up
d[n][t] 길이가 n이고 마지막 수가 t일 대의 오르막 수의 개수
d[n][L] = Σ d[n-1][S] (0 <= S <= L)
d[1][L] = 1 (0 <= L <= 9)
ans = Σ d[n][L] (0 <= L <= 9)
*/

#include <iostream>
#include <array>

using namespace std;
const int mod = 10007;
array<array<int, 10>, 1001> d;

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        for(int t = 0; t <= 9; ++t)
        {
            if(i == 1) 
            {
                d[i][t] = 1;
                continue;
            }
            d[i][t] = 0;
            for(int j = 0; j <= t; ++j)
            {
                d[i][t] += d[i-1][j];
                d[i][t] %= mod;
            }
        }
    }
    int ans = 0;
    for(int i = 0; i <= 9; ++i)
    {
        ans += d[n][i];
        ans %= mod;
    }
    cout << ans << '\n';
    return 0;
}