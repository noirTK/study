#include <iostream>

using namespace std;

bool isPrime(int num)
{
    if(num < 2) return false;
    for(int i = 2; i*i <= num; ++i)
    {
        if(num % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int times;
    cin >> times;
    int primes = 0;
    while(times--)
    {
        int num;
        cin >> num;
        if(isPrime(num)) ++primes;
    }
    cout << primes << '\n';
    return 0;
}