#include <iostream>
#include <array>
#include <algorithm>
using namespace std;
array<array<int, 3>, 1001> d, p;

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> p[i][0] >> p[i][1] >> p[i][2];
    for(int i = 0; i < 3; ++i) d[1][i] = p[1][i];
    for(int i = 2; i <= n; ++i)
    {
        d[i][0] = min({d[i-1][1], d[i-1][2]}) + p[i][0];
        d[i][1] = min({d[i-1][0], d[i-1][2]}) + p[i][1];
        d[i][2] = min({d[i-1][1], d[i-1][0]}) + p[i][2];
    }
    cout << min({d[n][0], d[n][1], d[n][2]}) << '\n';
    return 0;
}