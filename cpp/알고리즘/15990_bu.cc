#include <iostream>
#include <array>

using namespace std;
const long long mod = 1000000009LL;
array<array<long long, 4>, 100001> d;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        d[0][1] = d[0][2] = d[0][3] = d[1][2] = d[1][3] = d[2][3] = 0;
        for(int i = 1; i <= n; ++i)
        {
            if(i >= 1)
            {
                if(i == 1) d[i][1] = 1;
                else d[i][1] = d[i-1][2] + d[i-1][3];
                d[i][1] %= mod;
            }
            if(i >= 2)
            {
                if(i == 2) d[i][2] = 1;
                else d[i][2] = d[i-2][1] + d[i-2][3];
                d[i][2] %= mod;
            }
            if(i >= 3)
            {
                if(i == 3) d[i][3] = 1;
                else d[i][3] = d[i-3][1] + d[i-3][2];
                d[i][3] %= mod;
            }
        }
        cout << (d[n][1] + d[n][2] + d[n][3]) % mod << '\n';
    }
    return 0;
}