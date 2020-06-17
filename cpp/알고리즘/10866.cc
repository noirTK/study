#include <iostream>
#include <deque>
#include <string>

using namespace std;
int main()
{
    deque<int> dq;
    int times;
    cin >> times;
    while(times--)
    {
        string input;
        cin >> input;
        if(input == "push_front")
        {
            int num;
            cin >> num;
            dq.push_front(num);
        }
        else if(input == "push_back")
        {
            int num;
            cin >> num;
            dq.push_back(num);
        }
        else if(input == "pop_front")
        {
            cout << (dq.empty() ? -1 : dq.front()) << '\n';
            if(!dq.empty()) dq.pop_front();
        }
        else if(input == "pop_back")
        {
            cout << (dq.empty() ? -1 : dq.back()) << '\n';
            if(!dq.empty()) dq.pop_back();
        }
        else if(input == "size")
        {
            cout << dq.size() << '\n';
        }
        else if(input == "empty")
        {
            cout << dq.empty() << '\n';
        }
        else if(input == "front")
        {
            cout << (dq.empty() ? -1 : dq.front()) << '\n';
        }
        else if(input == "back")
        {
            cout << (dq.empty() ? -1 : dq.back()) << '\n';
        }
    }
    return 0;
}