/*
https://www.acmicpc.net/problem/2156
2156 다이나믹 문제풀이2 Bottom Up
d[n] n개의 포도주 중에서 규칙에 따라 포도주를 마실 때 포도주의 최댓값
d[n] = max(d[n-1], d[n-2]+p[n], d[n-3]+p[n-1]+p[n])
d[0] = 0
d[1] = p[1]
d[2] = p[1] + p[2]

============================================================================
d[n] = max(d[n-1], d[n-2]+p[n], d[n-3]+p[n-1]+p[n])
1. d[n-1] : n번째에서 포도주를 마시지 않는 경우이므로, n-1번째 포도주 양의 최댓값을 가져온다.
2. d[n-2]+p[n] : n번째에서 포도주를 1번 연속으로 마시는 경우이다.
이때, 위 조건을 만족시키기 위해서는 n-1번째에서 포도주를 마시지 않아야 하므로,
n-2번째 포도주 양의 최댓값에 n번째 포도주 양을 더한다.
3. d[n-3]+p[n-1]+p[n] : n번째에서 포도주를 2번 연속으로 마시는 경우이다.
위 조건을 만족시키기 위해서는 n-2번째에서 포도주를 마시지 않아야 하므로,
n-3번째 포도주 양의 최댓값에 n-1번째 포도주 양과 n번째 포도주 양을 더한다.
============================================================================
*/

#include <iostream>
#include <array>
#include <algorithm>

using namespace std;
array<int, 10001> d, p;

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> p[i];
    d[1] = p[1];
    d[2] = p[1] + p[2];
    for(int i = 3; i <= n; ++i)
    {
        d[i] = max({d[i-1], d[i-2]+p[i], d[i-3]+p[i-1]+p[i]});
    }
    cout << d[n] << '\n';
}