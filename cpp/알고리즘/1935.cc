#include <cstdio>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

double operate(const double& L, const double& R, const char& op)
{
    switch(op)
    {
        case '+':
            return L+R;
        case '-':
            return L-R;
        case '*':
            return L*R;
        case '/':
            return L/R; 
    }
}


int main()
{
    int times;
    cin >> times;
    cin.ignore();
    int oper[30];
    stack<double> s;
    string ex;
    getline(cin, ex);

    for(int i = 0; i < times; ++i)
    {
        int num;
        cin >> num;
        oper[i] = num;
    }
    
    for(const char ch : ex)
    {
        if(ch >= 'A' and ch <='Z')
        {
            s.push(oper[ch-'A']);
        }
        else
        {
            double Roperand = s.top();
            s.pop();
            double Loperand = s.top();
            s.pop();
            s.push(operate(Loperand,Roperand,ch));
        }
    }
    printf("%.2f\n",s.top());
    return 0;
}