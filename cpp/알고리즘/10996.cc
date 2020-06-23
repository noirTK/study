#include <iostream>

using namespace std;
int main()
{
    int n;
    cin >> n;
    bool isStar = true;
    for(int i = 0; i <n*2; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
             cout << (isStar ? '*' : ' ');
             isStar = !isStar;
        }
        if(n % 2 == 0)isStar = !isStar;
        cout << '\n';
    }
    return 0;
}