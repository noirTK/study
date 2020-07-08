/*
https://www.acmicpc.net/problem/16194
16194 다이나믹 문제풀이 - Top Down
sol(n) 정수 n에 대하여 n개의 카드를 구입하는 금액의 최솟값
sol(n) = min(sol(n-j)+p[j]) (1 <= j <= n)
sol(0) = 0
*/


#include <iostream>
#include <array>
#include <algorithm>

using namespace std;
array<int, 1001> p, d; 

int sol(const int n)
{
    if(n == 0) return 0;
    if(d[n] != -1) return d[n];
    d[n] = sol(n-1) + p[1];
    for(int j = 2; j <= n; ++j)
    {
        d[n] = min(d[n], sol(n-j) + p[j]);
    }
    return d[n];
}

int main()
{
    d.fill(-1);
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> p[i];
    cout << sol(n) << '\n';
    return 0;
}