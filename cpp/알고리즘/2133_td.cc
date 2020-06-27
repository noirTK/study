#include <iostream>
#include <array>

using namespace std;
array<int, 31> d;
int sol(const int n)
{
    if(n == 0) return 1;
    if(n % 2 == 1) return 0;
    if(d[n] != -1) return d[n];
    d[n] = 0;
    d[n] += sol(n-2) * 3;
    for(int i = 4; i <= n; i+=2) d[n] += sol(n-i) * 2;
    return d[n];
}

int main()
{
    d.fill(-1);
    int n;
    cin >> n;
    cout << sol(n) << '\n';
    return 0;
}