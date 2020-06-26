#include <iostream>
#include <array>
using namespace std;
array<int, 1001> d1, d2, p;

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> p[i];
    for(int i = 1; i <= n; ++i)
    {
        d1[i] = 1;
        for(int j = 1; j < i; ++j)
        {
            if(p[i] > p[j] && d1[i] <= d1[j]) d1[i] = d1[j] + 1;
        }
    }
    for(int i = n; i > 0; --i)
    {
        d2[i] = 1;
        for(int j = n; j > i; --j)
        {
            if(p[i] > p[j] && d2[i] <= d2[j]) d2[i] = d2[j] + 1;
        }
    }
    int ans;
    for(int i = 1; i <= n; ++i)
    {
        if(i == 1 || ans < d1[i] + d2[i] - 1)  ans = d1[i] + d2[i] - 1;
    }
    cout << ans << '\n';
    return 0;
}