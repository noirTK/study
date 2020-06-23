#include <iostream>
#include <array>
using namespace std;
array<array<char, 397>, 399> space;

void sol(const int y, const int x, const int n)
{
    if(n == 1)
    {
        space[y][x] = space[y+1][x] = space[y+2][x] = '*';
        return;
    }
    for(int i = 0; i < 4*n-1; ++i)
    {
        for(int j = 0; j < 4*n-3; ++j)
        {
            if(i == 0 || i == 4*n-2 || j == 0 || j == 4*n-4) space[y+i][x+j] = '*';
            else space[y+i][x+j] = ' ';
        }
    }
    space[y+1][x+4*n-4] = ' ';
    space[y+2][x+4*n-5] = '*';
    sol(y+2, x+2, n-1);
}

int main()
{
    int n;
    cin >> n;
    sol(0, 0, n);
    if(n == 1) 
    {
        cout << '*' << '\n';
        return 0;
    }

    for(int y = 0; y < 4*n-1; ++y)
    {
        if(y == 1)
        {
            cout << space[1][0] << '\n';
            continue;
        }
        for(int x = 0; x < 4*n-3; ++x) cout << space[y][x];
        cout << '\n';
    }
    return 0;
}