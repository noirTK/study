#include <iostream>
using namespace std;
int fac(int num)
{
    if(num == 0) return 1;
    return num*fac(num-1);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int num;
    cin >> num;
    cout << fac(num) << '\n';
    return 0;
}