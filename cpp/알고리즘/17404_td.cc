/*
https://www.acmicpc.net/problem/17404
17404 다이나믹 문제풀이 Top Down
sol(n, color, last) : 마지막을 last로 색칠할 때, n번째에 color을 색칠할 경우의 색칠 비용의 최솟값
sol(n, 0, last) = min(sol(n-1, 1, last), sol(n-1, 2, last)) + p[n][color]
sol(n, 1, last) = min(sol(n-1, 0, last), sol(n-1, 2, last)) + p[n][color]
sol(n, 2, last) = min(sol(n-1, 0, last), sol(n-1, 1, last)) + p[n][color]
sol(1, color, last)에서, color와 last색이 같을 경우, 원형 RGB 조건에 어긋나므로, 이 경우, 조건값의 범위(1000 이하)보다 더 큰 수를 리턴하여 해당 수를 선택하지 않도록 한다.

ans = last에 0색, 1색, 2색을 각각 선택할 경우의 최솟값 이므로,
ans = min(sol(n,0,0), sol(n,1,1), sol(n,2,2))이다.
이 때, 각각 경우에 따라 값이 달라지므로, -1로 초기화 이후에 값을 구한다.
*/

#include <iostream>
#include <array>
#include <algorithm>

using namespace std;
array<array<int, 3>, 1001> d, p;

int sol(const int n, const int color, const int last)
{
    if(n == 1) return (color == last) ? 1001 : p[n][color];
    if(d[n][color] != -1) return d[n][color];
    if(color == 0) d[n][color] = min(sol(n-1,1,last),sol(n-1,2,last));
    else if(color == 1) d[n][color] = min(sol(n-1,0,last),sol(n-1,2,last));
    else if(color == 2) d[n][color] = min(sol(n-1,0,last), sol(n-1,1,last));
    d[n][color] += p[n][color];
    return d[n][color];
}

int main()
{
    int n, ans;
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        cin >> p[i][0] >> p[i][1] >> p[i][2];
    }
    for(int i = 0; i <= 2; ++i)
    {
        for(int i = 1; i <= n; ++i) d[i].fill(-1);
        if(i == 0 || ans > sol(n,i,i)) ans = sol(n,i,i);
    }
    cout << ans << '\n';
    return 0;
}