#include <iostream>
#include <array>

using namespace std;
array<array<char, 397>, 397> space;

void rec(const int y, const int x, const int n)
{
    if(n == 1)
    {
        space[y][x] = '*';
        return;
    }
    for(int i = 0; i < 4*n-3; ++i)
    {
        for(int j = 0; j < 4*n-3; ++j)
        {
            if(i == 0 || j == 0 || i == 4*n-4 || j == 4*n-4) space[y+i][x+j] = '*';
            else space[y+i][x+j] = ' ';
        }
    }
    rec(y+2, x+2, n-1);
}

int main()
{
    int n;
    cin >> n;
    rec(0, 0, n);
    for(int i = 0; i < 4*n-3; ++i)
    {
        for(int j = 0; j < 4*n-3; ++j) cout << space[i][j];
        cout << '\n';
    }
    return 0;
}