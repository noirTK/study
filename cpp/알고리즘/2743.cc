#include <iostream>
#include <string>

using namespace std;
int main()
{
    string input;
    int len = 0;
    cin >> input;
    for(int i = 0; input[i]; ++i) len++;
    cout << len << '\n';
    return 0;
}