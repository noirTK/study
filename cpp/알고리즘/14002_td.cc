/*
https://www.acmicpc.net/problem/14002
14002 다이나믹 문제풀이 Top Down
sol(n) 길이가 n인 수열의 증가하는 부분 수열의 길이
sol(n) max(sol(L)+1,d[n]) (1 <= L < n)
go() 스택호출을 이용하여 출력순서를 뒤집었다. (자료구조 stack을 이용해도 됨.)
*/

#include <iostream>
#include <array>

using namespace std;
array<int, 1001> p, d, a;

int sol(const int n)
{
    if(d[n] != -1) return d[n]; 
    d[n] = 1;
    for(int L = 1; L < n; ++L) 
    {
        if(p[L] < p[n] && sol(L) >= d[n])
        {
            d[n] = sol(L) + 1;
            a[n] = L;
        }
    }
    return d[n];
}

void go(const int n)
{
    if(n == 0) return;
    go(a[n]);
    cout << p[n] << ' ';
}

int main()
{
    d.fill(-1);
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> p[i];
    for(int i = 1; i <= n; ++i) sol(i);
    int index;
    for(int i = 1; i <= n; ++i)
    {
        if(i == 1 || d[index] < d[i]) index = i;
    }
    cout << d[index] << '\n';
    go(index);
    return 0;
}