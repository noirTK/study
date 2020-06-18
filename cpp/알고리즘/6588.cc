#include <iostream>
#include <array>
#include <string>

using namespace std;

void checkPrime(array<bool,1000001>* const nums)
{
    nums->fill(true);
    nums->at(0) = nums->at(1) = false;
    for(int i = 2; i < nums->size(); ++i) if(nums->at(i) == true) for(int j = i*2; j < nums->size(); j+=i) nums->at(j) = false;
    nums->at(2) = false;
}

int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    string input;
    array<bool,1000001>* nums = new array<bool,1000001>;
    checkPrime(nums);
    while(getline(cin,input) && input != "0")
    {
        bool found = false;
        int num = stoi(input);
        for(int i = 3; i <= num-3; i+=2)
        {
            if(nums->at(i) && nums->at(num-i) && !found)
            {
                found = true;
                cout << num << " = " << i << " + " << num-i << '\n';
                break;
            }
        }
        if(!found) cout << "Goldbach's conjecture is wrong.\n";
    }
    delete nums;
    return 0;
}