/*
https://www.acmicpc.net/problem/11726
11726 다이나믹 문제풀이 Bottom Up
d[n] = 정수 n에 대해 2xn 타일을 까는 방법의 수
d[n] = d[n-2] + d[n-1]
d[0] = d[1] = 1
*/

#include <iostream>
#include <array>

using namespace std;
array<int, 1001> d;
const int mod = 10007;

int main()
{
    int n;
    cin >> n;
    d[0] = d[1] = 1;
    for(int i = 2; i <= n; ++i) 
    {
        d[i] = d[i-1] + d[i-2];
        d[i] %= mod;
    }
    cout << d[n] << '\n';
    return 0;
}