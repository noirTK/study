#include <iostream>
#include <array>

using namespace std;
array<int, 100001> p, d;

int sol(const int n)
{
    if(n == 1)
    {
        d[1] = p[1];
        return d[1];
    }
    if(d[n] != -1) return d[n];
    d[n] = (sol(n-1)+p[n] > p[n] ? sol(n-1)+p[n] : p[n]);
    return d[n];
}
int main()
{
    d.fill(-1);
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        int t;
        cin >> t;
        p[i] = t;
    }
    sol(n);
    int ans;
    for(int i = 1; i <= n; ++i) if(i == 1 || ans < d[i]) ans = d[i];
    cout << ans << '\n';
    return 0;
}