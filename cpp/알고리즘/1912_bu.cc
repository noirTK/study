#include <iostream>
#include <array>

using namespace std;
array<int, 100001> p, d;

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        int t;
        cin >> t;
        p[i] = t;
    }
    d[1] = p[1];
    for(int i = 2; i <= n; ++i)
    {
        if(d[i-1] + p[i] > p[i]) d[i] = d[i-1] + p[i];
        else d[i] = p[i];
    }
    int ans;
    for(int i = 1; i <= n; ++i) if(i == 1 || ans < d[i]) ans = d[i];
    cout << ans << '\n';
    return 0;
}