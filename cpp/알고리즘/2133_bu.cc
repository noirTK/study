/*
https://www.acmicpc.net/problem/2133
2133 다이나믹 문제풀이 Bottom Up
d[n] 3xn 공간을 2x1의 타일로 채울 수 있는 경우의 수
d[0] = 1
n이 홀수일 때 : d[n] = 0
n이 짝수일 때 :
  1. d[n] = d[n-L]*3  (L == 2)
  2. d[n] = Σd[n-L]*2 (L >= 4)

n이 홀수일 때 3xn 타일을 전혀 채울 수 없으므로 0이다.
2x1타일로 맨 끝 3x(n-2)를 채우기 위해 필요한 타일 수는 3개이다.
2x1타일로 맨 끝 3x(n-L)을 채우기 위해 필요한 타일 수는 2개이다. (L >= 4, L은 짝수)
*/

#include <iostream>
#include <array>

using namespace std;
array<int, 31> d;

int main()
{
    int n;
    cin >> n;
    if(n % 2 != 0)
    {
        cout << 0 << '\n';
        return 0;
    }
    d[0] = 1;
    for(int i = 2; i <= n; i+=2)
    {
        for(int j = 2; j <= i; j+=2)
        {
            if(j == 2) d[i] += d[i-j]*3;
            else d[i] += d[i-j]*2;
        }
    }
    cout << d[n] << '\n';
    return 0;
}