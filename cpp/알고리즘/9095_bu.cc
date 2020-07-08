/*
https://www.acmicpc.net/problem/9095
9095 다이나믹 문제풀이 - Bottom Up
d[n] 정수 n에 대하여 1,2,3의 합으로 나타낼 수 있는 경우의 수
d[n] = d[n-3] + d[n-2] + d[n-1]
d[0] = d[1] = 1
d[2] = 2
*/

#include <iostream>
#include <array>

using namespace std;
array<int, 11> d;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        d[0] = d[1] = 1;
        d[2] = 2;
        for(int i = 3; i <= n; ++i)
        {
            d[i] = d[i-3] + d[i-2] + d[i-1];
        }
        cout << d[n] << '\n';
    }
    return 0;
}