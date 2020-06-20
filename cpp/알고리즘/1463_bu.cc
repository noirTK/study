#include <iostream>
#include <array>

using namespace std;
array<int, 1000001> arr = {0};
int main()
{
    int n;
    cin >> n;
    arr[1] = 0;
    for(int i = 2; i <= n; ++i)
    {
        arr[i] = arr[i-1] + 1;
        if(i % 2 == 0 && arr[i] > arr[i/2] + 1)
        {
            arr[i] = arr[i/2] + 1;
        }
        if(i % 3 == 0 && arr[i] > arr[i/3] + 1)
        {
            arr[i] = arr[i/3] + 1;
        }
    }
    cout << arr[n] << '\n'; 
    return 0;
}