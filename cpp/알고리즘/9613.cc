#include <iostream>
using namespace std;

int gcd(const int lval, const int rval)
{   
    if(rval == 0) return lval;
    else return gcd(rval,lval%rval);
}
int main()
{
    int times;
    cin >> times;
    while(times--)
    {
        int count;
        cin >> count;
        int* numbers = new int[count];
        for(int i = 0; i < count; ++i)
        {
            int num;
            cin >> num;
            numbers[i] = num;
        }

        long int allgcdcount = 0;
        for(int i = 0; i < count-1; ++i)
        {
            for(int j = i+1; j < count; ++j)
            {
                allgcdcount += gcd(numbers[i],numbers[j]);
            }
        }
        cout << allgcdcount << '\n';
        delete[] numbers;
    }
    return 0;
}