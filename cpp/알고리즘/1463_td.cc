#include <iostream>
#include <array>

using namespace std;
array<int,1000001> d = {0};
int goto1(const int n)
{
    if(n == 1) return 0;
    if(d[n] > 0) return d[n];
    d[n] = goto1(n-1) + 1;
    if(n % 2 == 0)
    {
        int temp = goto1(n/2) + 1;
        if(d[n] > temp) d[n] = temp;
    }
    if(n % 3 == 0)
    {
        int temp = goto1(n/3) + 1;
        if(d[n] > temp) d[n] = temp;
    }
    return d[n];
}

int main()
{
    int n;
    cin >> n;
    cout << goto1(n) << '\n';
    return 0;
}