#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main()
{
    string input;
    cin >> input;
    stack<int> s;
    bool first = true;
    for(char ch : input)
    {
        int token = ch - '0';
        while(token > 0)
        {
            s.push(token%2);
            token /= 2;
        }
        if(first) first = !first;
        else while(s.size() != 3) s.push(0);
        while(!s.empty())
        {
            cout << s.top();
            s.pop();
        }
    }
    cout << (input == "0" ? "0\n" : "\n");
    return 0;
}