/*
https://www.acmicpc.net/problem/2225
2225 다이나믹 문제풀이3 Buttom Up
1차원 배열 문제풀이
d[n][k] = d[n-1][k]+d[n][k-1] 일때, d2[n] = d2[n-1]+d2[n] 이용
d[n] 0부터 n까지의 정수 k개를 더해서 그 합이 n이 되는 경우의 수
d[n] = d[n-1]+d[n] (단, n == 1, d[n] = k)

d[n][k] = d[n-1][k]+d[n][k-1]이므로, 
d2[n] = d[n][k]라 할 때, d2[n]을 k번 반복해서 d2[n]을 갱신.
d2[1] = k이고, d2[n] = d2[n-1]+d2[n]을 이용.
*/

#include <iostream>
#include <array>

using namespace std;
array<long long, 201> d;
const long long mod = 1000000000LL;

int main()
{
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= k; ++i)
    {
        d[1] = i;
        for(int j = 2; j <= n; ++j)
        {
            d[j] = d[j-1]+d[j];
            d[j] %= mod;
        }
    }
    cout << d[n] << '\n';
    return 0;
}