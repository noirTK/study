/*
https://www.acmicpc.net/problem/2156
2156 다이나믹 문제풀이 Top Down
sol(n,c) n개의 포도주잔 중에서 마지막으로 c번째 마실 경우의 포도주 양의 최댓값
sol(n,0) = max(sol(n-1,0), sol(n-1,1), sol(n-1,2));
sol(n,1) = sol(n-1,0) + p[n]
sol(n,2) = sol(n-1,1) + p[n]
sol(1,1) = p[1]
sol(1,0) = sol(1,2) = 0 
*/
#include <iostream>
#include <array>
#include <algorithm>

using namespace std;
array<array<int, 3>, 10001> d;
array<int, 10001> p;

int sol(const int n, const int c)
{
    if(n == 1) return (c == 1) ? p[1] : 0;
    if(d[n][c] != -1) return d[n][c];
    if(c == 0) d[n][c] = max({sol(n-1,0), sol(n-1,1), sol(n-1,2)});
    else if(c == 1) d[n][c] = sol(n-1,0) + p[n];
    else if(c == 2) d[n][c] = sol(n-1,1) + p[n];
    return d[n][c];
}

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> p[i];
    for(int i = 1; i <= n; ++i) d[i].fill(-1);
    cout << max({sol(n,0), sol(n,1), sol(n,2)}) << '\n';
    return 0;
}