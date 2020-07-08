/*
https://www.acmicpc.net/problem/16194
16194 다이나믹 문제풀이 Bottom Up
d[n] = 정수 n에 대하여 n개의 카드를 구입하는 금액의 최솟값
d[n] = min(d[n-j] + p[j]) (1 <= j <= n)
d[0] = 0
*/

#include <iostream>
#include <array>
#include <algorithm>

using namespace std;
array<int, 1001> p, d;
int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> p[i];
    d[0] = 0;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= i; ++j)
        {
            if(j == 1) d[i] = d[i-1] + p[1];
            else d[i] = min(d[i], d[i-j] + p[j]);
        }
    }
    cout << d[n] << '\n';
    return 0;
}