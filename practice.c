#include<stdio.h>
int main()
{
    int i,fact=1,n;
    printf("Enter the number\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
     fact =fact*i;

     printf("factorial of the number is %d",fact);
     return 0;
}