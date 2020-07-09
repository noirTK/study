/*
https://www.acmicpc.net/problem/11053
11053(LIS) 다이나믹 문제풀이 Top Down
sol(n) 수열의 길이 n에 대하여 n일 때의 증가하는 부분수열의 길이
sol(n) = max(max(sol(L)+1), sol(n)) (p[L] < p[n] && 1 <= L < n)
LIS = max(sol(S)) (1<= S <= n)
Top Down 시 주의할 점.(sol 스택호출만 해당.)
================================================================================
if(p[i] < p[n] && sol(i) >= d[n]) d[n] = sol(i) + 1; 
p[i] >= p[n]일 경우, if 조건문에서 무조건 false이므로, if 조건문을 거치지 않고 값 1을 리턴한다.
따라서 sol(n)만 호출 시 맨 마지막 값이 가장 작을 경우 무조건 LIS는 1이 된다.
** 결국 sol(L) (1<= L <= n)을 모두 호출해야하는데, 
방법 1. 명시적 호출 sol(L) (1<= L <= n) 모두 호출
방법 2. 암시적 호출 if(sol(i) >= d[n] && p[i] < p[n]) d[n] = sol(i) + 1; 
하는 방법이 있다. 여기에서는 암시적 호출을 사용하였다.
================================================================================
*/
#include <iostream>
#include <array>
#include <algorithm>

using namespace std;
array<int, 1001> d, p;

int sol(const int n)
{
    if(d[n] != -1) return d[n];
    d[n] = 1;
    for(int i = 1; i < n; ++i)
    {
        if(sol(i) >= d[n] && p[i] < p[n]) d[n] = sol(i) + 1;
    }
    return d[n];
}

int main()
{
    int n;
    cin >> n;
    d.fill(-1);
    for(int i = 1; i <= n; ++i) cin >> p[i];
    sol(n);
    cout << *max_element(d.cbegin()+1, d.cbegin()+n+1) << '\n';
}