#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
int main()
{
    int times;
    cin >> times;
    cin.ignore();
    while(times--)
    {
        char c;
        bool flag = true;
        stack<int> s;
        while((c=getchar())!='\n')
        {
            if(c =='(') s.push(1);
            else 
            {
                if(s.empty()) flag = false;
                else s.pop();
            }
        }
        if(s.empty() and flag) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}