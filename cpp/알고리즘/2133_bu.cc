#include <iostream>
#include <array>

using namespace std;
array<int, 31> d;
int main()
{
    int n;
    cin >> n;
    if(n % 2 == 1)
    {
        cout << 0 << '\n';
        return 0;
    }
    d[0] = 1;
    for(int i = 2; i <= n; i+=2)
    {
        d[i] = d[i-2] * 3;
        for(int k = 4; k <= i; k+=2) d[i] += d[i-k] * 2;
    }
    cout << d[n] << '\n';
    return 0;
}