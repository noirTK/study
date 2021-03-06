/*
https://www.acmicpc.net/problem/2193
2193 다이나믹 문제풀이 Bottom Up 2
d[n] n자리 수의 이친수의 개수
d[n] = d[n-1] + d[n-2]
d[1] = d[2] = 1

==================================================================================
d[n][t] 를 n자리 수의 마지막 수가 t인 이친수의 개수 라고 할 때,
d[n][1] = d[n-1][0], d[n][0] = d[n-1][0] + d[n-1][1] (n > 1) 을 만족한다.
d[n] = d[n][0] + d[n][1] 이므로, d[n] = d[n-1][0] + d[n-1][0] + d[n-1][1] (n > 1)이다.
또한, d[n-1][0] = d[n-2][0] + d[n-2][1] (n > 2)를 만족하므로,
d[n] = d[n-2][0] + d[n-2][1] + d[n-1][0] + d[n-1][1] (n > 2)
즉, d[n] = d[n-1] + d[n-2] 이다. (n > 2)
==================================================================================
*/

#include <iostream>
#include <array>

using namespace std;
array<long long, 91> d;
int main()
{
    int n;
    cin >> n;
    d[1] = d[2] = 1;
    for(int i = 3; i <= n; ++i) d[i] = d[i-1] + d[i-2];
    cout << d[n] << '\n';
    return 0;
}