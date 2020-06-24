#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

array<array<int, 3>, 100001> d, p;

int sol(const int n, const int t)
{
    if(n == 1) return p[n][t];
    if(d[n][t] != -1) return d[n][t];
    if(t == 0) d[n][t] = max({sol(n-1,1), sol(n-1,2)}) + p[n][t];
    if(t == 1) d[n][t] = max({sol(n-1,0), sol(n-1,2)}) + p[n][t];
    if(t == 2) d[n][t] = max({sol(n-1,0),sol(n-1,1), sol(n-1,2)});
    return d[n][t];
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        for(int i = 1; i < 100001; ++i) d[i].fill(-1);
        int n;
        cin >> n;
        for(int i = 0; i < 2; ++i)
        {
            for(int j = 1; j <= n; ++j) cin >> p[j][i];
        }
        cout << max({sol(n,0), sol(n,1), sol(n,2)}) << '\n';
    }
    return 0;
}