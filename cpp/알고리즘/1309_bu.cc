/*
https://www.acmicpc.net/problem/1309
1309 다이나믹 문제풀이 Bottom Up
d[n][s] = 2xn 배열의 n번째 자리에 사자가 위치하거나 위치하지 않았을 경우의 자리 배치 경우의 수
d[n][N] = d[n-1][R] + d[n-1][L] + d[n-1][N]
d[n][R] = d[n-1][L] + d[n-1][N]
d[n][L] = d[n-1][R] + d[n-1][N]
d[1][R] = d[1][L] = d[1][N] = 1
*/
#include <iostream>
#include <array>

using namespace std;
enum space {N = 0, R, L};
const int mod = 9901;
array<array<int, 3>, 100001> d;

int main()
{
    int n;
    cin >> n;
    d[1][N] = d[1][R] = d[1][L] = 1;
    for(int i = 2; i <= n; ++i)
    {
        d[i][N] = (d[i-1][R] + d[i-1][L] + d[i-1][N]) % mod;
        d[i][L] = (d[i-1][R] + d[i-1][N]) % mod;
        d[i][R] = (d[i-1][L] + d[i-1][N]) % mod;
    }
    cout << (d[n][N] + d[n][R] + d[n][L]) % mod << '\n';
    return 0;
}