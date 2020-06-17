#include <iostream>
#include <string>
using namespace std;
int main()
{
    string input;
    while(getline(cin,input))
    {
        int count[4] = {0,0,0,0};
        for(char ch :input)
        {
            if(ch >= 'a' && ch <= 'z') ++count[0];
            else if(ch >= 'A' && ch <= 'Z') ++count[1];
            else if(ch >= '0' && ch <= '9') ++count[2];
            else if(ch == ' ') ++count[3];
        }
        for(int i=0;i<4;++i) cout<<count[i] << (i==3 ? '\n' : ' ');
    }
    return 0;
}