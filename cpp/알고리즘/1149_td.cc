/*
https://www.acmicpc.net/problem/1149
1149 다이나믹 문제풀이 Top Down
sol(n,c) n개의 집 중 마지막 집을 c색으로 색칠 시 최소비용
sol(n,R) = min(sol(n-1,B), sol(n-1,G)) + p[n][R]
sol(n,G) = min(sol(n-1,R), sol(n-1,B)) + p[n][G]
sol(n,B) = min(sol(n-1,R), sol(n-1,G)) + p[n][B]
sol(1,c) = p[1][c] (c = R || c = B || c = C)
ans = min(sol(n,R), sol(n,G), sol(n,B))
*/

#include <iostream>
#include <array>
#include <algorithm>

using namespace std;
enum color { R = 0, G, B };
array<array<int, 3>, 1001> d, p;

int sol(const int n, const int c)
{
    if(n == 1) return p[1][c];
    if(d[n][c] != -1) return d[n][c];
    if(c == R) d[n][c] = min(sol(n-1,B),sol(n-1,G)) + p[n][R];
    else if(c == G) d[n][c] = min(sol(n-1,R),sol(n-1,B)) + p[n][G];
    else if(c == B) d[n][c] = min(sol(n-1,R),sol(n-1,G)) + p[n][B];
    return d[n][c];
}

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> p[i][R] >> p[i][G] >> p[i][B];
    for(int i = 1; i <= n; ++i) d[i].fill(-1);
    cout << min({sol(n,R), sol(n,G), sol(n,B)}) << '\n';
    return 0;
}