#include <iostream>
#include <array>
#include <string>
#include <vector>
using namespace std;

void checkPrime(array<bool,1000001>* const nums, vector<int>* prime)
{
    nums->fill(true);
    nums->at(0) = nums->at(1) = false;
    for(int i = 2; i < nums->size(); ++i)
    {
        if(nums->at(i) == true) 
        {
            prime->push_back(i);
            for(int j = i*2; j < nums->size(); j+=i) 
            {
                nums->at(j) = false;
            }
        }
    }
}

int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    string input;
    array<bool,1000001>* nums = new array<bool,1000001>;
    vector<int>* prime = new vector<int>;
    checkPrime(nums,prime);
    while(getline(cin,input) && input != "0")
    {
        bool found = false;
        int num = stoi(input);
        for(auto it = prime->begin(); *it < num && it != prime->end(); ++it)
        {
            if(nums->at(num-(*it)) && !found)
            {
                found = true;
                cout << num << " = " << *it << " + " << num-(*it) << '\n';
                break;
            }
        }
        if(!found) cout << "Goldbach's conjecture is wrong.\n";
    }
    delete nums;
    delete prime;
    return 0;
}