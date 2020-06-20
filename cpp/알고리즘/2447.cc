#include <iostream>
#include <array>

using namespace std;
array<array<char,2187>,2187>space;
void star(int y, int x, int length, char fill)
{
    if(length == 3)
    {
        for(int i = 0; i < 3; ++i)
        {
            space[y][x+i] = fill;
        }
        space[y+1][x] = fill;
        space[y+1][x+1] = ' ';
        space[y+1][x+2] = fill;
        for(int i = 0; i < 3; ++i)
        {
            space[y+2][x+i] = fill;
        }
        return;
    }
    for(int i = 0; i < length; i+= length/3)
    {
        star(y , x+i ,length/3, fill);
    }

    star(y+length/3, x, length/3, fill);
    star(y+length/3, x + length/3, length/3, ' ');
    star(y+length/3, x + length/3*2, length/3, fill);

    for(int i = 0; i < length; i+= length/3)
    {
        star(y + length/3*2 , x+i ,length/3, fill);
    }
}
int main()
{
    int n;
    cin >> n;
    star(0,0,n,'*');
    for(int y = 0; y < n; ++y)
    {
        for(int x = 0; x < n; ++x)
        {
            cout << space[y][x];
        }
        cout << '\n';
    }
    return 0;
}