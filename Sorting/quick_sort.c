void quick(int arr[], int n, int beg, int end, int *loc)
{
    int left,right,temp;
    left=beg; right=end;
    *loc=beg;

    step2:
    while(arr[*loc]<=arr[right] && *loc!=right)
      right--;

    if(*loc==right)
     return ;
    if(arr[*loc]>arr[right])
    {
        temp=arr[*loc];
        arr[*loc]=arr[right];
        arr[right]=temp;

        *loc=right;
    }

    goto step3;

   step3:
     while(arr[left]<=arr[*loc] && left!=*loc)
      left++;

    if(*loc==left)
     return;
    if(arr[*loc]<arr[left])
    {
        temp=arr[*loc];
        arr[*loc]=arr[left];
        arr[left]=temp;

        *loc=left;
    }
   goto step2;
}

void quick_sort(int arr[], int n)
{
    int beg,end,loc,top=-1;
    int lower[10],upper[10];
    if(n>1)
    {
        top++;
        lower[top]=0;
        upper[top]=n-1;
    }
    while(top!=-1)
    {
        beg=lower[top];
        end=upper[top];
        top--;

        quick(arr,n,beg,end,&loc);

        if(beg<loc-1){
            top++;
            lower[top]=beg;
            upper[top]=loc-1;
        }

        if(loc+1<end)
        {
            top++;
            lower[top]=loc+1;
            upper[top]=end;
        }
    }
}

#include<stdio.h>
int main()
{
    int arr[]={44,33,11,55,77,90,40,60,99,22,86,66};
    quick_sort(arr,12);
    for(int i=0;i<12;i++)
     printf("%d ",arr[i]);

    return 0;
}