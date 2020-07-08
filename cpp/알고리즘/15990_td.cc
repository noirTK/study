/*
https://www.acmicpc.net/problem/15990
15990 다이나믹 문제풀이 Top Down
sol(n,t) 정수 n, t에 대하여 정수 n의 끝자리 값이 k일 때, 1,2,3의 합으로 나타내는 방법의 수
sol(n,1) = sol(n-1,2) + sol(n-1,3)
sol(n,2) = sol(n-2,1) + sol(n-2,3)
sol(n,3) = sol(n-3,1) + sol(n-3,2)
sol(1,1) = sol(2,2) = sol(3,1) = sol(3,2) = sol(3,3) = 1
sol(1,2) = sol(1,3) = sol(2,1) = sol(2,3) = 0
*/

#include <iostream>
#include <array>

using namespace std;
const long long mod = 1000000009LL;
array<array<long long, 4>, 100001> d;

long long sol(const int n, const int t)
{
    if(n == 1 || n == 2) 
    {
        if(n == t) return 1;
        else return 0;
    }
    if(n == 3) return 1;
    if(d[n][t] != -1) return d[n][t];
    if(t == 1) d[n][t] = sol(n-1,2) + sol(n-1,3);
    if(t == 2) d[n][t] = sol(n-2,1) + sol(n-2,3);
    if(t == 3) d[n][t] = sol(n-3,1) + sol(n-3,2);
    d[n][t] %= mod;
    return d[n][t];
}

int main()
{
    int t;
    cin >> t;
    for(int i = 1; i <= 100000; ++i) d[i].fill(-1);
    while(t--)
    {
        int n;
        cin >> n;
        cout << (sol(n,1) + sol(n,2) + sol(n,3)) % mod << '\n';
    }
    return 0;
}