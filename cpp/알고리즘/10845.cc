#include <iostream>
#include <queue>
#include <string>

using namespace std;
int main()
{
    queue<int> q;
    int times;
    cin >> times;
    while(times--)
    {
        string input;
        cin >> input;
        if(input == "push")
        {
            int num;
            cin >> num;
            q.push(num);
        }
        else if(input == "pop")
        {
            cout << (q.empty() ? -1 : q.front()) << '\n';
            if(!q.empty()) q.pop();
        }
        else if(input == "size")
        {
            cout << q.size() << '\n';
        }
        else if(input == "empty")
        {
            cout << (q.empty() ? 1 : 0) << '\n';
        }
        else if(input == "front")
        {
            cout << (q.empty() ? -1 : q.front()) << '\n';
        }
        else if(input == "back")
        {
            cout << (q.empty() ? -1 : q.back()) << '\n';
        }
    }
    return 0;
}