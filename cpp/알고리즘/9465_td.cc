/*
https://www.acmicpc.net/problem/9465
9465 다이나믹 문제풀이 Top Down
sol(n,c) 2n 스티커 중에서 n번째 스티커를 선택하거나 선택하지 않았을 경우의 스티커 점수의 최댓값
sol(n,L) = max(sol(n-1,N), sol(n-1,R)) + p[n][L]
sol(n,R) = max(sol(n-1,N), sol(n-1,L)) + p[n][R]
sol(n,N) = max(sol(n-1,N), sol(n-1,R), sol(n-1,L))
sol(1,c) = p[1][c]
** 각각의 케이스t 마다 d[n][c] 값이 변하므로 반드시 각 케이스 마다 -1로 초기화해야 한다.
*/

#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

array<array<int, 3>, 100001> d, p;
enum choice {R = 0, L, N};

int sol(const int n, const int c)
{
    if(n == 1) return p[n][c];
    if(d[n][c] != -1) return d[n][c];
    if(c == L) d[n][c] = max(sol(n-1,N), sol(n-1,R)) + p[n][L];
    else if(c == R) d[n][c] = max(sol(n-1,N), sol(n-1,L)) + p[n][R];
    else if(c == N) d[n][c] = max({sol(n-1,N), sol(n-1,R), sol(n-1, L)});
    return d[n][c];
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        for(int j = R; j <= L; ++j)
        {
            for(int i = 1; i <= n; ++i)
            {
                cin >> p[i][j];
            }
        }
        for(int i = 1; i <= n; ++i) d[i].fill(-1);
        cout << max({sol(n,N), sol(n,R), sol(n,L)}) << '\n';
    }
    return 0;
}