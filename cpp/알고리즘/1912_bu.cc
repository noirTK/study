/*
https://www.acmicpc.net/problem/1912
1912 다이나믹 문제풀이 Bottom Up
d[n] 길이가 n인 수열의 마지막이 n인 경우의 연속합
d[n] = max(d[n-1]+p[n], p[n])
d[1] = p[1]
*/

#include <iostream>
#include <array>
#include <algorithm>

using namespace std;
array<int, 100001> p, d;

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> p[i];
    d[1] = p[1];
    for(int i = 2; i <= n; ++i)
    {
        d[i] = max(d[i-1] + p[i], p[i]);
    }
    cout << *max_element(d.cbegin()+1, d.cbegin()+n+1) << '\n';
    return 0;
}