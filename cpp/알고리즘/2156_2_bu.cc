#include <iostream>
#include <array>
#include <algorithm>

using namespace std;
array<int, 10001> p, d;
int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> p[i];
    d[1] = p[1];
    d[2] = p[1] + p[2];
    for(int i = 3; i <= n; ++i) d[i] = max({d[i-1], d[i-2]+p[i], d[i-3]+p[i-1]+p[i]});
    cout << d[n] << '\n';
    return 0;
}