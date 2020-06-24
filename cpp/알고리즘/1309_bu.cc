#include <iostream>
#include <array>

using namespace std;
const int mod = 9901;
array<array<int, 3>, 100001> d;
int main()
{
    int n;
    cin >> n;
    d[1][0] = d[1][1] = d[1][2] = 1;
    for(int i = 2; i <= n; ++i)
    {
        d[i][0] = (d[i-1][1] + d[i-1][2]) % mod;
        d[i][1] = (d[i-1][0] + d[i-1][2]) % mod;
        d[i][2] = (d[i-1][0] + d[i-1][1] + d[i-1][2]) % mod;
    }
    cout << (d[n][0] + d[n][1] + d[n][2]) % mod << '\n';
    return 0;
}