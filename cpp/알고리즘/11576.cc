#include <iostream>
#include <stack>
using namespace std;
int main()
{
    int from, to, times, dec;
    cin >> from >> to >> times;
    dec = 0;
    stack<string> s;
    while(times--)
    {
        int num;
        cin >> num;
        dec = dec * from + num;
    }

    while(dec != 0)
    {
        s.push(to_string(dec % to));
        dec /= to;
    }

    while(!s.empty())
    {
        cout << s.top();
        s.pop();
        cout << (s.empty() ? '\n' : ' ');
    }
    return 0;
}