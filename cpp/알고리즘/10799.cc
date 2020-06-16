#include <iostream>
#include <stack>
#include <cstdio>

using namespace std;
int main()
{
    char ch, lastest;
    stack<int> s;
    int tot = 0;
    while((ch = getchar()) != '\n')
    {
        if(lastest == '(' and ch == ')')
        {
            s.pop();
            if(!s.empty()) tot += s.top();
        }
        else
        {
            if(ch == '(')
            {
                if(s.empty()) s.push(1);
                else s.push(s.top()+1);
            }
            else
            {
                s.pop();
                ++tot;
            }   
        }
        lastest = ch;
    }
    cout << tot << '\n';
    return 0;
}