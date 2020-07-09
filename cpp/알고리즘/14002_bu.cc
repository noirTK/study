/*
https://www.acmicpc.net/problem/14002
14002 다이나믹 문제풀이 Bottom Up
d[n] 길이가 n인 수열의 증가하는 부분수열의 길이
d[n] = max(d[L]+1, d[n]) (1 <= L < n)
stack을 이용하여 출력순서를 뒤집었다. (재귀호출도 가능.)
*/

#include <iostream>
#include <array>
#include <stack>

using namespace std;
array<int, 1001> p, d, a;
int main()
{
    stack<int> s;
    int n, index;
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> p[i];
    for(int i = 1; i <= n; ++i)
    {
        d[i] = 1;
        for(int L = 1; L < i; ++L)
        {
            if(p[L] < p[i] && d[L] >= d[i])
            {
                d[i] = d[L] + 1;
                a[i] = L;
            }
        }
    }
    for(int i = 1; i <= n; ++i)
    {
        if(i == 1 || d[index] < d[i]) index = i;
    }
    cout << d[index] << '\n';
    while(index != 0)
    {
        s.push(p[index]);
        index = a[index];
    }
    while(!s.empty())
    {
        cout << s.top() << ' ';
        s.pop();
    }
    return 0;
}