/*
https://www.acmicpc.net/problem/2193
2193 다이나믹 문제풀이 Bottom Up
d[n][t] n자리수의 끝수가 t인 경우의 이친수의 개수
d[n][1] = d[n-1][0]
d[n][0] = d[n-1][0] + d[n-1][1]
d[1][0] = 0
d[1][1] = 1
*/

#include <iostream>
#include <array>

using namespace std;
array<array<long long, 2>, 91> d;
int main()
{
    int n;
    cin >> n;
    d[1][1] = 1;
    for(int i = 2; i <= n; ++i)
    {
        d[i][1] = d[i-1][0];
        d[i][0] = d[i-1][0] + d[i-1][1];
    }
    cout << d[n][0] + d[n][1] << '\n';
    return 0;
}