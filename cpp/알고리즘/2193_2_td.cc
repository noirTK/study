/*
https://www.acmicpc.net/problem/2193
2193 다이나믹 문제풀이 Top Down 2
sol(n) n자리 수의 이친수의 개수
sol(n) = sol(n-1) + sol(n-2)
sol(1) = sol(2) = 1
==============================================================================
sol(n,t)를 n자리 수의 끝자리가 t일때의 이친수의 개수 라고 할 때,
sol(n,1) = sol(n-1,0), sol(n,0) = sol(n-1,0) + sol(n-1,1)을 만족한다. (단, n > 1)
sol(n) = sol(n,0) + sol(n,1) 이므로,
sol(n) = 2 * sol(n-1,0) + sol(n-1, 1)을 만족한다.
이때, sol(n-1,0) = sol(n-2,0) + sol(n-2,1) 역시 성립하므로,
sol(n) = sol(n-1,0) + sol(n-1,1) + sol(n-2,0) + sol(n-2,1)
즉, sol(n) = sol(n-1) + sol(n-2)이 된다. (단, n > 2)
==============================================================================
*/

#include <iostream>
#include <array>

using namespace std;
array<long long, 91> d;

long long sol(const int n)
{
    if(n == 1 || n == 2) return 1;
    if(d[n] != -1) return d[n];
    d[n] = sol(n-1) + sol(n-2);
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