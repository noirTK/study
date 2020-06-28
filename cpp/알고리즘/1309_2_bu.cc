#include <iostream>
#include <array>

using namespace std;
const int mod = 9901;
array<int, 100001> s, d; 
int main()
{
    int n;
    cin >> n;
    d[0] = 1;
    d[1] = 2;
    s[0] = d[0];
    s[1] = d[1] + d[0];
    for(int i = 2; i <= n; ++i)
    {
        d[i] = d[i-1] + s[i-2] * 2;
        s[i] = s[i-1] + d[i];
        d[i] %= mod;
        s[i] %= mod;
    }
    cout << s[n] << '\n';
    return 0;
}