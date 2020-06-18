#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int num;
    cin >> num;
    int nums5 = 0;
    
    for(int i = 5; i <= num; i*=5) nums5 += num/i;
    cout << nums5 << '\n'; 
    return 0;
}