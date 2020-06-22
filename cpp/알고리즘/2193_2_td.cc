#include <iostream>
#include <array>

using namespace std;
array<long long, 91> d;

long long sol(const int n)
{
    if(n == 1 or n == 2) return 1;
    if(d[n] != -1) return d[n];
    d[n] = sol(n-1) + sol(n-2);
    return d[n];
}

int main()
{
    for(int i = 1; i < 91; ++i) d.fill(-1);
    int n;
    cin >> n;
    cout << sol(n) << '\n';
}