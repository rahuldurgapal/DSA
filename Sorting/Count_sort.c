#include<stdio.h>
void CountingSort(int [], int n, int [], int);
int main()
{   int a[] = {5,9,4,5,3,6,8,5,4,8,7,4,6,9,7};
    int b[15];
    int k=10;
    int n=15;
    int i;
    CountingSort(a,n,b,k);
    for(i=0;i<n;i++)
     printf("%d ",b[i]);
    return 0;
}

void CountingSort(int a[], int n, int b[], int k)
{
    int i,j,c[k];
    for(i=0;i<k;i++)
     c[i]=0;
    for(j=0;j<n;j++)
     c[a[j]]=c[a[j]]+1;
    for(i=1;i<k;i++)
     c[i]=c[i]+c[i-1];
    for(j=n-1;j>=0;j--)
     {
        b[c[a[j]]-1]=a[j];
        c[a[j]]=c[a[j]]-1;
     }
}