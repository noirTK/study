/*
https://www.acmicpc.net/problem/1309
1309 다이나믹 문제풀이2 Top Down
sol(n) 2xn 자리 배열에 n자리에 사자가 있는 경우 사자를 배치하는 경우의 수
array d[n] : sol(n)의 memorization array
array s[n-S] : Σ sol(n-L) (S <= L <= n)
sol(n) = sol(n-1) + 2*s[n-2] (단, n >= 2)
sol(0) = 1, sol(1) = 2
ans = sol(n) + s[n-1]
=========================================================================
sol(n)은 크게 두가지로 분류할 수 있는데,
1. 2x(n-1)자리에 사자가 없는 경우
2. 2x(n-1)자리에 사자가 있는 경우

1의 경우 2x(n-1)자리에 사자가 없으므로
2x(n-2)자리부터 2x1자리 까지 사자가 있을 수도 있고 없을 수도 있다.
이때 sol(n)은 n에 반드시 사자가 있는 경우 배치하는 경우의 수 이므로
이때 경우의 수는 sol(n-2) + sol(n-3) + ... + sol(0)이다.
** 2x(n-2)에 사자가 없는 경우의 경우의 수는 sol(n-3)와 같기 때문이다.
이때, 2xn에 사자는 왼쪽 오른쪽에 각각 1번씩 둘 수 있으므로, 위의 점화식에 2배를 한 것과 같다.
따라서 1의 경우의 수는 Σ 2*sol(n-L) (2 <= L <= n)이 된다.

2의 경우 2x(n-1)자리에 사자가 있으므로,
이는 sol(n-1)과 같다.
따라서 2의 경우의 수는 sol(n-1)이 된다.

sol(n)은 1의 경우의 수와 2의 경우의 수의 합이므로,
sol(n) = Σ 2*sol(n-L) + sol(n-1) (2 <= L <= n)이 된다.
array s[n-S] : Σ sol(n-L) (S <= L <= n)이라 정의할 때,
sol(n) = 2*s[n-2] + sol(n-1)이다. (n >= 2)

여기서 sol(n)이 비어있는 경우도 포함되므로,
위 문제의 답은 sol(n) + s[n-1]이 된다.
==========================================================================
*/

#include <iostream>
#include <array>

const int mod = 9901;
using namespace std;
array<int, 1000001> d, s;

int sol(const int n)
{
    if(n == 0) s[n] = d[n] = 1;
    else if(n == 1) 
    {
        d[n] = 2;
        s[n] = sol(0)+d[n];
    }
    if(d[n] != -1) return d[n];
    d[n] = sol(n-1) + 2*s[n-2];
    s[n] = s[n-1] + d[n];
    d[n] %= mod;
    s[n] %= mod;
    return d[n];
}

int main()
{
    int n;
    d.fill(-1);
    cin >> n;
    cout << (sol(n) + s[n-1]) % mod << '\n';
    return 0;
}