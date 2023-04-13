#include<stdio.h>
int min(int [],int , int );
int main()
{

   int a[]={24,11,67,8,19,45,55,32,41,27};
   int k,loc,temp;
   for(k=0;k<9;k++)
   {
    loc=min(a,k,10);
    if(a[k]>a[loc])
    {
        temp=a[k];
        a[k]=a[loc];
        a[loc]=temp;
    }
   }
   printf("After Soretd Array\n");
   for(k=0;k<10;k++)
    printf(" %d",a[k]);
    return 0;
}
int min(int a[],int k, int n)
{
    int min,loc,i;
    min=a[k];
    loc=k;

    for(i=k+1;i<n;i++)
    {
        if(min>a[i])
        {
            min=a[i];
            loc=i;
        }
    }
    return loc;
}