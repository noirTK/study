#include <iostream>
#include <array>

using namespace std;
array<array<int, 3>, 100001> d;
const int mod = 9901;
int sol(const int n, const int t)
{
    if(n == 1) return 1;
    if(d[n][t] != -1) return d[n][t];
    if(t == 0) d[n][t] = sol(n-1, 1) + sol(n-1, 2);
    if(t == 1) d[n][t] = sol(n-1, 0) + sol(n-1, 2);
    if(t == 2) d[n][t] = sol(n-1, 0) + sol(n-1, 1) + sol(n-1, 2);
    d[n][t] %= mod;
    return d[n][t];
}

int main()
{
    for(int i = 1; i <= 100001; ++i) d[i].fill(-1);
    int n;
    cin >> n;
    cout << (sol(n,0) + sol(n,1) + sol(n,2)) % mod << '\n'; 
    return 0;
}