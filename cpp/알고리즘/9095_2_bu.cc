#include <iostream>
#include <array>

using namespace std;
array<int, 11> d;

// D[n] : n일 때 1,2,3의 합으로 나타낼 수 있는 경우의 수 
// 점화식 ∑D[n-L] = D[n] (단, 1 <= L <= 3, 1 <= n <= 10)

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
            d[i] = 0;
            for(int j = i - 3; j < i; ++j)
            {
                d[i] += d[j];
            }
        }
        cout << d[n] << '\n'; 
    }
    return 0;
}