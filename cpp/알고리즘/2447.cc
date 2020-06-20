#include <iostream>
#include <array>

using namespace std;
array<array<char, 2187>, 2187> space;

void star(const int y, const int x, const int len, const char ch)
{
    if(len == 3)
    {
        for(int i = 0; i < 3; ++i) space[y][x+i] = ch;
        space[y+1][x] = ch;
        space[y+1][x+1] = ' ';
        space[y+1][x+2] = ch;
        for(int i = 0; i < 3; ++i) space[y+2][x+i] = ch;
        return;
    }
    for(int i = 0; i < len; i += len/3)
    {
        for(int j = 0; j < len; j += len/3)
        {
            if(j == len/3 && i >= len/3 && i < len/3*2) star(y + i, x + j, len/3, ' ');
            else star(y + i, x + j, len/3, ch);
        }
    }
}
int main()
{
    int n;
    cin >> n;
    star(0,0,n,'*');
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j) cout << space[i][j];
        cout << '\n';
    }
    return 0;
}