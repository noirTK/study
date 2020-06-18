#include <iostream>
#include <array>

using namespace std;

void findPrime(array<bool,1001>* const nums)
{
    nums->fill(true);
    nums->at(0) = nums->at(1) = false;
    for(int i = 2; i < nums->size(); ++i)
    {
        if((*nums)[i] == true)
        {
            for(int j = i*i; j < nums->size(); j+=i) nums->at(j) = false;
        }
        
    }

}
int main()
{
    array<bool,1001>* nums = new array<bool,1001>;
    findPrime(nums);
    int times;
    cin >> times;
    int primeNum = 0;
    while(times--)
    {
        int num;
        cin >> num;
        if(nums->at(num)) ++primeNum;
    }
    cout << primeNum << '\n';
    delete nums;
    return 0;
}