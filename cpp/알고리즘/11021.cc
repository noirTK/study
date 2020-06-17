#include <iostream>
using std::cin;

int main()
{
    int t;
    cin >> t;
    for(int i = 1; i <= t; ++i)
    {
        int a, b;
        cin >> a >> b;
        std::cout << "Case #" << i << ": " << a + b << '\n'; 
    }
    return 0;
}