/*
https://www.acmicpc.net/problem/1309
1309 다이나믹 문제풀이 Top Down
sol(n,s) 2xn 배열의 n번째 자리에 사자가 위치하거나 위치하지 않았을 경우의 자리배치 경우의 수
sol(n,N) = sol(n-1,R) + sol(n-1,L) + sol(n-1,N)
sol(n,L) = sol(n-1,R) + sol(n-1,N)
sol(n,R) = sol(n-1,L) + sol(n-1,N)
sol(1,N) = sol(1,L) = sol(1,R) = 1
*/

#include <iostream>
#include <array>

using namespace std;
const int mod = 9901;
array<array<int, 3>, 100001> d;
enum space { N = 0, R, L};

int sol(const int n, const int s)
{
    if(n == 1) return 1;
    if(d[n][s] != -1) return d[n][s];
    if(s == N) d[n][s] = sol(n-1,R) + sol(n-1,L) + sol(n-1,N);
    else if(s == L) d[n][s] = sol(n-1,R) + sol(n-1,N);
    else if(s == R) d[n][s] = sol(n-1,L) + sol(n-1,N);
    d[n][s] %= mod;
    return d[n][s];
}

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) d[i].fill(-1);
    cout << (sol(n,N) + sol(n,R) + sol(n,L)) % mod << '\n';
    return 0; 
}