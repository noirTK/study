/*
https://www.acmicpc.net/problem/1932
1932 다이나믹 문제풀이 Bottom Up
d[n][l] 삼각형에서 (n,l)의 숫자를 선택했을 경우의 최댓값
1. (l == 1) d[n][l] = d[n-1][l] + p[n][l]
2. (l == n) d[n][l] = d[n-1][l-1] + p[n][l]
3. (l > 1 && l < n) d[n][l] = max(d[n-1][l], d[n-1][l-1]) + p[n][l]
d[1][1] = p[1][1]
*/

#include <iostream>
#include <array>
#include <algorithm>

using namespace std;
array<array<int, 501>, 501> d, p;

int main()
{
    int n;
    cin >> n;
    for(int y = 1; y <= n; ++y)
    {
        for(int x = 1; x <= y; ++x)
        {
            cin >> p[y][x];
        }
    }
    d[1][1] = p[1][1];
    for(int i = 2; i <= n; ++i)
    {
        for(int l = 1; l <= i; ++l)
        {
            if(l == 1) d[i][l] = d[i-1][l];
            else if(l == i) d[i][l] = d[i-1][l-1];
            else d[i][l] = max(d[i-1][l], d[i-1][l-1]);
            d[i][l] += p[i][l];
        }
    }
    cout << *max_element(&d[n][1], &d[n][1]+n) << '\n';
}