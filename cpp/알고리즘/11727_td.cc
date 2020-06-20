#include <iostream>
#include <array>

using namespace std;
array<int, 1001> d = {0};

int sol(const int n)
{
    if(n == 0 or n == 1) return 1;
    if(d[n] > 0) return d[n];
    d[n] = (sol(n-1) + sol(n-2) * 2) % 10007;
    return d[n];
}

int main()
{
    int n;
    cin >> n;
    cout << sol(n) << '\n';
    return 0;
}