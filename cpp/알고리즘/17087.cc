#include <iostream>
#include <queue>
using namespace std;
int gcd(const int& l, const int& r)
{
    if(r == 0) return l;
    else return gcd(r,l%r);
}
int main()
{
    long int t, s;
    cin >> t >> s;
    queue<int> dis;

    for(long int i = 0; i < t; ++i)
    {
        int num;
        cin >> num;
        dis.push((num<=s ? s-num : num-s));
    }
    
    while(dis.size()!=1)
    {
        int r = dis.front();
        dis.pop();
        int l = dis.front();
        dis.pop();
        dis.push(gcd(r,l));
    }
    cout << dis.front() << '\n';
    return 0;
}