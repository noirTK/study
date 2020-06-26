#include <iostream>
#include <array>

using namespace std;
array<int, 100001> p, front, back;

int sol(const int n)
{
    if(n == 1) 
    {
        front[1] = p[1];
        return p[1];
    }
    if(front[n] != -1) return front[n];
    front[n] = (sol(n-1) + p[n] > p[n] ? sol(n-1) + p[n] : p[n]);
    return front[n];
}

int sol2(const int n, const int last)
{
    if(n == last) 
    {
        back[n] = p[n];
        return p[n];
    }
    if(back[n] != -1) return back[n];
    back[n] = (sol2(n+1, last) + p[n] > p[n] ? sol2(n+1, last) + p[n] : p[n]);
    return back[n];
}
int main()
{
    front.fill(-1);
    back.fill(-1);
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> p[i];
    int ans;
    for(int i = 1; i <= n; ++i)
    {
        if(i == 1 || ans < sol(i)) ans = sol(i);
    }
    for(int i = n; i >= 1; --i) sol2(i, n);
    for(int i = 2; i < n; ++i)
    {
        if(ans < front[i-1] + back[i+1]) ans = front[i-1] + back[i+1];
    }
    cout << ans << '\n';
    return 0;
}