#include <iostream>
#include <stack>
#include <cstdio>

using namespace std;
int main()
{
    int times;
    stack<char> left, right, temp;
    char c;
    while((c = getchar()) != '\n')
    {
        left.push(c);
    }
    fflush(stdin);
    cin >> times;

    while(times--)
    {
        char c;
        cin >> c;
        switch(c)
        {
            case 'L':
                if(!left.empty())
                {
                    right.push(left.top());
                    left.pop();
                }
                break;
            case 'D':
                if(!right.empty())
                {
                    left.push(right.top());
                    right.pop();
                }
                break;
            case 'B':
                if(!left.empty())
                {
                    left.pop();
                }
                break;
            case 'P':
                char ch;
                cin >> ch;
                left.push(ch);
                break;
        }
    }
    while(!left.empty())
    {
        temp.push(left.top());
        left.pop();
    }
    while(!temp.empty())
    {
        cout << temp.top();
        temp.pop();
    }
    while(!right.empty())
    {
        cout << right.top();
        right.pop();
    }
    return 0;
}