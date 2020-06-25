#include <iostream>
#include <array>
#include <algorithm>

using namespace std;
array<array<int, 3>, 10001> d;
array<int, 10001> p;
int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> p[i];
    d[1][1] = p[1];
    for(int i = 2; i <= n; ++i)
    {
        d[i][2] = d[i-1][1] + p[i];
        d[i][1] = d[i-1][0] + p[i];
        d[i][0] = max({d[i-1][0], d[i-1][1], d[i-1][2]});
    }
    cout << max({d[n][0], d[n][1], d[n][2]}) << '\n';
    return 0;
}