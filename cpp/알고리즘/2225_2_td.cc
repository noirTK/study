/*
https://www.acmicpc.net/problem/2225
2225 다이나믹 문제풀이2 Top Down
sol(n,k) : 0부터 n까지 정수 k개를 더해서 그 합이 0이 되는 경우의 수
sol(n,k) = sol(n,k-1) + sol(n-1,k) (n >= 1 && k >= 1)
sol(0,L) = 1 (L >= 1)
sol(N,0) = 0 (N >= 1)
*/

#include <iostream>
#include <array>

using namespace std;
array<array<long long, 201>, 201> d;
const long long mod = 1000000000LL;

long long sol(const int n, const int k)
{
    if(n == 0 || k == 1) return 1;
    if(d[n][k] != -1) return d[n][k];
    d[n][k] = sol(n,k-1) + sol(n-1,k);
    d[n][k] %= mod;
    return d[n][k];
}
int main()
{
    int n, k; 
    cin >> n >> k;
    for(int i = 1; i <= n; ++i) d[i].fill(-1);
    cout << sol(n, k) << '\n';
    return 0;
}