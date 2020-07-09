/*
https://www.acmicpc.net/problem/2225
2225 다이나믹 문제풀이 Bottom Up
d[n][k] 정수 n에 대하여 0에서 n미만의 수 k개 더해서 합이 n이 되는 경우의 수
d[n][k] = Σ d[n-L][k-1] (0 <= L <= n, k != -1)
d[S][1] = 1 (0 <= S <= n)
*/

#include <iostream>
#include <array>

using namespace std;
const long long mod = 1000000000LL;
array<array<long long, 201>, 201> d;

int main()
{
    int n, k;
    cin >> n >> k;
    
    for(int i = 0; i <= n; ++i)
    {
        for(int j = 1; j <= k; ++j)
        {
            if(j == 1) 
            {
                d[i][j] = 1;
                continue;
            }
            d[i][j] = 0;
            for(int L = 0; L <= i; ++L)
            {
                d[i][j] += d[i-L][j-1];
                d[i][j] %= mod;
        }
    }
    cout << d[n][k] << '\n';
    return 0;
}