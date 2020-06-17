#include <iostream>
#include <cstdio>

using namespace std;
int main()
{
    char ch;
    while((ch = getchar())!='\n')
    {
        if(!isdigit(ch) and ch != ' ') printf("%c", (ch>='a' and ch <= 'z') ? (ch-'a'+13)%26+'a' : (ch-'A'+13)%26+'A');
        else printf("%c",ch);
    }
    printf("%c",ch);
    return 0;
}