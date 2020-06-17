#include <iostream>
#include <stack>
#include <string>

using namespace std;

int operations(const char op)
{
    switch(op)
    {
        case '(': return 0; // '('는 항상 스택 안에 있어야 하므로
        case '/': case '*': return 2;
        case '+': case '-': return 1;
    }
    return -1;
}

int main()
{
    stack<char> s;
    string ex;
    getline(cin, ex);
    for(char ch : ex)
    {
        if(ch>='A'&&ch<='Z')
        {
            cout << ch;
        }
        else if(ch == ')')
        {
            while(s.top() != '(')
            {
                cout << s.top();
                s.pop();
            }
            s.pop();
        }
        else if(ch == '(')
        {
            s.push(ch);
        }
        else
        {
            // 연산자 우선순위가 빠를 수록 operations는 크다.
             while(!s.empty() && operations(ch) <= operations(s.top()))
            {
                cout << s.top();
                s.pop();
            }
            s.push(ch);
        }
    }
    while(!s.empty())
    {
        cout << s.top();
        s.pop();
    }
    cout << '\n';

    return 0;
}