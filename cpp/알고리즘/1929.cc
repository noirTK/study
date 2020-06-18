#include <iostream>
#include <array>
using namespace std;

void checkPrime(array<bool,1000001>* const nums)
{
    nums->fill(true);
    nums->at(0) = nums->at(1) = false;
    for(int i = 2; i < nums->size(); ++i)
    {
        if(nums->at(i) == true)
        {
            for(int j = i*2; j < nums->size() ; j+=i) nums->at(j) = false;
        }
    }  
};

int main()
{
    array<bool,1000001>* nums = new array<bool, 1000001>;
    checkPrime(nums);
    int min, max;
    cin >> min >> max;
    for(int it = min; it <= max; ++it)
    {
        if(nums->at(it) == true) cout << it << '\n';
    }
    delete nums;
    return 0;
}