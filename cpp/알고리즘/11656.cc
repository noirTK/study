#include <iostream>
#include <string>
#include <cstring>

using namespace std;
int main()
{
    string input;
    cin >> input;
    int len = input.length();
    int* rows = new int[len];
    for(int i = 0; i < len; ++i) rows[i] = i;

    for(int i = 0; i < len; ++i)
    {
        for(int j = 0; j < i; ++j)
        {
            if(strcmp(input.c_str()+rows[i],input.c_str()+rows[j]) < 0)
                swap(rows[i],rows[j]);
        }
    }
    for(int i = 0; i < len; ++i) cout << input.substr(rows[i]) << '\n';
    
    delete [] rows;
    return 0;
}