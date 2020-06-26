#include <iostream>
#include <array>
#include <algorithm>
using namespace std;
array<int, 100001> p, front, back;
int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> p[i];
    int ans;
    front[1] = p[1];
    for(int i = 2; i <= n; ++i)
    {
        front[i] = (front[i-1] + p[i] > p[i] ? front[i-1] + p[i] : p[i]);
    }
    for(int i = 1; i <= n; ++i) if(i == 1 || ans < front[i]) ans = front[i];
    back[n] = p[n];
    for(int i = n-1; i >= 1; --i)
    {
        back[i] = (back[i+1] + p[i] > p[i] ? back[i+1] + p[i] : p[i]);
    }
    for(int i = 2; i < n; ++i)
    {
        if(ans < front[i-1] + back[i+1]) ans = front[i-1] + back[i+1];
    }
    cout << ans << '\n';
    return 0;
}