/*
https://www.acmicpc.net/problem/11053
11053(LIS) 다이나믹 문제풀이 Bottom Up
d[n] = 수열의 길이 n에 대하여 n일 때의 증가하는 부분수열의 길이
d[n] = max(d[L]+1, d[n]) (p[L] < p[n] && 1 <= L < N)
LIS = max(d[S]) (1 <= S <= n)
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
        for(int L = 1; L < i; ++L)
        {
            if(p[i] > p[L]) d[i] = max(d[L]+1, d[i]);
        }
    }
    cout << *max_element(d.cbegin()+1, d.cbegin()+n+1) << '\n';
    return 0;
}