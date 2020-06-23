#include <iostream>
#include <array>
#include <cmath>
#include <string>
using namespace std;
array<array<char, 2045>,1024> space;
void sol(const int y, const int x, const int n)
{
    if(n == 1)
    {
        space[y][x] = '*';
        return;
    }
    int row = 1;
    for(int i = 1; i < n; ++i)row += pow(2,i);
    if(n % 2 == 1)
    {
        for(int i = 0; i < row; ++i)
        {
            for(int j = 0; j < row+i; ++j) 
            {
                if(j >= row+i-1 or j+i == row-1) space[y+i][x+j] = '*';
                else space[y+i][x+j] = ' ';
            }
            for(int i = 0; i < row*2-1; ++i) space[y+row-1][x+i] = '*';
        }
        sol(y+row/2,x+row/2+1,n-1);
    }
    else
    {
        for(int i = 0; i < row; ++i)
        {
            for(int j = 0; j < row*2-1-i; ++j)
            {
                if(row*2-2-i == j or j == i) space[y+i][x+j] = '*';
                else space[y+i][x+j] = ' ';
            }
        }
        for(int i = 0; i < row*2-1; ++i) space[y][x+i] = '*';
        sol(y+1,x+row/2+1,n-1);
    }
}

int main()
{
    int n;
    cin >> n;
    sol(0, 0, n);
    int row = 1;
    for(int i = 1; i < n; ++i) row += pow(2,i);
    for(int y = 0; y < row; ++y)
    {
        if(n % 2 == 0) for(int x = 0; x < 2*row-1-y; ++x) cout << space[y][x];
        else for(int x = 0; x < 2*row-(row-y); ++x) cout << space[y][x];
        cout << '\n';
    }
    return 0;
}