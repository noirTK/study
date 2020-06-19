#include <iostream>
#include <stack>

using namespace std;
int main()
{
    stack<char> s;
    int num, div;
    cin >> num >> div;
    while(num != 0)
    {
        int n = num % div;
        if( n >= 10 && n < 36)
        {
            s.push('A'+n-10);
        }
        else s.push(n+'0');
        num /= div;
    }
    while(!s.empty())
    {
        cout << s.top();
        s.pop();
    }
    return 0;
}