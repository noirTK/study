#include <iostream>
#include <string>
#include <deque>

using namespace std;
int main()
{
    int times;
    cin >> times;
    while(times--)
    {
        deque<int> dq;
        string input;
        int len;
        cin >> input >> len;
        cin.ignore();
        string nums;
        getline(cin,nums);
        string ch;
        for(auto it = nums.begin(); it < nums.end(); ++it)
        {
            if(*it == '[') continue;
            else if(*it != ',' and *it != ']') ch.push_back(*it);
            else if(!ch.empty())
            {
                dq.push_back(stoi(ch));
                ch.clear();  
            }
        }
        bool isReverse = false;
        bool error = false;
        for(char command : input)
        {
            if(dq.empty() && command == 'D')
            {
                error = true;
                break;
            }
            if(command == 'R') isReverse = !isReverse;
            else
            {
                if(isReverse) dq.pop_back();
                else dq.pop_front();
            }
        }
        cout << (error ? "error\n" : "[");
        if(dq.empty() && !error) cout << "]\n";
        while(!dq.empty())
        {
            if(isReverse)
            {
                cout << dq.back() << (dq.size() == 1 ? "]\n" : "," );
                dq.pop_back();
            }
            else 
            {
                cout << dq.front() << (dq.size() == 1 ? "]\n" : "," );
                dq.pop_front();
            }
        }
    }
    return 0;
}