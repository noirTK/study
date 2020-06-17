#include <iostream>
#include <cstdio>
using namespace std;
int freq[26];
int main()
{
    char ch;
    while((ch = getchar())!='\n') ++freq[ch-'a'];
    for(int i = 0; i<26; ++i) cout << freq[i] << (i==25 ? '\n' : ' '); 
    return 0;
}