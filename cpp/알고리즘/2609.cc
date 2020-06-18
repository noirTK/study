#include <iostream>
#include <array>

int GCD(int a, int b)
{
    while(b!=0)
    {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int GCD2(int a, int b)
{
    if(b==0) return a;
    else return GCD2(b,a%b);
}

int LCM(int a, int b)
{
    return a*b/GCD(a,b);
}

int main()
{
    std::array<int,3> nums;
    std::cin >> nums[0] >> nums[1];
    std::cout << GCD(nums[0],nums[1]) << '\n';
    std::cout << LCM(nums[0],nums[1]) << '\n';
    return 0;
}