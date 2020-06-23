#include <iostream>
#include <array>

using namespace std;
typedef struct 
{
    int begin;
    int end;
    int gap;
}rule;

array<rule, 10000> rules;
int main()
{
    int n, k, d;
    cin >> n >> k >> d;
    for(int i = 0; i < k; ++i) cin >> rules[i].begin >> rules[i].end >> rules[i].gap; 

    int low = 1, high = n;
    while(low <= high)
    {
        int mid = (low + high)/2;

        long long cnt = 0LL;
        for(int i = 0; i < k; ++i)
        {
            if(mid < rules[i].begin) continue;
            cnt += ((mid < rules[i].end ? mid : rules[i].end)-rules[i].begin)/rules[i].gap + 1;
        }
        if(cnt < d) low = mid + 1;
        else high = mid - 1;
    }
    cout << low << '\n';
    return 0;
}