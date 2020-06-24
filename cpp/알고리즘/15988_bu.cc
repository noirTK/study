#include <iostream>
#include <array>

using namespace std;
array<long long, 1000001> d;
const long long mod = 1000000009LL;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        d[0] = d[1] = 1;
        d[2] = 2;
        for(int i = 3; i <= n; ++i)
        {
            d[i] = 0;
            for(int j = 1; j <= 3; ++j) d[i] += d[i-j];
            d[i] %= mod;
        }
        cout << d[n] << '\n';
    }
    return 0;
}