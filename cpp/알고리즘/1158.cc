#include <iostream>
#include <queue>

using namespace std;
int main()
{
    int man, gap;
    cin >> man >> gap;
    queue<int> q, answer;
    for(int i = 1; i <= man; ++i) q.push(i);
    for(int i = 0; i < man; ++i)
    {
        for(int j = 0; j < gap-1; ++j)
        {
            q.push(q.front());
            q.pop();
        }
        answer.push(q.front());
        q.pop();
    }
    cout << '<';
    while(!answer.empty())
    {
        cout << answer.front() << (answer.size() == 1 ? ">" : ", ");
        answer.pop();
    }
    return 0;
}