/*
https://www.acmicpc.net/problem/1463
1463 다이나믹 문제풀이 - TopDown
D[n] = 정수 n에 대해 1로 만드는 연산 횟수의 최솟값
sol(n) = min(sol(n-1)+1, sol(n/3)+1, sol(n/2)+1)
d[1] = 0
*/

#include <iostream>
#include <array>
using namespace std;
array<int, 1000001> d;
int sol(const int n)
{
    if(n == 1) return 0;
    if(d[n] != -1) return d[n];
    d[n] = sol(n-1) + 1;
    if(n % 3 == 0 && d[n] > sol(n/3) + 1) d[n] = sol(n/3) + 1;
    if(n % 2 == 0 && d[n] > sol(n/2) + 1) d[n] = sol(n/2) + 1;
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