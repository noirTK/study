/*
https://www.acmicpc.net/problem/9095
9095 다이나믹 문제풀이 Top Down
sol(n) 정수 n에 대하여 1,2,3의 합으로 나타낼 수 있는 경우의 수
sol(n) = sol(n-3) + sol(n-2) + sol(n-1)
sol(0) = sol(1) = 1
sol(2) = 2
*/
#include <iostream>
#include <array>

using namespace std;
array<int, 11> d;
int sol(const int n)
{
    if(n == 0 || n == 1) return 1;
    if(n == 2) return 2;
    if(d[n] != -1) return d[n];
    d[n] = sol(n-3) + sol(n-2) + sol(n-1);
    return d[n];
}
int main()
{
    int t, n;
    cin >> t;
    while(t--)
    {
        d.fill(-1);
        cin >> n;
        cout << sol(n) << '\n';
    }
    return 0;
}