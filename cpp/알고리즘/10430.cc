#include <iostream>
#include <array>
using namespace std;
int main()
{
    array<int,3> nums;
    cin >> nums.at(0) >> nums.at(1) >> nums.at(2);
    cout << (nums.at(0)+nums.at(1))%nums.at(2) << '\n';
    cout << (nums.at(0)%nums.at(2)+nums.at(1)%nums.at(2))%nums.at(2) << '\n';
    cout << (nums.at(0)*nums.at(1))%nums.at(2) << '\n';
    cout << (nums.at(0)%nums.at(2)*nums.at(1)%nums.at(2))%nums.at(2) << '\n';
    return 0;
}