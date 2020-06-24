#include <iostream>
#include <array>
#include <algorithm>

using namespace std;
array<array<int, 3>, 100001> d, p;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        for(int i = 0; i < 2; ++i)
        {
            for(int j = 1; j <= n; ++j) cin >> p[j][i];
        }
        d[1][0] = p[1][0];
        d[1][1] = p[1][1];
        d[1][2] = 0;
        for(int i = 2; i <= n; ++i)
        {
            d[i][0] = max({d[i-1][1], d[i-1][2]}) + p[i][0];
            d[i][1] = max({d[i-1][0], d[i-1][2]}) + p[i][1];
            d[i][2] = max({d[i-1][0], d[i-1][1], d[i-1][2]});
        }
        cout << max({d[n][0], d[n][1], d[n][2]}) << '\n';
    }
    return 0;
}