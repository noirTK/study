/*
https://www.acmicpc.net/problem/11055
11055 다이나믹 문제풀이 Top Down
sol(n) p[n]을 선택했을 경우의 증가 부분 수열의 최댓값
sol(n) = p[n]
sol(n) (p[n] > p[L]) d[n] = max(sol(L)+p[n], d[n]) (L >= 1 && L < n)
*/

#include <iostream>
#include <array>
#include <algorithm>

using namespace std;
array<int, 1001> d, p;

int sol(const int n)
{
    if(d[n] != -1) return d[n];
    d[n] = p[n];
    for(int i = 1; i < n; ++i)
    {
        if(p[n] > p[i]) d[n] = max(sol(i)+p[n], d[n]);
    }
    return d[n];
}

int main()
{
    int n;
    cin >> n;
    d.fill(-1);
    for(int i = 1; i <= n; ++i) cin >> p[i];
    for(int i = 1; i <= n; ++i) sol(i);
    cout << *max_element(d.cbegin()+1, d.cbegin()+n+1) << '\n';
}