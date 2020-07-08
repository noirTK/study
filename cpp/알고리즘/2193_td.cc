/*
https://www.acmicpc.net/problem/2193
2193 다이나믹 문제풀이 Top Down
sol(n,t) n자리 수의 끝 수가 t인 경우의 이친수의 개수
sol(n,1) = sol(n-1,0)
sol(n,0) = sol(n-1,0) + sol(n-1,1)
sol(1,1) = 1
sol(1,0) = 0
*/

#include <iostream>
#include <array>

using namespace std;
array<array<long long, 2>, 91> d;

long long sol(const int n, const int t)
{
    if(n == 1) return t == 1 ? 1 : 0;
    if(d[n][t] != -1) return d[n][t];
    d[n][t] = (t == 1) ? sol(n-1, 0) : sol(n-1,0) + sol(n-1,1);
    return d[n][t];
}

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) d[i].fill(-1);
    cout << sol(n,0) + sol(n,1) << '\n';
    return 0;
}