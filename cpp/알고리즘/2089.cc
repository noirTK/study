#include <iostream>
#include <string>
#include <stack>

using namespace std;
int main()
{
    string input;
    cin >> input;
    int div = stoi(input);
    stack<int> s;
    if(div == 0) cout << 0;
    while(div != 0)
    {
        int rm = div % -2;
        if(rm < 0) rm += 2;
        s.push(rm);
        div = (div-rm)/-2;
    }
    while(!s.empty())
    {
        cout << s.top();
        s.pop();
    }
    return 0;
}