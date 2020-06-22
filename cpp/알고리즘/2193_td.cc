#include <iostream>
#include <array>

using namespace std;
array<array<long long ,2>, 91> d;

long long sol(const int n, const int t)
{
    if(n == 1) return (t == 1 ? 1 : 0);
    if(d[n][t] != -1) return d[n][t];
    if(t == 0) d[n][t] = sol(n-1, 0) + sol(n-1, 1);
    else d[n][t] = sol(n-1, 0);
    
    return d[n][t];
}

int main()
{
    for(int i = 1; i < 91; ++i) d[i].fill(-1);
    int n;
    cin >> n;
    cout << sol(n,0) + sol(n,1) << '\n';
    return 0;
}