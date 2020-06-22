#include <iostream>
#include <array>

using namespace std;
array<long long, 91> d;

int main()
{
    int n;
    cin >> n;
    d[1] = d[2] = 1;
    for(int i = 3; i <= n; ++i) d[i] = d[i-1] + d[i-2];
    cout << d[n] << '\n';
    return 0;
}