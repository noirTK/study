#include <iostream>
#include <cstdio>

using namespace std;
int main()
{
    char ch;
    int len = 0;
    while((ch = getchar())!='\n') ++len;
    cout << len << '\n';
    return 0;
}