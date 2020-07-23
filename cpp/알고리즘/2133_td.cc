/*
https://www.acmicpc.net/problem/2133
2133 다이나믹 문제풀이 Top Down
sol(n) 3xn 공간을 2x1의 타일로 채울 수 있는 경우의 수
sol(0) = 1
n이 홀수일 때 : sol(n) = 0
n이 짝수일 때 :
  1. sol(n) = sol(n-L)*3  (L == 2)
  2. sol(n) = Σsol(n-L)*2 (L >= 4)

n이 홀수일 때 3xn 타일을 전혀 채울 수 없으므로 0이다.
2x1타일로 맨 끝 3x(n-2)를 채우기 위해 필요한 타일 수는 3개이다.
2x1타일로 맨 끝 3x(n-L)을 채우기 위해 필요한 타일 수는 2개이다. (L >= 4, L은 짝수)
*/

#include <iostream>
#include <array>

using namespace std;
array<int, 31> d;

int sol(const int n)
{
    if(n == 0) return 1;
    if(n % 2 != 0) return 0;
    if(d[n] != -1) return d[n];
    d[n] = 0;
    for(int i = 2; i <= n; i+=2)
    {
        if(i == 2) d[n] += sol(n-i)*3;
        else d[n] += sol(n-i)*2;
    }
    return d[n];
}

int main()
{
    d.fill(-1);
    int n;
    cin >> n;
    cout << sol(n) << '\n';
    return 0;
}