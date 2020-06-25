#include <iostream>
#include <array>
#include <algorithm>

using namespace std;
array<int, 1001> p, d;
int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> p[i];
    for(int i = 1; i <= n; ++i)
    {
        d[i] = 1;
        for(int j = 1; j < i; ++j)
        {
            if(d[i] <= d[j] && p[j] > p[i]) d[i] = d[j] + 1;
        }
    }
    cout << *max_element(d.cbegin(), d.cend()) << '\n';
    return 0;
}