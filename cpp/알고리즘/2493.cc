#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int times;
    stack<int> s;
    cin >> times;
    int* nums = new int[times];
    int* answer = new int[times];
    fill_n(answer,times,0);

    for(int i = 0; i < times; ++i)
    {
        int num;
        cin >> num;
        nums[i] = num;
    }

    for(int i = times-1; i >= 0; --i)
    {
        if(!s.empty())
        {
            while(!s.empty() and nums[s.top()] < nums[i])
            {
                answer[s.top()] = i+1;
                s.pop();
            }
        }
        s.push(i);
    }
    
    for(int i = 0; i < times; ++i)
    {
        cout << answer[i] << (i==times-1 ? '\n' : ' ');
    }

    delete [] nums;
    delete [] answer;
    return 0;
}