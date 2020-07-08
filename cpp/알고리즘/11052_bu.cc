/*
https://www.acmicpc.net/problem/11052
11052 다이나믹 문제풀이 - Bottom Up
d[n] = 카드 n개를 구입하기 위해 지불해야하는 금액의 최댓값
d[n] = max(d[n-j] + p[j]) (1 <= j <= n)
d[0] = 0
*/

#include <iostream>
#include <array>
#include <algorithm>

using namespace std;
array<int, 1001> d, p;
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
            d[i] = max(d[i], d[i-j] + p[j]);
        }
    }
    cout << d[n] << '\n';
    return 0;
}