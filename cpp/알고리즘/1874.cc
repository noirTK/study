#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main()
{
    int times;
    stack<int> s;
    cin >> times;
    string answer;
    int num = 1;
    int su;

    bool check = true;
    while(times--)
    {
        cin >> su;
        if(su >= num)
        {
            while(num <= su)
            {
                s.push(num++);
                answer += '+';
            }
            s.pop();
            answer += '-';
        }
        else
        {
            if(s.top() != su) 
            {
                check = false;
            }
            else
            {
                s.pop();
                answer += '-';
            }
        }
    }
    if(s.empty() and check)
    {
        for(char c : answer)
        {
            cout << c << '\n';
        }
    }
    else
    {
        cout << "NO" << '\n';
    }
    return 0;
}