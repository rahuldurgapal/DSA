#include<bits/stdc++.h>
using namespace std;
  char stk[20000];
    int top=-1;
    int r=0,big=0,temp=0,t=0;
void push(char s)
{
    
    if(top==-1)
    {
        top++;
        stk[top]=s;
    }
    else if(s==')' && stk[top]=='(')
    {
        r=r+2;
        t=t+2;
        top--;
        temp=top;
    }
    else if((stk[top]=='('  || stk[top]==')') && temp!=top)
    {
        top++;
        stk[top]=s;
            if(r>big)
            {
                big=r;
                r=0;
            }
    }
    else{
        top++;
        stk[top]=s;
    }
}
int main()
{
  
    string s;
    cout<<"Enter the input\n";
    cin>>s;
    int i;
    for(i=0;i<s.length();i++)
    push(s[i]);
    
    
    cout<<s.length()<<endl<<top<<endl;
    if(top>=-1)
     cout<<t;
    else if(r>=big)
     cout<<r;
    else
     cout<<big;

     cout<<endl<<r<<" "<<big<<" "<<t;
    return 0;
}
// )(((((()())()()))()(()))(