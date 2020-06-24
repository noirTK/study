#include <iostream>
#include <array>

using namespace std;
array<long long, 1000001> d;
const long long mod = 1000000009LL;
long long sol(const int n)
{
    if(n == 0 || n == 1) return 1;
    if(n == 2) return 2;
    if(d[n] != -1) return d[n];
    d[n] = 0;
    for(int i = 1; i <= 3; ++i) d[n] += sol(n-i);
    d[n] %= mod;
    return d[n];
}

int main()
{
    d.fill(-1);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        cout << sol(n) << '\n';
    }
    return 0;
}