#include <iostream>
#include <string>

using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string input;
        cin >> input;
        bool isTrue1 = true, isTrue2 = true;
        int i = 0, end = input.size()-1;
        while(i <= end && (isTrue1 || isTrue2))
        {
            isTrue1 = isTrue2 = false;
            if(i+1 <= end && input.substr(i,2) == "01")
            {
                isTrue1 = true;
                i += 2;
            }
            else if(i+3 <= end && input.substr(i,3) == "100")
            {
                i += 3;
                while(i <= end && input[i] == '0') ++i;
                if(i <= end && input[i] == '1')
                {
                    ++i;
                    isTrue2 = true;
                }
                while((i <= end && input[i] == '1') && !(i+3 <= end && input.substr(i,3) == "100")) ++i;
            }
        }
        cout << (i > end && (isTrue1 || isTrue2) ? "YES" : "NO") << '\n';
    }
    return 0;
}