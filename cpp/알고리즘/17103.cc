#include <iostream>
#include <array>
#include <vector>
using namespace std;

void checkPrime(array<bool, 1000001>* isprime, vector<int>* prime)
{
    isprime->fill(true);
    isprime->at(0) = isprime->at(1) = false;
    for(int i = 2; i < isprime->size(); ++i)
    {
        if(isprime->at(i) == true) 
        {
            prime->push_back(i);
            for(int j = i*2; j < isprime->size(); j += i)
            {
                isprime->at(j) = false;
            }
        }
    }
}
int main()
{
    array<bool, 1000001>* isprime = new array<bool, 1000001>;
    vector<int>* prime = new vector<int>;
    checkPrime(isprime, prime);
    int t;
    cin >> t;
    while(t--)
    {
        int ans = 0;
        int even;
        cin >> even;
        
        for(int i = 0; i < prime->size(); ++i)
        {
            if(even-prime->at(i)>=2 && isprime->at(even-prime->at(i)))
            {
                if(even-prime->at(i) <= prime->at(i)) ++ans;
            }
        }
        cout << ans << '\n';
    }
    delete isprime;
    delete prime;
    return 0;
}