#include <iostream>
#include <array>

using namespace std;
array<int, 1001> d = {0};
array<int, 1001> p;

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        int value;
        cin >> value;
        p[i] = value;
    }

    d[0] = 0;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= i; ++j)
        {
            if(d[i] < d[i-j] + p[j]) d[i] = d[i-j] + p[j];
        }
    }

    cout << d[n] << '\n';
    return 0;
}