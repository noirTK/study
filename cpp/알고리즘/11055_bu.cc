#include <iostream>
#include <array>
#include <algorithm>
using namespace std;
array<int, 1001> d, p;
int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> p[i];
    for(int i = 1; i <= n; ++i)
    {
        d[i] = p[i];
        for(int j = 1; j < i; ++j)
        {
            if(p[j] < p[i] && d[j] + p[i] > d[i]) d[i] = d[j] + p[i];
        }
    }
    cout << *max_element(d.cbegin(), d.cend()) << '\n';
    return 0;
}