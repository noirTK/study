#include <iostream>
#include <array>
using namespace std;
array<int, 1001> d1, d2, p;
int up(const int n)
{
    if(d1[n] != -1) return d1[n];
    d1[n] = 1;
    for(int j = 1; j < n; ++j)
    {
        if(p[n] > p[j] && d1[n] <= up(j)) d1[n] = up(j) + 1;
    }
    return d1[n];
}

int down(const int n, const int last)
{
    if(d2[n] != -1) return d2[n];
    d2[n] = 1;
    for(int j = last; j > n; --j)
    {
        if(p[n] > p[j] && d2[n] <= down(j, last)) d2[n] = down(j, last) + 1;
    }
    return d2[n];
}

int main()
{
    d1.fill(-1);
    d2.fill(-1);
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> p[i];
    for(int i = 1; i <= n; ++i) up(i);
    for(int i = n; i > 0; --i) down(i, n);
    int ans;
    for(int i = 1; i <= n; ++i) if(i == 1 || ans < d1[i] + d2[i] - 1) ans = d1[i] + d2[i] - 1; 
    cout << ans << '\n';
    return 0;
}