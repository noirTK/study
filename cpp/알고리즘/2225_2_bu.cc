/*
https://www.acmicpc.net/problem/2225
2225 다이나믹 문제풀이2 Bottom Up
d[n][k] : 0부터 n까지 정수 k개를 더해서 그 합이 0이 되는 경우의 수
d[n][k] = d[n][k-1] + d[n-1][k] (n >= 1 && k >= 1)
d[0][L] = 1 (L >= 1)
d[N][0] = 0 (N >= 1)
*/

#include <iostream>
#include <array>

using namespace std;
array<array<long long, 201>, 201> d;
const long long mod = 1000000000LL;

int main()
{
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= k; ++i) d[0][i] = 1LL;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= k; ++j)
        {
            d[i][j] = d[i][j-1]+d[i-1][j];
            d[i][j] %= mod;
        }
    }
    cout << d[n][k] << '\n'; 
    return 0;
}