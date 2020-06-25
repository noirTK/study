#include <iostream>
#include <array>
#include <algorithm>

using namespace std;
array<array<int, 501>, 501> d, p;

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= i; ++j) cin >> p[i][j];
    }
    d[1][1] = p[1][1];
    for(int i = 2; i <= n; ++i)
    {
        for(int k = 1; k <= n; ++k)
        {
            if(k == 1) d[i][k] = d[i-1][1] + p[i][1];
            if(k == i) d[i][k] = d[i-1][i-1] + p[i][i];
            else d[i][k] = max({d[i-1][k-1], d[i-1][k]}) + p[i][k];
        }
    }
    int ans;
    for(int i = 1; i <= n; ++i) if(i == 1 || ans < d[n][i]) ans = d[n][i];
    cout << ans << '\n';
    return 0;
}