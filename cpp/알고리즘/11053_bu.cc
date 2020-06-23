#include <iostream>
#include <array>
#include <algorithm>

using namespace std;
array<int, 1001> p, d;

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
    for(int i = 1; i <= n; ++i)
    {
        d[i] = 1;
        for(int j = 1; j < i; ++j)
        {
            if(p[i] > p[j] && d[i] <= d[j]) d[i] = d[j] + 1;
        }
    }
    cout << *max_element(d.begin(), d.end());
    return 0;
}