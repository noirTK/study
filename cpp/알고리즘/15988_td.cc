/*
https://www.acmicpc.net/problem/15988
15988 다이나믹 문제풀이 Top Down
sol(n) 정수 n에 대하여 1, 2, 3의 합으로 나타내는 방법의 수
sol(n) = Σ sol(n-L) (1 <= L <= 3)
sol(0) = sol(1) = 1
sol(2) = 2
*/
#include <iostream>
#include <array>

using namespace std;
const long long mod = 1000000009LL;
array<long long, 1000001> d;

long long sol(const int n)
{
    if(n == 0 || n == 1) return 1;
    if(n == 2) return 2;
    if(d[n] != -1) return d[n];
    d[n] = 0;
    for(int L = 1; L <= 3; ++L)
    {
        d[n] += sol(n-L);
        d[n] %= mod;
    }
    return d[n];
}

int main()
{
    int t;
    cin >> t;
    d.fill(-1);
    while(t--)
    {
        int n;
        cin >> n;
        cout << sol(n) << '\n';
    }
    return 0;
}