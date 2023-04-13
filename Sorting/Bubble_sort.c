#include<stdio.h>
void bubble_sort(int [], int);
int main()
{
    int arr[]={34,11,4,56,78,9,15,29,8};
    int i;
    bubble_sort(arr,9);
    for(i=0;i<9;i++)
     printf(" %d",arr[i]);
    
   return 0;
}
void bubble_sort(int arr[], int n)
{
    int round,i,temp;
    for(round=1;round<n;round++)
    {
        for(i=0;i<n-round;i++)
        {
            if(arr[i]>arr[i+1])
            {
                temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
            }
        }
    }
}