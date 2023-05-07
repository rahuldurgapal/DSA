#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
class infix_to_postfix{
    char stk[50];
    int top;
    public:
    void in_to_post(char infix[]);
    void push(char);
    char pop();

    infix_to_postfix()
    {
        top=-1;
    }
};
void infix_to_postfix::push(char symb)
{
    if(top>=49)
    {
        cout<<"Stack Overflow";
        exit(0);
    }
    else{
        top++;
        stk[top]=symb;
    }
}

char infix_to_postfix:: pop()
{
    char item;
    if(top==-1)
    {
        cout<<"stack empty";
        return(0);
    }
    else{
        item =stk[top];
        top--;
    }
    return item;
}

int preced(char ch)
{
    if(ch==47)
     return(5);
    else if(ch==42)
     return(4);
    else if(ch==43)
     return(3);
    else
     return(2);
}
void infix_to_postfix:: in_to_post(char infix[])
{
    int len;
    static int index=0,pos=0;
    char symbol,temp;
    char postfix[50];
    len=strlen(infix);
    push('#');

    while(index<len)
    {
        symbol=infix[index];
        switch(symbol)
        {
            case '(': push(symbol);
                      break;

            case ')': temp=pop();
            while(temp!='(')
            {
                postfix[pos]=temp;
                pos++;
                temp=pop();
            }
            break;

            case '+': 
            case '-':
            case '*':
            case '/':
            case '^':

            while(preced(stk[top])>=preced(symbol))
            {
                temp=pop();
                postfix[pos]=temp;
                pos++;
            }
            push(symbol);
            break;

            default:
               postfix[pos++]=symbol;
               break;
        }
        index++;
    }
    while(top>0)
    {
        temp=pop();
        postfix[pos++]=temp;
    }
    postfix[pos++]='\0';
    puts(postfix);
    return;
}
int main()
{
    infix_to_postfix s;
    char infx[40];
    cout<<"Enter the infix expression\n";
    cin>>infx;
    s.in_to_post(infx);
    return 0;
}