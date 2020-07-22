/*
https://www.acmicpc.net/problem/11722
11722 다이나믹 문제풀이 Bottom Up
d[n] n번째 숫자를 선택했을 경우의 감소하는 부분수열의 길이
d[n] = 1
(p[n] < p[L]) d[n] = max(d[L]+1, d[n]) (1 <= L && L < n)
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
        d[i] = 1;
        for(int l = 1; l < i; ++l)
        {
            if(p[i] < p[l]) d[i] = max(d[l]+1, d[i]);
        }
    }
    cout << *max_element(d.cbegin()+1, d.cbegin()+1+n) << '\n'; 
    return 0;
}