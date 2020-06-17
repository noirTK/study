#include <iostream>
#include <stack>

using namespace std;
int frequencyNum[1000001];
int main()
{
    int times;
    stack<int> s;
    cin >> times;
    int* nums = new int[times];
    int* answer = new int[times];
    fill_n(answer,times, -1);

    for(int i = 0; i < times; ++i)
    {
        int num;
        cin >> num;
        frequencyNum[num] += 1;
        nums[i] = num;
    }

    for(int i = 0; i < times; ++i)
    {
        if(!s.empty())
        {
            while(!s.empty() and frequencyNum[nums[s.top()]] < frequencyNum[nums[i]])
            {
                answer[s.top()] = nums[i];
                s.pop();
            }
        }
        s.push(i);
    }
    for(int i = 0; i < times; ++i)
    {
        cout << answer[i] << (i == times-1 ? '\n' : ' ');
    }

    delete[] nums;
    delete[] answer;
    return 0;
}