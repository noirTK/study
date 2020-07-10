/*
https://www.acmicpc.net/problem/2156
2156 다이나믹 문제풀이 Bottom Up
d[n][c] n개의 포도주 중 마지막을 연속해서 c번째 마시는 경우의 포도주 양의 최댓값
d[n][0] = max(d[n-1][0], d[n-1][1], d[n-1][2])
d[n][1] = d[n-1][0] + p[n]
d[n][2] = d[n-1][1] + p[n]
d[1][0] = d[1][2] = 0
d[1][1] = p[1]
*/

#include <iostream>
#include <array>
#include <algorithm>

using namespace std;
array<array<int, 3>, 10001> d;
array<int, 10001> p;

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> p[i];

    d[1][0] = d[1][2] = 0;
    d[1][1] = p[1];
    for(int i = 2; i <= n; ++i)
    {
        d[i][0] = max({d[i-1][0], d[i-1][1], d[i-1][2]});
        d[i][1] = d[i-1][0] + p[i];
        d[i][2] = d[i-1][1] + p[i];
    }
    cout << max({d[n][0], d[n][1], d[n][2]}) << '\n';
    return 0;
}