/*
https://www.acmicpc.net/problem/15988
15988 다이나믹 문제풀이 Bottom Up
d[n] 정수 n에 대하여 1,2,3의 합으로 나타내는 방법 수
d[n] = Σ d[n-L] (1 <= L <= 3)
d[0] = d[1] = 1
d[2] = 2
=====================================================
t가 주워져서 t번 값을 print 해야하는데
각 t 마다 값이 항상 일정하므로 
t의 while문 밖에서 값을 미리 구해 놓고 바로 인덱스 접근하도록 했다.
while문 안에서 값을 구하면 시간초과 됨.
=====================================================
*/
#include <iostream>
#include <array>

using namespace std;
const long long mod = 1000000009LL;
array<long long, 1000001> d;

int main()
{
    d[0] = d[1] = 1;
    d[2] = 2;
    int t;
    cin >> t;
    for(int i = 3; i <= 1000000; ++i)
    {
        d[i] = 0;
        for(int L = 1; L <= 3; ++L)
        {
            d[i] += d[i-L];
            d[i] %= mod;
        }
    } 
    while(t--)
    {
        int n;
        cin >> n;
        cout << d[n] << '\n';
    }
    return 0;
}