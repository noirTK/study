#include <iostream>
using namespace std;
int main()
{
    int num1, num2, nums2, nums5;
    nums2 = nums5 = 0;
    cin >> num1 >> num2;

    for(long int i = 2; i <= num1; i *= 2) nums2 += num1/i;
    for(long int i = 5; i <= num1; i *= 5) nums5 += num1/i;

    for(long int i = 2; i <= num1-num2; i *= 2) nums2 -= (num1-num2)/i;
    for(long int i = 5; i <= num1-num2; i *= 5) nums5 -= (num1-num2)/i;

    for(long int i = 2; i <= num2; i *= 2) nums2 -= num2/i;
    for(long int i = 5; i <= num2; i *= 5) nums5 -= num2/i;

    cout << (nums2 >= nums5 ? nums5 : nums2) << '\n'; 
    return 0;
}