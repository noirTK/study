#include <iostream>
#include <array>
#include <algorithm>
using namespace std;
array<int, 1001> d, p;
int sol(const int n)
{
    if(d[n] != -1) return d[n];
    d[n] = 1;
    for(int j = 1; j < n; ++j) 
    {
        if(p[n] < p[j] && d[n] <= sol(j)) d[n] = sol(j) + 1;
    }
    return d[n];
}
int main()
{
    d.fill(-1);
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> p[i];
    for(int i = 1; i <= n; ++i) sol(i);
    cout << *max_element(d.cbegin(), d.cend()) << '\n';
    return 0;
}