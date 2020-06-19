#include <iostream>
#include <string>

using namespace std;
int main()
{
    string input;
    int div;
    cin >> input >> div;
    int ans = 0;
    for(int i = 0; i < input.size(); ++i)
    {
        ans = ans * div + (input[i] - (input[i] >= 'A' && input[i] <= 'Z' ? 'A'-10 : '0'));
    }
    cout << ans << '\n';
    return 0;
}