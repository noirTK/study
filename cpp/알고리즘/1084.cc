#include <iostream>
#include <string>

using namespace std;
int main()
{
    string num[4];
    cin >> num[0] >> num[1] >> num[2] >> num[3];
    cout << stoull(num[0]+num[1])+stoull(num[2]+num[3]) << '\n';
    return 0;
}