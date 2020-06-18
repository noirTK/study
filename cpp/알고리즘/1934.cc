#include <iostream>
#include <array>

using namespace std;
int gcd(int a, int b)
{
    if(b == 0) return a;
    else return gcd(b,a%b);
}

int main()
{
    int times;
    array<int, 2> nums;
    cin >> times;
    while(times--)
    {
        cin >> nums[0] >> nums[1];
        cout << nums[0]*nums[1]/gcd(nums[0], nums[1]) << '\n';
    }
    return 0;
}