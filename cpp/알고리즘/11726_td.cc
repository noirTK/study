/*
https://www.acmicpc.net/problem/11726
11726 다이나믹 문제풀이 - Top Down
d[n] = 정수 n에 대하여 2xn 타일을 까는 방법의 수
sol(n) = sol(n-1) + sol(n-2)
d[0] = d[1] = 1
*/

#include <iostream>
#include <array>

using namespace std;
array<int, 1001> d;
const int mod = 10007;

int sol(const int n)
{
    if(n == 0 || n == 1) return 1;
    if(d[n] != -1) return d[n];
    d[n] = sol(n-1) + sol(n-2);
    d[n] %= mod;
    return d[n];
}

int main()
{
    d.fill(-1);
    int n;
    cin >> n;
    cout << sol(n) << '\n';
    return 0;
}