#include<stdio.h>
void insertion_sort(int [], int );
int main()
{
    int a[]={31,45,11,89,55,19,21,8,40,23};
    insertion_sort(a,10);
    printf("After Sorted Array is \n");
    for(int i=0;i<10;i++)
     printf(" %d",a[i]);
     
    return 0;
}
void insertion_sort(int a[], int n)
{
    int i=1,j,temp;
    for(i=1;i<n;i++)
    {
        temp=a[i];
        for(j=i-1;j>=0 && temp<a[j];j--)
          a[j+1]=a[j];

        a[j+1]=temp;
    }
}