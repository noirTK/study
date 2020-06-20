#include <iostream>
#include <array>

using namespace std;
array<int, 11> d = {0};
int main()
{
    int t;
    cin >> t;
    d[0] = d[1] = 1;
    d[2] = 2;
    while(t--)
    {
        int n;
        cin >> n;
        for(int i = 3; i <= n; ++i)
        {
            d[i] = d[i-1] + d[i-2] + d[i-3];
        }
        cout << d[n] << '\n';
    }
    return 0;
}