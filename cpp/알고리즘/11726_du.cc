#include <iostream>
#include <array>

using namespace std;
int main()
{
    array<int, 1001> d = {0};
    int n;
    cin >> n;
    d[0] = d[1] = 1;
    for(int i = 2; i <= n; ++i)
    {
        d[i] = (d[i-1] + d[i-2]) % 10007;
    }

    cout << d[n] << '\n';
    return 0;
}