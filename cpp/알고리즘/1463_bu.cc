/*
https://www.acmicpc.net/problem/1463
1463 다이나믹 문제풀이 - Bottom Up
d[i] = 정수 i에 대해 1로 만드는 연산의 최솟값
d[i] = min(d[i-1]+1, d[i/3]+1, d[i/2]+1)
d[1] = 0
*/

#include <iostream>
#include <array>
using namespace std;
array<int, 1000001> d;
int main()
{
    int n;
    cin >> n;
    d[1] = 0;
    for(int i = 2; i <= n; ++i)
    {
        d[i] = d[i-1] + 1;
        if(i % 3 == 0 && d[i] > d[i/3] + 1) d[i] = d[i/3] + 1;
        if(i % 2 == 0 && d[i] > d[i/2] + 1) d[i] = d[i/2] + 1;
    }
    cout << d[n] << '\n';
    return 0;
}