#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    unsigned long long int a, b, c, ans;
    cin >> a >> b >> c;
    ans = 1;
    while(b != 0)
    {
        if(b == 1) ans = (ans * a) % c;
        a = (a * a) % c;
        b >>= 1;
    }

    return 0;
}