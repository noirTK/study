#include <iostream>
#include <array>

using namespace std;
array<int, 100001> d;

int sol(const int n)
{
    if(n == 1) return 1;
    if(d[n] != -1) return d[n];
    d[n] = n;
    for(int k = 1; k*k <= n; ++k)
    {
        d[n] = (d[n] > sol(n-k*k) ? sol(n-k*k)+1 : d[n]); 
    }
    return d[n];
}

int main()
{
    d.fill(-1);
    int n;
    cin >> n;
    cout << sol(n) << '\n';
    return 0;
}