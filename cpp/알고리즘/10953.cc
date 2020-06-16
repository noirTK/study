#include <iostream>

int main()
{
    using std::cin;
    int t;
    cin >> t;
    while(t--)
    {
        int a, b;
        cin >> a;
        cin.ignore(256, ',');
        cin >> b;

        std::cout << a+b << '\n';
    }
    return 0;
}