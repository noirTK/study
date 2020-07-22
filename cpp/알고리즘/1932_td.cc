/*
https://www.acmicpc.net/problem/1932
1932 다이나믹 문제풀이 Top Down
sol(n,l) 삼각형에서 (n,l)의 숫자를 선택했을 경우의 최댓값
1. (l == 1) sol(n,l) = sol(n-1,l) + p[n][l]
2. (l == n) sol(n,l) = sol(n-1,l-1) + p[n][l]
3. (l > 1 && l < n) sol(n,l) = max(sol(n-1,l), sol(n-1,l-1)) + p[n][l]
sol(1,1) = p[1][1]
*/

#include <iostream>
#include <array>
#include <algorithm>

using namespace std;
array<array<int, 501>, 501> d, p;

int sol(const int n, const int l)
{
    if(n == 1) 
    {
        d[n][l] = p[n][l];
        return p[n][l];
    }
    if(d[n][l] != -1) return d[n][l];
    if(l == 1) d[n][l] = sol(n-1, l);
    else if(l == n) d[n][l] = sol(n-1,l-1);
    else d[n][l] = max(sol(n-1,l), sol(n-1,l-1));
    d[n][l] += p[n][l];
    return d[n][l];
}

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) d[i].fill(-1);
    for(int y = 1; y <= n; ++y)
    {
        for(int x = 1; x <= y; ++x)
        {
            cin >> p[y][x];
        }
    }
    for(int i = 1; i <= n; ++i) sol(n,i);
    cout << *max_element(&d[n][1], &d[n][1]+n) << '\n';
}