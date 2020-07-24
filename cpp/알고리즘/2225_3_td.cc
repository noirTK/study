/*
https://www.acmicpc.net/problem/2225
2225 다이나믹 문제풀이3 Top Down
1차원 배열 문제풀이
d[n][k] = d[n-1][k]+d[n][k-1] 일때, d2[n] = d2[n-1]+d2[n] 이용
sol(n, k) 0부터 n까지의 정수 k개를 더해서 그 합이 n이 되는 경우의 수
sol(n, k) = sol(n-1,k)+d[n] (단, n == 1, sol(1,k) = k)

d[n][k] = d[n-1][k]+d[n][k-1]이므로, 
d2[n] = d[n][k]라 할 때, d2[n]을 k번 반복해서 d2[n]을 갱신.
d2[1] = k이고, d2[n] = d2[n-1]+d2[n]을 이용.
*/

#include <iostream>
#include <array>

using namespace std;
array<long long, 201> d;
const long long mod = 1000000000LL;

long long sol(const int n, const int k)
{
    if(n == 1) return k;
    d[n] = sol(n-1,k)+d[n];
    d[n] %= mod;
    return d[n];
}

int main()
{
    int n, k;
    long long ans;
    cin >> n >> k;
    for(int i = 1; i <= k; ++i)
    {
        ans = sol(n,i);
    }
    cout << ans << '\n';
    return 0;
}