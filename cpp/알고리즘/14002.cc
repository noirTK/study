#include <iostream>
#include <array>

using namespace std;
array<int, 1001> d, p, v;

int sol(const int n)
{
    if(d[n] != -1) return d[n];
    d[n] = 1;
    for(int j = 1; j < n; ++j)
    {
        if(sol(j) >= d[n] && p[j] < p[n]) 
        {
            d[n] = sol(j) + 1;
            v[n] = j;
        }
    }
    return d[n];
}

void go(const int n)
{
    if(n == 0) return;
    go(v[n]);
    cout << p[n] << ' ';
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
    int maxIndex, ans;
    for(int i = 1; i <= n; ++i) 
    {
        if(i == 1 || d[maxIndex] < d[i])
        {
            maxIndex = i;
            ans = d[maxIndex];
        }
    }
    cout << ans << '\n';
    go(maxIndex);
    cout << '\n';
    return 0;
}