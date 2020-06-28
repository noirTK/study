#include <iostream>
#include <array>

using namespace std;
const int mod = 9901;
array<int, 100001> s, d;

int sol(const int n)
{
    if(n == 1)
    {
        d[0] = 1;
        d[1] = 2;
        s[0] = 1;
        s[1] = d[1] + 1;
        return d[1];
    }
    if(d[n] != -1) return d[n];
    d[n] = sol(n-1) + s[n-2] * 2;
    s[n] = s[n-1] + d[n];
    d[n] %= mod;
    s[n] %= mod;
    return d[n];
}
int main()
{
    d.fill(-1);
    int n;
    cin >> n;
    sol(n);
    cout << s[n] << '\n';
    return 0;
}
