/*
https://www.acmicpc.net/problem/1912
1912 다이나믹 문제풀이 Top Down
sol(n) 마지막이 n인 연속합
sol(n) = max(sol(n-1)+p[n], p[n])
sol(1) = p[1]
*/

#include <iostream>
#include <array>
#include <algorithm>

using namespace std;
array<int, 100001> d, p;

int sol(const int n)
{
    if(n == 1)
    {
        d[1] = p[1];
        return p[1];
    }
    if(d[n] != -1001) return d[n];
    d[n] = max(sol(n-1) + p[n], p[n]);
    return d[n];
}

int main()
{
    d.fill(-1001);
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> p[i];
    sol(n);
    cout << *max_element(d.cbegin()+1, d.cbegin()+n+1) << '\n';
    return 0;
}