/*
https://www.acmicpc.net/problem/1149
1149 다이나믹 문제풀이 Bottom Up
d[n][k] n개의 집 중 마지막 집을 k색으로 색칠시 최소 비용
d[n][R] = min(d[n-1][G], d[n-1][B]) + p[n][R]
d[n][G] = min(d[n-1][R], d[n-1][B]) + p[n][G]
d[n][B] = min(d[n-1][R], d[n-1][G]) + p[n][B]
d[0][c] = 0 (c = R || c = G || c = B)이므로, n = 1인 경우에도 위의 점화식이 성립한다.
ans = min(d[n][R], d[n][G], d[n][B])
*/

#include <iostream>
#include <array>
#include <algorithm>

using namespace std;
array<array<int, 3>, 1001> d, p;
enum colar { R = 0, G, B};

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> p[i][R] >> p[i][G] >> p[i][B];
    for(int i = 1; i <= n; ++i)
    {
        d[i][R] = min(d[i-1][G], d[i-1][B]) + p[i][R];
        d[i][G] = min(d[i-1][R], d[i-1][B]) + p[i][G];
        d[i][B] = min(d[i-1][R], d[i-1][G]) + p[i][B];
    }
    cout << *min_element(&d[n][0], &d[n][0]+3) << '\n';
    return 0;
}