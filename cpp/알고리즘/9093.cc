#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;
int main()
{
    stack<char>* s = new stack<char>;
    int times;
    cin >> times;
    cin.ignore();
    while(times--)
    {
        char c;
        while((c = getchar()) != '\n')
        {
            if(c != ' ')
            {
                s->push(c);
            }
            else
            {
                while(!(s->empty()))
                {
                    cout << s->top();
                    s->pop();
                }
                cout << c;
            }
        }
        while(!(s->empty()))
        {
            cout << s->top();
            s->pop();
        }
        cout << c;
    }
    delete s;
    return 0;
}