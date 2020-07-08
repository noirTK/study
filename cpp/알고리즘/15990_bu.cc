/*
https://www.acmicpc.net/problem/15990
15990 다이나믹 문제풀이 Bottom Up
d[n][t] = 정수 n, t에 대하여 정수 n의 끝자리 값이 t일때 1,2,3의 합으로 나타내는 방법의 수
d[n][1] = d[n-1][2] + d[n-1][3]
d[n][2] = d[n-2][1] + d[n-2][3]
d[n][3] = d[n-3][1] + d[n-3][2]
d[1][1] = d[2][2] = d[3][1] = d[3][2] = d[3][3] = 1
d[1][2] = d[1][3] = d[2][1] = d[2][3] = 0
*/

#include <iostream>
#include <array>

using namespace std;
const long long mod = 1000000009LL;
array<array<long long, 4>, 100001> d;

int main()
{
    int t;
    cin >> t;
    d[1][1] = d[2][2] = d[3][1] = d[3][2] = d[3][3] = 1;
    while(t--)
    {
        int n;
        cin >> n;
        for(int i = 4; i <= n; ++i)
        {
            d[i][1] = (d[i-1][2] + d[i-1][3]) % mod;
            d[i][2] = (d[i-2][1] + d[i-2][3]) % mod;
            d[i][3] = (d[i-3][1] + d[i-3][2]) % mod;
        }
        cout << (d[n][1] + d[n][2] + d[n][3]) % mod << '\n';
    }
}