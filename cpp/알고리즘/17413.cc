#include <iostream>
#include <stack>
#include <cstdio>
#include <string>

using namespace std;
int main()
{
    stack<char> s;
    string line;
    getline(cin, line);
    line+='\n';
    bool found = false;
    for(char ch : line)
    {
        
        if(ch == '<')
        {
            if(!s.empty())
            {
                while(!s.empty())
                {
                    cout << s.top();
                    s.pop();
                }
            }
            if(found == false) found = true;
            cout << ch;
        }
        else if(ch == '>')
        {
            found = false;
            cout << ch;
        }
        else if(ch == ' ' or ch == '\n')
        {
            while(!s.empty())
            {
                cout << s.top();
                s.pop();
            }
            cout << ch;
        }
        else
        {
            if(found == true) cout << ch;
            else s.push(ch);
        }
    }
    return 0;
}