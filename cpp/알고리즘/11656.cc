#include <iostream>
#include <string>

using namespace std;
int main()
{
    string input;
    cin >> input;
    int len = input.length();
    string* rows = new string[len];
    for(int i = 0; i < len; ++i)
    {
        rows[i] = input.substr(i,len-i);
    }

    for(int i = 0; i < len; ++i)
    {
        for(int j=0; j<i; ++j)
        {
            if(rows[i] < rows[j])
            {
                swap(rows[j],rows[i]);
            }
        }
    }
    for(int i = 0; i < len; ++i)
    {
        cout << rows[i] << '\n';
    }
    delete [] rows;
    return 0;
}