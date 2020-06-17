#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    stack<int>* s = new stack<int>;
    string input;
    int times;
    cin >> times;
    while(times--)
    {
        cin >> input;
        if(input == "push")
        {
            int item;
            cin >> item;
            s->push(item);
        }
        else if(input == "pop")
        {
            cout << (s->empty() ? -1 : s->top()) << '\n';
            if(!(s->empty())) s->pop();
        }
        else if(input == "size")
        {
            cout << s->size() << '\n';
        }
        else if(input == "empty")
        {
            cout << s->empty() << '\n';
        }
        else if(input == "top")
        {
            cout << (s->empty() ? -1 : s->top()) << '\n';
        }
    };
    return 0;
}