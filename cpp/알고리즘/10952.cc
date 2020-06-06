#include <iostream>

int main()
{
    int a, b;
    while((std::cin >> a >> b) && !(a == 0 && b == 0))
        std::cout << a+b << '\n';
    return 0;
}