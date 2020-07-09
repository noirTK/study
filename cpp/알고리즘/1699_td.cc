/*
https://www.acmicpc.net/problem/1699
1699 다이나믹 문제풀이 Top Down
sol(n) 정수 n의 제곱수의 항의 최소갯수
sol(n) = min(sol(n-L*L), d[n]) (1 <= L*L <= n)
sol(0) = 0
*/

#include <iostream>
#include <array>
#include <algorithm>
using namespace std;
array<int, 100001> d;

int sol(const int n)
{
    if(n == 0) return 0;
    if(d[n] != -1) return d[n];
    d[n] = n;
    for(int i = 1; i*i <= n; ++i)
    {
        d[n] = min(sol(n-i*i) + 1, d[n]);
    }
    return d[n];
}

int main()
{
    d.fill(-1);
    int n;
    cin >> n;
    cout << sol(n) << '\n';
    return 0;
}