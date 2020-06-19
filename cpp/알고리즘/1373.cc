#include <iostream>
#include <string>

using namespace std;

int main()
{
    string input;
    cin >> input;
    int len = input.length();

    int decimal = 0;
    if(len%3 != 0)
    {
        for(int i = 0; i < len%3; ++i)
        {
            if(input[i] == '1') decimal += 1 << (len%3-i-1);
        }
        cout << decimal;
    }
    for(int i = len%3; i < len; i+=3)
    {
        int decimal = 0;
        string token = input.substr(i,3);
        int len = token.size();
        for(int j = 0; j < len; ++j)
        {
            if(token[j] == '1') decimal += 1 << (len-j-1);
        }
        cout << decimal;
    }
    cout << '\n';
    return 0;
}