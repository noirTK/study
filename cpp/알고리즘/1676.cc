#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int num;
    cin >> num;
    int nums2 = 0;
    int nums5 = 0;
    
    for(int i = 2; i <= num; i*=2) nums2 += num/i;
    for(int i = 5; i <= num; i*=5) nums5 += num/i;
    cout << (nums2 >= nums5 ? nums5 : nums2) << '\n'; 
    return 0;
}