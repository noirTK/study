#include <iostream>
#include <array>
#include <algorithm>
using namespace std;
array<array<int, 3>, 1001> d, p;
int sol(const int n, const int c, const int last)
{
    if(n == 1)
    {
        if(c == last) return 1001;
        else return p[1][c];
    }
    if(d[n][c] != -1) return d[n][c];
    if(c == 0) d[n][c] = min(sol(n-1,1,last), sol(n-1,2,last)) + p[n][c];
    if(c == 1) d[n][c] = min(sol(n-1,0,last), sol(n-1,2,last)) + p[n][c];
    if(c == 2) d[n][c] = min(sol(n-1,0,last), sol(n-1,1,last)) + p[n][c];
    return d[n][c];
}

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> p[i][0] >> p[i][1] >> p[i][2];
    int ans;
    for(int i = 0; i <= 2; ++i)
    {
        for(int j = 1; j < 1001; ++j) d[j].fill(-1);
        if(i == 0 || ans > sol(n,i,i)) ans = sol(n,i,i);
    }
    cout << ans << '\n';
    return 0;
}