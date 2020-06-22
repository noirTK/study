#include <iostream>
#include <array>

using namespace std;
array<array<char, 6144>, 6144> space;
void sol(const int y, const int x, const int len, const char ch)
{
    if(len == 3)
    {
        space[y][x+2] = ch;
        space[y+1][x+1] = space[y+1][x+3] = ch;
        for(int i = 0; i < 5; ++i) space[y+2][x+i] = ch;
        return;
    }
    sol(y, x+len/2, len/2, ch);
    sol(y+len/2, x, len/2, ch);
    sol(y+len/2, x+len, len/2, ch);
}
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < 3073; ++i) space[i].fill(' ');
    sol(0, 0, n, '*');
    for(int y = 0; y < n; ++y)
    {
        for(int x = 0; x < 2*n; ++x)
        {
            cout << space[y][x];
        }
        cout << '\n';
    }
    return 0;
}