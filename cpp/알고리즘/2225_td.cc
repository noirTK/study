/*
https://www.acmicpc.net/problem/2225
2225 다이나믹 문제풀이 Top Down
sol(n) 정수 n을 0 ~ n의 정수 k개를 더해서 나타낼수 있는 경우의 수
sol(n,k) = Σ sol(n-L,k-1) (0 <= L <= n)
sol(S,1) = 1 (0 <= S <= n)
*/

#include <iostream>
#include <array>

using namespace std;
array<array<long long, 201>, 201> d;
const long long mod = 1000000000LL;

long long sol(const int n, const int k)
{
    if(k == 1) return 1;
    if(d[n][k] != -1) return d[n][k];
    d[n][k] = 0;
    for(int L = 0; L <= n; ++L)
    {
        d[n][k] += sol(n-L,k-1);
        d[n][k] %= mod;
    }
    return d[n][k];
}
int main()
{
    int n, k;
    cin >> n >> k;
    for(int i = 0; i <= n; ++i) d[i].fill(-1);
    cout << sol(n, k) << '\n';
    return 0;
}