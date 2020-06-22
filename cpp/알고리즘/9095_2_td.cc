#include <iostream>
#include <array>

using namespace std;
array<int , 11> d;

// D[n] : n일 때 1,2,3의 합으로 나타낼 수 있는 경우의 수 
// 점화식 ∑D[n-L] = D[n] (단, 1 <= L <= 3, 1 <= n <= 10)

int sol(const int n)
{
    if(n == 0) return 1;
    else if(n == 1) return 1;
    else if(n == 2) return 2;
    if(d[n] != -1) return d[n];
    d[n] = 0;
    for(int j = n - 3; j < n; ++j)
    {
        d[n] += sol(j);
    }
    return d[n];
}

int main()
{
    d.fill(-1);
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