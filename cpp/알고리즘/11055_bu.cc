/*
https://www.acmicpc.net/problem/11055
11055 다이나믹 문제풀이 Bottom Up
d[n] p[n]을 선택했을 경우의 증가 부분 수열의 최댓값
d[n] = p[n]
(p[n] > p[L]) d[n] = max(d[L]+p[n], d[n]) (L >= 1 && L < n)
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
    for(int i = 1; i <= n; ++i)
    {
        d[i] = p[i];
        for(int j = 1; j < i; ++j)
        {
            if(p[i] > p[j]) d[i] = max(d[j]+p[i], d[i]);
        }
    }
    cout << *max_element(d.cbegin()+1, d.cbegin()+n+1) << '\n';
    return 0;
}