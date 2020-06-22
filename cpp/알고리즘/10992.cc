#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n-1; ++i)
    {
        for(int j = 0; j < n+i; ++j)
        {
            if(j < n+i-1 and j+i != n-1) cout << ' ';
            else cout << '*';
        }
        cout << '\n';
    }
    for(int i = 0; i < 2*n-1; ++i) cout << '*';
    cout << '\n';
    return 0;
}