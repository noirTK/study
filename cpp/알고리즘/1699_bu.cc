/*
https://www.acmicpc.net/problem/1699
1699 다이나믹 문제풀이 Bottom Up
d[n] 정수 n에 대해 제곱수의 합의 항의 최소 갯수
d[n] = min(d[n-L*L]+1,d[n]) (1<= L*L <= n)
d[0] = 0
*/

#include <iostream>
#include <array>
#include <algorithm>
using namespace std;
array<int, 100001> d;

int main()
{
    int n;
    cin >> n;

    for(int i = 1; i <= n; ++i)
    {
        d[i] = i;
        for(int k = 1; k*k <= i; ++k)
        {
            d[i] = min(d[i-k*k]+1, d[i]);
        }
    }
    cout << d[n] << '\n';
    return 0;
}