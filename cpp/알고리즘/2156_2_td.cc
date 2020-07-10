/*
https://www.acmicpc.net/problem/2156
2156 다이나믹 문제풀이2 Top Down
sol(n) n개의 포도주에서 규칙에 따라 포도주를 마실 경우, 마실 수 있는 포도주의 양의 최댓값
sol(n) = max(sol(n-1), sol(n-2)+p[n], sol(n-3)+p[n-1]+p[n])
sol(0) = 0
sol(1) = p[1]
sol(2) = p[1] + p[2]

============================================================================
sol(n) = max(sol(n-1), sol(n-2)+p[n], sol(n-3)+p[n-1]+p[n])
1. sol(n-1) : n번째에서 포도주를 마시지 않는 경우이므로, n-1번째 포도주 양의 최댓값을 가져온다.
2. sol(n-2)+p[n] : n번째에서 포도주를 1번 연속으로 마시는 경우이다.
이때, 위 조건을 만족시키기 위해서는 n-1번째에서 포도주를 마시지 않아야 하므로,
n-2번째 포도주 양의 최댓값에 n번째 포도주 양을 더한다.
3. sol(n-3)+p[n-1]+p[n] : n번째에서 포도주를 2번 연속으로 마시는 경우이다.
위 조건을 만족시키기 위해서는 n-2번째에서 포도주를 마시지 않아야 하므로,
n-3번째 포도주 양의 최댓값에 n-1번째 포도주 양과 n번째 포도주 양을 더한다.
============================================================================
*/

#include <iostream>
#include <array>
#include <algorithm>

using namespace std;
array<int, 10001> d, p;

int sol(const int n)
{
    if(n == 0) return 0;
    if(n == 1) return p[1];
    if(n == 2) return p[1] + p[2];
    if(d[n] != -1) return d[n];
    d[n] = max({sol(n-1), sol(n-2)+p[n], sol(n-3)+p[n-1]+p[n]});
    return d[n];
}

int main()
{
    int n;
    cin >> n;
    d.fill(-1);
    for(int i = 1; i <= n; ++i) cin >> p[i];
    cout << sol(n) << '\n';
    return 0;
}