#include <iostream>
#include <array>

using namespace std;
array<int, 11> d;

int sol(const int n)
{
    if(n == 0 or n == 1) return 1;
    else if(n == 2) return 2;
    if(d[n] > 0) return d[n];
    d[n] = sol(n-1) + sol(n-2) + sol(n-3);
    return d[n];
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        cout << sol(n) << '\n';
    }
    return 0;
}