/*
https://www.acmicpc.net/problem/17404
17404 다이나믹 문제풀이 Bottom Up
d[n][color] : 마지막을 last로 색칠할 때, n번째에 color을 색칠할 경우의 색칠 비용의 최솟값
1. d[1][color]에서 color를 하나 선택할 경우, 무조건 특정 색깔을 처음에 선택해야 하므로, 나머지는 조건범위(1000 이하)보다 큰 수 1001로 초기화한다.
2. d[i][0] = min(d[i-1][1], d[i-1][2]) + p[i][0]
   d[i][1] = min(d[i-1][0], d[i-1][2]) + p[i][1]
   d[i][2] = min(d[i-1][0], d[i-1][1]) + p[i][2]
   (단, i >= 2 && i <= n)
3. 마지막은 처음에 선택할 색깔을 제외한 나머지에서 최솟값을 선택해야하므로, 
   처음에 선택했던 색 = color와 다른 경우를 각각 비교해서 최솟값을 ans에 할당한다.
   cf. (color == 0) ans = min(d[n][1], d[n][2])
       (color == 1) ans = min(d[n][0], d[n][2])
       (color == 2) ans = min(d[n][0], d[n][1])
*/

#include <iostream>
#include <array>
#include <algorithm>

using namespace std;
array<array<int, 3>, 1001> d, p;

int main()
{
    int n, ans;
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        cin >> p[i][0] >> p[i][1] >> p[i][2];
    }

    for(int color = 0; color < 3; ++color)
    {
        d[1][0] = d[1][1] = d[1][2] = 1001;
        d[1][color] = p[1][color];

        for(int i = 2; i <= n; ++i)
        {
            d[i][0] = min(d[i-1][1], d[i-1][2]) + p[i][0];
            d[i][1] = min(d[i-1][0], d[i-1][2]) + p[i][1];
            d[i][2] = min(d[i-1][0], d[i-1][1]) + p[i][2];
        }
        for(int i = 0; i < 3; ++i)
        {
            if(color == i) continue;
            ans = min(ans, d[n][i]);
        }
    }
    cout << ans << '\n';
    return 0;
}