#include <iostream>
#include <array>

using namespace std;
array<array<long long, 201>, 201> d;
const long long mod = 1000000000LL;

long long sol(const int n, const int k)
{
    if(k == 1) return 1;
    if(d[n][k] != -1) return d[n][k];
    d[n][k] = 0;
    for(int i = 0; i <= n; ++i) d[n][k] += sol(n-i,k-1);
    d[n][k] %= mod;
    return d[n][k];
}
int main()
{
    for(int i = 0; i < 201; ++i) d[i].fill(-1);
    int n, k;
    cin >> n >> k;
    cout << sol(n, k) << '\n';
    return 0;
}