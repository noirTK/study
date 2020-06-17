#include <iostream>
#include <cstdio>

using namespace std;
int main()
{
    int index[26],i =0;
    fill_n(index,26,-1);
    char ch;
    while((ch=getchar())!='\n') index[ch-'a'] != -1 ? ++i : index[ch-'a'] = i++; 
    for(int i = 0; i < 26; ++i) cout << index[i] << (i==25 ?'\n':' ');
    return 0;
}