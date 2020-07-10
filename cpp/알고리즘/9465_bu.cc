/*
https://www.acmicpc.net/problem/9465
9465 다이나믹 문제풀이 Bottom Up
d[n][c] 2n 스티커 중에서 n번째를 선택하거나 선택하지 않았을 경우의 스티커 점수의 최댓값
d[n][L] = max(d[n-1][N], d[n-1][R]) + p[n][L]
d[n][R] = max(d[n-1][N], d[n-1][L]) + p[n][R]
d[n][N] = max({d[n-1][N], d[n-1][R], d[n-1][L]})
d[1][c] = p[1][c]
*/

#include <iostream>
#include <array>
#include <algorithm>

using namespace std;
array<array<int, 3>, 100001> d, p;
enum choice {R = 0, L, N};

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        for(int j = R; j <= L; ++j)
        {
            for(int i = 1; i <= n; ++i)
            {
                cin >> p[i][j];
            }
        }
        d[1][R] = p[1][R];
        d[1][L] = p[1][L];

        for(int i = 2; i <= n; ++i)
        {
            d[i][L] = max(d[i-1][N], d[i-1][R]) + p[i][L];
            d[i][R] = max(d[i-1][N], d[i-1][L]) + p[i][R];
            d[i][N] = max({d[i-1][N], d[i-1][R], d[i-1][L]});
        }
        cout << max({d[n][L], d[n][R], d[n][N]}) << '\n';
    }
    return 0;
}