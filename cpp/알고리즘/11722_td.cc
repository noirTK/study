/*
https://www.acmicpc.net/problem/11722
11722 다이나믹 문제풀이 Top Down
sol(n) n번째 숫자를 선택했을 경우의 감소하는 부분수열의 길이
d[n] = 1
(p[n] < p[L]) d[n] = max(sol(L)+1, d[n]) (1 <= L && L < n)
for(int i = 1; i <= n; ++i) sol(i) 이용한 직접호출
*/

#include <iostream>
#include <array>
#include <algorithm>

using namespace std;
array<int, 1001> d, p;

int sol(const int n)
{
    if(n == 1) d[n] = 1;
    if(d[n] != -1) return d[n];
    d[n] = 1;
    for(int i = 1; i < n; ++i)
    {
        if(p[n] < p[i]) d[n] = max(sol(i)+1, d[n]);
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
    cout << *max_element(d.cbegin()+1, d.cbegin()+1+n) << '\n';
    return 0;
}