#include <iostream>
#include <array>
#include <algorithm>
using namespace std;
array<int, 1001> p, d;

int sol(const int n)
{
    if(d[n] != -1) return d[n];
    d[n] = 1;
    for(int j = 1; j < n; ++j)
    {
        if(sol(j) >= d[n] && p[j] < p[n]) d[n] = sol(j) + 1;
    }
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
    cout << *max_element(d.begin(),d.end()) << '\n';
    return 0;
}